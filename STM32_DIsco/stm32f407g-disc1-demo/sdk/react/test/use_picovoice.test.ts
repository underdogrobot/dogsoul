import { renderHook } from '@testing-library/react-hooks/dom';

import { usePicovoice } from '../src';

// @ts-ignore
import porcupineParams from '@/porcupine/porcupine_params.js';
// @ts-ignore
import rhinoParams from '@/rhino/rhino_params.js';
// @ts-ignore
import picovoiceWakeWord from '@/keyword_files/picovoice_wasm.js';
// @ts-ignore
import coffeeMakerContext from '@/contexts/coffee_maker_wasm.js';

import testData from './test_data.json';

const ACCESS_KEY = Cypress.env('ACCESS_KEY');

describe('Picovoice SDK', () => {
  it('should be able to init via public path', () => {
    const { result } = renderHook(() => usePicovoice());

    cy.wrapHook(
      () => result.current.init(
        ACCESS_KEY,
        { label: 'picovoice', publicPath: "/test/keyword_files/picovoice_wasm.ppn", forceWrite: true },
        { publicPath: "/test/porcupine/porcupine_params.pv", forceWrite: true },
        { publicPath: "/test/contexts/coffee_maker_wasm.rhn", forceWrite: true },
        { publicPath: "/test/rhino/rhino_params.pv", forceWrite: true }
      )
    ).then(() => {
      expect(result.current.isLoaded).to.be.true;
    });

    cy.wrapHook(
      result.current.release
    ).then(() => {
      expect(result.current.isLoaded).to.be.false;
    });
  });

  it('should be able to init via base64', () => {
    const { result } = renderHook(() => usePicovoice());

    cy.wrapHook(
      () => result.current.init(
        ACCESS_KEY,
        { label: 'picovoice', base64: picovoiceWakeWord, forceWrite: true },
        { base64: porcupineParams, forceWrite: true },
        { base64: coffeeMakerContext, forceWrite: true },
        { base64: rhinoParams, forceWrite: true }
      )
    ).then(() => {
      expect(result.current.isLoaded).to.be.true;
    });
  });

  it('should show invalid model path error message', () => {
    const { result } = renderHook(() => usePicovoice());

    cy.wrapHook(
      () => result.current.init(
        ACCESS_KEY,
        { label: 'picovoice', publicPath: "/test/keyword_files/picovoice_wasm.ppn", forceWrite: true },
        { publicPath: "/test/porcupine/porcupine_params_failed.pv", forceWrite: true },
        { publicPath: "/test/contexts/coffee_maker_wasm.rhn", forceWrite: true },
        { publicPath: "/test/rhino/rhino_params.pv", forceWrite: true }
      )
    ).then(() => {
      expect(result.current.isLoaded).to.be.false;
      expect(result.current.error?.toString()).to.contain("Error response returned while fetching model from '/test/porcupine/porcupine_params_failed.pv'");
    });
  });

  it('should show invalid access key error message', () => {
    const { result } = renderHook(() => usePicovoice());

    cy.wrapHook(
      () => result.current.init(
        '',
        { label: 'picovoice', publicPath: "/test/keyword_files/picovoice_wasm.ppn", forceWrite: true },
        { publicPath: "/test/porcupine/porcupine_params.pv", forceWrite: true },
        { publicPath: "/test/contexts/coffee_maker_wasm.rhn", forceWrite: true },
        { publicPath: "/test/rhino/rhino_params.pv", forceWrite: true }
      )
    ).then(() => {
      expect(result.current.isLoaded).to.be.false;
      expect(result.current.error?.toString()).to.contain("Invalid AccessKey");
    });
  });

  for (const testInfo of testData.tests.parameters) {
    it(`should be able to process audio (${testInfo.language})`, () => {
      const { result } = renderHook(() => usePicovoice());

      cy.wrapHook(
        () => result.current.init(
          ACCESS_KEY,
          { label: testInfo.wakeword, publicPath: `/test/keyword_files/${testInfo.wakeword}_wasm.ppn`, forceWrite: true },
          { publicPath: `/test/porcupine/porcupine_params${testInfo.language === 'en' ? '' : '_' + testInfo.language}.pv`, forceWrite: true },
          { publicPath: `/test/contexts/${testInfo.context_name}_wasm.rhn`, forceWrite: true },
          { publicPath: `/test/rhino/rhino_params${testInfo.language === 'en' ? '' : '_' + testInfo.language}.pv`, forceWrite: true }
        )
      ).then(() => {
        expect(result.current.isLoaded).to.be.true;
      });

      cy.wrapHook(
        result.current.start
      ).then(() => {
        expect(result.current.isListening).to.be.true;
      });

      cy.mockRecording(
        `audio_samples/${testInfo.audio_file}`
      ).then(() => {
        expect(result.current.inference?.intent).to.eq(testInfo.inference.intent);
        expect(result.current.inference?.slots).to.deep.eq(testInfo.inference.slots);
      });

      cy.wrapHook(
        () => result.current.stop()
      ).then(() => {
        expect(result.current.isListening).to.be.false;
      });
    });
  }
});
