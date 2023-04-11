# dancing dog
import time
import board
import pwmio
from adafruit_motor import servo

# create a PWMOut object on Pin A2.
# front left
pwm1 = pwmio.PWMOut(board.PA01, duty_cycle=2 ** 15, frequency=50)
# front right - working
pwm2 = pwmio.PWMOut(board.PA00, duty_cycle=2 ** 15, frequency=50)

# back left
pwm3 = pwmio.PWMOut(board.PA03, duty_cycle=2 ** 15, frequency=50)
# back right - working
pwm4 = pwmio.PWMOut(board.PB01, duty_cycle=2 ** 15, frequency=50)

# Create a servo object, my_servo.
my_servo1 = servo.Servo(pwm1)
my_servo2 = servo.Servo(pwm2)
my_servo3 = servo.Servo(pwm3)
my_servo4 = servo.Servo(pwm4)

delay = 0.01
while True:
    for angle in range(0, 180, 5):  # 0 - 180 degrees, 5 degrees at a time.
        my_servo1.angle = angle
        time.sleep(delay)
        my_servo2.angle = angle
        time.sleep(delay)
        my_servo3.angle = angle
        time.sleep(delay)
        my_servo4.angle = angle
        time.sleep(delay)
    for angle in range(180, 0, -5): # 180 - 0 degrees, 5 degrees at a time.
        my_servo1.angle = angle #FL
        time.sleep(delay)
        my_servo2.angle = angle #FR
        time.sleep(delay)
        my_servo3.angle = angle
        time.sleep(delay)
        my_servo4.angle = angle
        time.sleep(delay)
    print("hi")
# notes: 
# use correct pins
# use ground to reduce noise
# need to change screw of one front leg
