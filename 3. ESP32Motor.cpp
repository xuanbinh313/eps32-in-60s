// Defined connect between ESP32 and DRV8833
#define IN1 32
#define IN2 33

void setup() {
// Mapping init OUTPUT
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
}

void loop() {
// Go Forward (IN1 HIGH, IN2 LOW)
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
delay(2000); // Spin in 2s

// Go back (IN1 LOW, IN2 HIGH)
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
delay(2000); // Spin in 2s

// Stop (IN1 LOW, IN2 LOW)
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
delay(2000); // Spin in 2s
}
