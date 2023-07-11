from machine import UART,Pin
import utime

TX_PIN=16 # physical pin 21
RX_PIN=17 # physical pin 22
UART_NUM = 0 # Since pins 21 and 22 are part of the UART0
BAUDRATE=9600
PARITY_BITS=None
BITS=8
STOP=1



uart = UART(UART_NUM,baudrate=BAUDRATE, tx=Pin(TX_PIN), rx=Pin(RX_PIN), bits=BITS, parity=PARITY_BITS, stop=STOP)
val = uart.write(b"hello\r\n") # write some dummy text with a CRLF ends
uart.flush() #required to ensure the write is finished
rcvChar = uart.readline()# read the line (reads until it finds a valid line ending, in this case CRLF)
print(rcvChar) # print the recieved info.
