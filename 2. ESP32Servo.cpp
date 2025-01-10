#include <ESP32Servo.h>

// Define the servo object
Servo myServo;

// Define the pin to control the servo
int servoPin = 18;

void setup() {
// Attach the servo to the specified pin
myServo.attach(servoPin);
Serial.begin(115200);
}

void loop() {
// Move servo to 0 degrees
myServo.write(0);
Serial.println("Servo at 0 degrees");
delay(1000);

// Move servo to 90 degrees
myServo.write(90);
Serial.println("Servo at 90 degrees");
delay(1000);

// Move servo to 180 degrees
myServo.write(180);
Serial.println("Servo at 180 degrees");
delay(1000);
}
