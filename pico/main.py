import machine
import time

# Set up UART1 with the appropriate baud rate and pins.
uart1 = machine.UART(1, baudrate=9600, tx=machine.Pin(4), rx=machine.Pin(5))

def read_char_from_uart(uart):
    while not uart.any():
        pass
    return uart.read(1)

def write_char_to_uart(uart, char):
    uart.write(char)

while True:
    try:
        # Read a character from UART1
        received_char = read_char_from_uart(uart1)
        print("Received character:", received_char.decode('utf-8'))

        # Modify the received character (e.g., increment it)
        modified_char = chr(ord(received_char) + 1)

        # Write the modified character back to UART1
        write_char_to_uart(uart1, modified_char.encode('utf-8'))

        # Wait a bit to avoid flooding the UART
        time.sleep_ms(100)

    except Exception as e:
        print("Error:", e)

