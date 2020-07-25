#ifndef _BUTTON_H_
#define _BUTTON_H_

#include<stdint.h>

#define MAX_BUTTON_NUMBER 20

using ButtonFuncPointer = void (*) (void*);
enum buttonMode 
{
    Pullup,
    PulldownSS
};
enum buttonState
{
    Pressed,
    Released
};

class Button{

public:
 Button();

 protected :
 static  uint8_t buttons_index;
 uint8_t max_button_number;
 buttonMode mode;
 buttonState state;
 ButtonFuncPointer pressedTask;
 ButtonFuncPointer releasedTask;
 void addButton(Button* b);
 
public:
 void setPressedTask(ButtonFuncPointer f);
 void setReleassedTask(ButtonFuncPointer f);
 void setMode(buttonMode m);
 void setState(buttonState s);
 buttonState getstate();
 
 
};

#endif