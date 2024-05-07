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

void thread_blinkred() {
  t_current = millis();
  if (t_current - t_red > 1000) {
    digitalWrite(LED_RED, !digitalRead(LED_RED));
    t_red = t_current;
  }
}

void thread_blinkblue() {
  t_current = millis();
  if (t_current - t_blue > 250) {
    digitalWrite(LED_BLUE, !digitalRead(LED_BLUE));
    t_blue = t_current;
  }
}

bool threads_array[3];

void thread_setnext() {
  for (int i = 0; i < threads_array.size(); ++i) {
    if (threads_array[i] == true) {
      threads_array[i] = false; // Mark current thread as false
      int next_index = (i + 1) % threads_array.size(); // Calculate index of next thread
      threads_array[next_index] = true; // Mark next thread as true
      break; // Break out of loop after updating one thread
    }
  }
}

void isrhandler_button() {
  thread_setnext();
}

void loop() {

}
