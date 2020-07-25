#include"button.h"


uint8_t Button::buttons_index=0;

 Button::Button()
{

}

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

buttonState Button::getstate()
{
    return state;
}
