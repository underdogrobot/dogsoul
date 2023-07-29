# This is a newer program that can dance, walk and stand based on the mpr121 pins
import time
import board
import pwmio
from adafruit_motor import servo
import busio
import adafruit_mpr121

#i2c = busio.I2C(board.SCL, board.SDA)
i2c = busio.I2C(board.PA08, board.PC09)
mpr121 = adafruit_mpr121.MPR121(i2c)



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

def dance():
    while True:
# Use touched_pins to get current state of all pins.
        touched = mpr121.touched_pins
# Test if 2 is touched. Stop motion if not touched
        if not touched[2]:
            break
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
        print("dancing")

def stand():
    my_servo1.angle = 90
    my_servo2.angle = 90
    my_servo3.angle = 90
    my_servo4.angle = 90
    
def bow():
# when pin 8 touched, bow
    for angle in range(0, 90, 3):  # 0 - 180 degrees, 5 degrees at a time.
        my_servo1.angle = 90 - angle
        time.sleep(delay)
        my_servo2.angle = 90 + angle
        time.sleep(delay)
        my_servo3.angle = 90
        time.sleep(delay)
        my_servo4.angle = 90
        time.sleep(delay)
        print("bowing")

def walk():
    while True:
# when pin 6 touched, walk
# Use touched_pins to get current state of all pins.
        touched = mpr121.touched_pins
# Test if 6 is touched.
        if not touched[6]:
            break
        for angle in range(0, 90, 3):  # 0 - 180 degrees, 5 degrees at a time.
            my_servo1.angle = 90 - angle
            time.sleep(delay)
            my_servo2.angle = 90 + (90 - angle)
            time.sleep(delay)
            my_servo3.angle = 90
            time.sleep(delay)
            my_servo4.angle = 90
            time.sleep(delay)
            print("walking")

stand()
stopRobot = False

while stopRobot == False:    
    for i in range(12):      
        if mpr121[i].value == True:
            if i == 2:
                dance()
            elif i == 4:
                stand()
            elif i == 6:
                walk()
            elif i == 8:
                bow()
            else:
# stop the while loop
                stopRobot = True 
                break




