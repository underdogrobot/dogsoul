import machine
from machine import PWM, Pin
from time import sleep

center = 5500 #range for servo is: 1100 - 8300
# The range of the drawbot is more constrained.
#left_front_arm: left_shoulder:LS, left_elbow: LE
LS = PWM(Pin(10))
LS.freq(50)
LE = PWM(Pin(11))
LE.freq(50)
#right_front_leg: right_shoulder:RS, right_elbow: RE
RS = PWM(Pin(14))
RS.freq(50)
RE = PWM(Pin(15))
RE.freq(50)
#left_back_leg: left_hip: LH, right_knee: LK
LH = PWM(Pin(16))
LH.freq(50)
LK = PWM(Pin(17))
LK.freq(50)
#right_back_leg: right_hip: RH, right_knee: RK
RH = PWM(Pin(18))
RH.freq(50)
RK = PWM(Pin(19))
RK.freq(50)

#DC MOTORS
#-----------------------------------
#right motor
B1A = machine.Pin(8, machine.Pin.OUT)
B1B = machine.Pin(9, machine.Pin.OUT)
#left motor
A1A = machine.Pin(12, machine.Pin.OUT)
A1B = machine.Pin(13, machine.Pin.OUT)

def test_servo(svr):
    print("testing servo now: ")
    """ TYPE: test_servo(svr)
        svr = servo pin you want to test and set to 5500ms
        """
    s = PWM(Pin(svr))
    s.freq(50)
    s.duty_u16(5500) #midpoint

#These definitions/functions are hard-coded positions
#svrL = RS(GP14), svrR = RE(GP15)
def leg_center_up(svrL,svrR):
    svrL.duty_u16(6400)
    svrR.duty_u16(4500)

def leg_forward_up(svrL,svrR):
    svrL.duty_u16(8200)
    svrR.duty_u16(6700)
    
def leg_forward_down(svrL,svrR):
    svrL.duty_u16(6800)
    svrR.duty_u16(6700)
    
def leg_back_down(svrL,svrR):
    svrL.duty_u16(4200)
    svrR.duty_u16(3900)

def leg_back_up(svrL,svrR):
    svrL.duty_u16(4200)
    svrR.duty_u16(2200)

#DC MOTORS for move efficent motion
#left motor
def motorA():
    A1A.value(0)
    A1B.value(0)
#right motor
def motorB():
    B1A.value(0)
    B1B.value(0)
    
legcycle = .5

leg_center_up(RE,RS)
sleep(legcycle)
leg_forward_up(RE,RS)
sleep(legcycle)
leg_forward_down(RE,RS)
sleep(legcycle)
leg_back_down(RE,RS)
sleep(legcycle)
leg_back_up(RE,RS)
sleep(legcycle)
leg_center_up(RE,RS)
sleep(legcycle)
"""
paw_down_front()
sleep(legcycle)

paw_walk_fwd()
sleep(legcycle)

paw_up_center()
sleep(legcycle)
sleep(1)
"""
