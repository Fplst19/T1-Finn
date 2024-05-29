#define TRIGGER_PIN 12    // Pin für Trigger des HC-SR04
#define ECHO_PIN 13       // Pin für Echo des HC-SR04

// RGB-LED 1 Pins
#define LED1_R_PIN 2
#define LED1_G_PIN 4
#define LED1_B_PIN 5

// RGB-LED 2 Pins
#define LED2_R_PIN 16
#define LED2_G_PIN 17
#define LED2_B_PIN 18

void setup() {
  // Initialisiere serielle Kommunikation
  Serial.begin(115200);

  // Initialisiere HC-SR04 Pins
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Initialisiere RGB-LED-Pins
  pinMode(LED1_R_PIN, OUTPUT);
  pinMode(LED1_G_PIN, OUTPUT);
  pinMode(LED1_B_PIN, OUTPUT);

  pinMode(LED2_R_PIN, OUTPUT);
  pinMode(LED2_G_PIN, OUTPUT);
  pinMode(LED2_B_PIN, OUTPUT);
}

void loop() {
  // Entfernung messen
  long duration, distance;
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1; // Abstand in cm berechnen

  // Bedingung für LED-Farbe
  if (distance < 20) {
    // LEDs auf gelb setzen
    setColor(255, 255, 0); // Gelb
  } else {
    // LEDs auf weiß setzen
    setColor(255, 255, 255); // Weiß
  }

  // Kurze Pause
  delay(100);
}

// Funktion zum Setzen der LED-Farbe
void setColor(int red, int green, int blue) {
  analogWrite(LED1_R_PIN, red);
  analogWrite(LED1_G_PIN, green);
  analogWrite(LED1_B_PIN, blue);

  analogWrite(LED2_R_PIN, red);
  analogWrite(LED2_G_PIN, green);
  analogWrite(LED2_B_PIN, blue);
}
