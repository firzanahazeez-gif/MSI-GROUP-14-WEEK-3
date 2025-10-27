Update Python code:                                                                                                                                                                               import serial
import time
ser = serial.Serial('COM8', 9600)
try:
while True:
angle = input("Enter servo angle
(0-180 degrees) or 's' to stop: ")
if angle.lower() == 's':
ser.write(b's') # Send 's' to stop
the servo
break
angle = int(angle)
if 0 <= angle <= 180:
ser.write(str(angle).encode()) #
Send the servo's angle to the Arduino
else:
print("Angle must be between 0
and 180 degrees.")
except KeyboardInterrupt:
pass # Handle keyboard interrupt
finally:
ser.close() # Close the serial connection
print("Serial connection closed.")
