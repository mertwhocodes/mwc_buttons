#include <Arduino.h>
#include "AVR_button.h"

AVR_button my_button(7);

void my_button_pressedCallback(void *ptr);
void my_button_releasedCallback(void *ptr);

void setup() {
  Serial.begin(9600);// put your setup code here, to run once:
 Serial.println("Serial active");
  my_button.setMode(buttonMode::Pulldown);
  my_button.setState(buttonState::NonState);
  my_button.setPressedTask(my_button_pressedCallback);
 my_button.setReleassedTask(my_button_releasedCallback);
}  

void loop() {
  
 AVR_button::updateButton();
  // put your main code here, to run repeatedly:

} 
void my_button_pressedCallback(void *ptr)
{
  Serial.println("button_pressed_callback");
}
void my_button_releasedCallback(void *ptr)
{
  Serial.println("button_released_callback");
}