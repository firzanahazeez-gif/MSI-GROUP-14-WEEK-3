Updated Arduino code :  
#include <Servo.h>
Servo myservo; // Create a servo object
int potPin = A0; // Analog pin for
potentiometer
int val; // Potentiometer value
int servoPos = 90; // Initial servo
position
boolean haltFlag = false; // Flag to
indicate if servo should be halted
void setup() {
myservo.attach(9); // Attach the servo
to pin 9
Serial.begin(9600); // Initialize serial
communication
}
void loop() {
if (!haltFlag) { // Check if the servo
should not be halted
val = analogRead(potPin);                                                                                                                                                                                 // Read potentiometer value
servoPos = map(val, 0, 1023, 0, 180);
// Map potentiometer value to servo
angle
myservo.write(servoPos); // Set the
servo position
}
if (Serial.available() > 0) {
char key = Serial.read(); // Read a
character from serial input
if (key == 's') { // Check if 's' character
is received
haltFlag = !haltFlag; // Toggle the
haltFlag
if (haltFlag) {
myservo.write(90); // Halt the servo
at a specific position (90 degrees)
Serial.println("Servo halted.");
} else {
Serial.println("Servo resumed.");
}
}
}
}