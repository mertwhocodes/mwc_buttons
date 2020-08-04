#include"button.h"


//uint8_t Button::buttons_index=0;
//Button* Button::buttons[MAX_BUTTON_NUMBER];

Button::Button()
{
// addButton(this);
}

/*void Button::addButton(Button* b)
{
    buttons[buttons_index]= b;
    buttons_index++;
}*/

void Button::setPressedTask(ButtonFuncPointer f)
{
   pressedTask=f; 
}

void Button::setReleassedTask(ButtonFuncPointer f)
{
   releasedTask=f; 
}

void Button::setMode(buttonMode m)
{
    mode=m;
}

void Button::setState(buttonState s)
{
    state=s;
}
void Button::setPrevState(buttonState s)
{
   previous_state=s;
}

buttonState Button::getState()
{
    return state;
}
buttonState Button::getPrevState()
{
    return previous_state;
}
buttonMode Button::getMode()
{
    return mode;
}