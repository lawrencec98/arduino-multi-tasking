#define LED_GREEN   4
#define LED_BLUE    5
#define LED_RED     6
#define BUTTON      7

unsigned long t_red = millis();
unsigned long t_blue = millis();
unsigned long t_current;

void setup() {
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  
  t_current = millis();
  if (t_current - t_red > 1000) {
    digitalWrite(LED_RED, !digitalRead(LED_RED));
    t_red = t_current;
  }

  t_current = millis();
  if (t_current - t_blue > 250) {
    digitalWrite(LED_BLUE, !digitalRead(LED_BLUE));
    t_blue = t_current;
  }

  if (digitalRead(BUTTON) == HIGH) {
    digitalWrite(LED_GREEN, HIGH);
  } else {
    digitalWrite(LED_GREEN, LOW);
  }
}
