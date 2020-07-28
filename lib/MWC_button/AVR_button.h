#ifndef _AVR_BUTTON_H_
#define _AVR_BUTTON_H_

#include"button.h"

#define MAX_BUTTON_NUMBER 20

 class AVR_button:Button
{
 AVR_button();
 AVR_button(uint8_t _port,uint8_t _pin);
 AVR_button(uint8_t _pin);
 AVR_button(uint8_t _pin, buttonMode _mode);
 public:

 static AVR_button* buttons[MAX_BUTTON_NUMBER];
 static  uint8_t buttons_index;

 private:

 uint8_t port;
 uint8_t pin;

 static uint8_t pin_state[MAX_BUTTON_NUMBER];
 static uint8_t pin_prev_state[MAX_BUTTON_NUMBER];

 void addButton(AVR_button* b);
 static void updatePinState();
 static void updateButtonState();
 static void updateButton();

};

#endif