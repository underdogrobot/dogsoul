#MICROPYTHON code to test servo

from machine import PWM, Pin
from time import sleep

s = PWM(Pin(test_servo_pin))
s.freq(50)
servo_range = range(1100,8200)

for sweep in servo_range:
    s.duty_u16(sweep)
    sleep(.1)
    
