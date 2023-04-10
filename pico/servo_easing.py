import time, random, board
from pwmio import PWMOut
from adafruit_motor import servo

animation = (
    (0,1.3),
    (180, 1.3)
)

servoA = servo.Servo(PWMOut(board.GP6, frequency=50), min_pulse=500, max_pulse=2250)
servoA.angle = 0 #starting position
time.sleep(2)
servoA.angle = 180
time.sleep(2)
servoA.angle = 90

ani_pos = 0
ease_speed = 0.1
num_ease_slices = 50
while True:
    new_angle, secs = animation[ ani_pos ]
    print("new position:", new_angle, secs)
    for i in range(num_ease_slices):
        servoA.angle += (new_angle - servoA.angle) * ease_speed
        print((new_angle - servoA.angle) * ease_speed)
        time.sleep( secs / num_ease_slices )
    print("got there")
    time.sleep(2)
    ani_pos = (ani_pos + 1) % len(animation) #go to next loop if at end.
    
    

