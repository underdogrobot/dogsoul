#PICO
import machine
import board
import digitalio
import time

def flash_circuit_python():
    led = digitalio.DigitalInOut(board.GP25)
    led.direction = digitalio.Direction.OUTPUT
    for i in range(5):
        led.value = True
        time.sleep(0.5)
        led.value = False
        time.sleep(0.5)
        
def flash_micro_python():
    led = machine.Pin(25,machine.Pin.OUT)
    for i in range(5):
        led.value = True
        time.sleep(0.5)
        led.value = False
        time.sleep(0.5)
        
while True:
    flash_circuit_python()
    flash_micro_python()