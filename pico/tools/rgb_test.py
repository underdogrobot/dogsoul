import time
import board
import neopixel

pixel_pin = board.A1
num_pixels = 2

pixels = neopixel.NeoPixel(pixel_pin, num_pixels, brightness=0.3, auto_write=False)

RED = (255, 0, 0)
YELLOW = (255, 150, 0)
GREEN = (0, 255, 0)
CYAN = (0, 255, 255)
BLUE = (0, 0, 255)
PURPLE = (180, 0, 255)

while True:
    pixels.fill(BLUE)
    pixels.show()
    time.sleep(1)
    pixels.fill(GREEN)
    pixels.show()
    time.sleep(1)
    
