#include <Arduino.h>

void logger_init(void) {
  Serial.begin(115200);
  Serial.print("\r");
}

void log(const char* msg) {
  Serial.println(msg);
}

void log(String msg) {
  Serial.println(msg);
}

void log(const char* msg, const char* arg) {
  Serial.print(msg);
  Serial.println(arg);
}

void log(const char* msg, int arg) {
  Serial.print(msg);
  Serial.println(arg);
}
