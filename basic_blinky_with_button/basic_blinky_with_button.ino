#define LED_GREEN   4
#define LED_BLUE    5
#define LED_RED     6
#define BUTTON      7

unsigned long t_red;
unsigned long t_blue;

void setup() {
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  digitalWrite(LED_RED, HIGH);
  delay(1000);
  digitalWrite(LED_RED, LOW);
  delay(1000);

  digitalWrite(LED_BLUE, HIGH);
  delay(250);
  digitalWrite(LED_BLUE, LOW);
  delay(250);

  if (digitalRead(BUTTON) == HIGH) {
    digitalWrite(LED_GREEN, HIGH);
  } else {
    digitalWrite(LED_GREEN, LOW);
  }
}
