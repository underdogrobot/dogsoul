# SPDX-FileCopyrightText: 2021 ladyada for Adafruit Industries
# SPDX-License-Identifier: MIT

import time
import board
import busio
import adafruit_lis3dh

i2c = busio.I2C(board.GP1, board.GP0)    # Pi Pico RP2040
    # i2c = board.STEMMA_I2C()  # For using the built-in STEMMA QT connector on a microcontroller
lis3dh = adafruit_lis3dh.LIS3DH_I2C(i2c)
# Set range of accelerometer (can be RANGE_2_G, RANGE_4_G, RANGE_8_G or RANGE_16_G).
lis3dh.range = adafruit_lis3dh.RANGE_2_G

# Loop forever printing accelerometer values
while not i2c.try_lock():
    pass
try:
    while True:
        # Read accelerometer values (in m / s ^ 2).  Returns a 3-tuple of x, y,
        # z axis values.  Divide them by 9.806 to convert to Gs.
        x, y, z = [
            value / adafruit_lis3dh.STANDARD_GRAVITY for value in lis3dh.acceleration
        ]
        print("x = %0.3f G, y = %0.3f G, z = %0.3f G" % (x, y, z))
        # Small delay to keep things responsive but give time for interrupt processing.
        time.sleep(0.1)
finally:
    i2c.unlock()
    