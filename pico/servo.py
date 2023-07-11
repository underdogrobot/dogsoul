# The following code is under public domain, feel free to use this how you will.

from machine import PWM, Pin
import utime
from math import cos, sin, radians, sqrt, atan, degrees, acos
left = PWM(Pin(14))
left.freq(50)
right = PWM(Pin(15))
right.freq(50)
MIN_DUTY = 1128
MAX_DUTY = 8559

DUTY_PER_DEG = (MAX_DUTY - MIN_DUTY) / 180
class Vector:
    def __init__(self, x,y):
        self.x = x
        self.y = y
    def add_to(self, other):
        self.x += other.x
        self.y += other.y
    def add(rhs, lhs):
        return Vector(rhs.x + lhs.x, rhs.y + lhs.y)
    def sub_from(self, other):
        self.x -= other.x
        self.y -= other.y
    def sub(rhs, lhs):
        print(rhs.x)
        return Vector(rhs.x - lhs.x, rhs.y - lhs.y)
    def from_polar(length, angle):
        return Vector(cos(radians(angle)) * length, sin(radians(angle)) * length)
    def magnitude(self):
        return sqrt(self.x**2 + self.y ** 2)
    def angle(self):
        return degrees(atan(self.y/self.x))
    def display(self):
        print("x: ", self.x, ", y:", self.y)
    def __str__(self):
        return f"x: {self.x}, y:{self.y}"

L1 = 2
L2 = 2.125
L4 = 1.28
L5 = 1.81
L6 = 1.33

DISTANCE_BETWEEN = Vector.from_polar(1.45, 180)
def end_position(angle_1, angle_2):
    pos_1 = Vector.from_polar(L1, angle_1)
    pos_2 = Vector.from_polar(L2, angle_2)
    pos_2.add_to(DISTANCE_BETWEEN)
    L3 = Vector.sub(pos_1, pos_2)
    L3.display()
    angle_6 = L3.angle()
    print(angle_6)
    angle_5 = degrees(acos((L3.magnitude()**2 + L5**2 - L4**2) / (2 * L3.magnitude() * L5)))
    print(angle_5)
    out = Vector.from_polar(L6 + L5, angle_6 + angle_5)
    print(out)
    out.add_to(pos_2)
    return out
def degree_from_duty(degree):
    return int(DUTY_PER_DEG * degree + MIN_DUTY)
left.duty_u16(degree_from_duty((90)))
right.duty_u16(degree_from_duty(85))

print(end_position(90, 90))

#NEXT:
"""
Work on collision avoidance with self, you have some neato code up there to help you out.

bring a ruler

"""
