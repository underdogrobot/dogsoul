from machine import UART,Pin
import utime

TX_PIN=4 # physical pin 21
RX_PIN=5 # physical pin 22
UART_NUM = 1 # Since pins 21 and 22 are part of the UART0
BAUDRATE=9600
PARITY_BITS=None
BITS=8
STOP=1

uart = UART(UART_NUM,baudrate=BAUDRATE, tx=Pin(TX_PIN), rx=Pin(RX_PIN))
uart.init(bits=BITS, parity=PARITY_BITS, stop=STOP)
data = ""
while True:
    #uart.write(b"hello\r\n")    # write some dummy text with a CRLF ends
    #uart.flush()                # required to ensure the write is finished
    if uart.any():
        data = uart.read()
        #print(data)
        # print the recieved info.
        #uart.write(data)
        if data == b'w':
            print('w')
            uart.write(data)
            #pass
        elif data == b's':
            print('s')
            uart.write("s")
            #pass
        elif data == b'd':
            print('d')
            uart.write("d")
            #pass
        else:
            pass
    utime.sleep(1)
