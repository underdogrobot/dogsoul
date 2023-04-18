import time
import board
import pwmio
from adafruit_motor import servo

pwm = pwmio.PWMOut(board.GP6, duty_cycle=2 ** 15, frequency=50)
my_servo = servo.Servo(pwm, min_pulse = 500, max_pulse=2600)
accel = .05
step = 4
while True:
    for angle in range(0, 180, step):  # 0 - 180 degrees, 5 degrees at a time.
        my_servo.angle = angle
        time.sleep(accel)
    for angle in range(180, 0, -step): # 180 - 0 degrees, 5 degrees at a time.
        my_servo.angle = angle
        time.sleep(accel)