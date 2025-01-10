#include <Arduino.h>

// HC-SR04
#define trigPin 19  // Chân Trig of HC-SR04
#define echoPin 18  // Chân Echo of HC-SR04

// Defined connect between ESP32 and DRV8833
#define IN1 32  // PWM
#define IN2 33  // Control direction motor

// Channel và resolution for PWM of motor
#define MOTOR_PWM_FREQ 1000
#define MOTOR_PWM_RESOLUTION 8
#define MOTOR_PWM_CHANNEL 1

long duration;
int distance;   
int motorSpeed = 0;  // Init speed motor

void setup() {
  // Setup HC-SR04
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Setup DRV8833 and motor
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // Khởi tạo PWM cho động cơ
  ledcSetup(MOTOR_PWM_CHANNEL, MOTOR_PWM_FREQ, MOTOR_PWM_RESOLUTION);
  ledcAttachPin(IN1, MOTOR_PWM_CHANNEL);
  // Turn on log monitor Serial Monitor
  Serial.begin(115200);
}

void loop() {
  // Generate signal pulse Trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Calculate time Echo
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // Calculate distance (cm)

  // Speed change depend distance
  if (distance > 20) {
    motorSpeed = 0;  // Stop
  } else if (distance <= 5) {
    motorSpeed = 255;  // Max speed
  } else {
    motorSpeed = map(distance, 20, 5, 0, 255);  
  }

  // Control motor logic
  if (motorSpeed > 0) {
    digitalWrite(IN2, LOW);  // Go forward
    ledcWrite(MOTOR_PWM_CHANNEL, motorSpeed);
  } else {
    digitalWrite(IN2, LOW);  // Stop
    ledcWrite(MOTOR_PWM_CHANNEL, 0);
  }

  // Debug
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Motor Speed: ");
  Serial.println(motorSpeed);

  delay(100);
}
