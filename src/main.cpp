#include <Arduino.h>
#include "button.h"
Button my_button;
void setup() {
  Serial.begin(9600);// put your setup code here, to run once:
}

void loop() {
  Serial.println(my_button.getButtonCounter());
  // put your main code here, to run repeatedly:
} 