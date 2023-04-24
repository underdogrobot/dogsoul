import time
import board
import pwmio
from digitalio import DigitalInOut, Direction, Pull
from adafruit_motor import servo

left_shoulder = pwmio.PWMOut(board.GP2, duty_cycle=2 ** 15, frequency=50)
LS2 = servo.Servo(left_shoulder, min_pulse = 500, max_pulse=2600)
right_shoulder = pwmio.PWMOut(board.GP4, duty_cycle=2 ** 15, frequency=50)
RS4 = servo.Servo(right_shoulder, min_pulse = 500, max_pulse=2600)

left_hip = pwmio.PWMOut(board.GP6, duty_cycle=2 ** 15, frequency=50)
LH6 = servo.Servo(left_hip, min_pulse = 500, max_pulse=2600)
right_hip = pwmio.PWMOut(board.GP8, duty_cycle=2 ** 15, frequency=50)
RH8 = servo.Servo(right_hip, min_pulse = 500, max_pulse=2600)


accel = .05
step = 4

def silly_walks():
    for angle in range(0, 180, step):  # 0 - 180 degrees, 5 degrees at a time.
        RH8.angle = angle
        LH6.angle = angle
        time.sleep(accel)
    for angle in range(180, 0, -step): # 180 - 0 degrees, 5 degrees at a time.
        RH8.angle = angle
        LH6.angle = angle
        time.sleep(accel)
        
def stand():
    LS2.angle = 90
    RS4.angle = 90
    LH6.angle = 90
    RH8.angle = 90

def sit():
    LS2.angle = 20
    RS4.angle = 20
    LH6.angle = 20
    RH8.angle = 20

    
stand()
sit()
time.sleep(5)
stand()
time.sleep(1)
sit()
time.sleep(5)
stand()


