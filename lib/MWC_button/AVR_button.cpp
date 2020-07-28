#include"AVR_button.h"


uint8_t AVR_button::buttons_index=0;
AVR_button* AVR_button::buttons[MAX_BUTTON_NUMBER];

uint8_t pin_state[MAX_BUTTON_NUMBER];
uint8_t prev_pin_state[MAX_BUTTON_NUMBER];

AVR_button::AVR_button()
{
  
}
#ifdef ARDUINO
#include <Arduino.h>

AVR_button::AVR_button(uint8_t _pin)
{
    addButton(this);
    pin = _pin;
    pinMode(pin, INPUT);
    this->setMode(Pullup);
}
AVR_button::AVR_button(uint8_t _pin, buttonMode _mode)
{
    addButton(this);
    pin = _pin;
    pinMode(pin, INPUT);
    this->setMode(_mode);
}

void AVR_button::updatePinState()
{
 //TODO- convert byte size pin state to bit size 

    AVR_button btn;
    
    for (uint8_t i = 0; i < MAX_BUTTON_NUMBER; i++)
    {
        if(buttons[i]==nullptr)
        {
          break;
        } 
        btn=*buttons[i];
        pin_prev_state[i]=pin_state[i];
        pin_state[i]=digitalRead(btn.pin);
    }
    
    for (uint8_t i = 0; i < MAX_BUTTON_NUMBER; i++)
    {
        if(buttons[i]==nullptr)
        {
          break;
        } 
        //1-0= 1(released for pullup)
        //0-1=-1(pressed for pullup)
        //0-0= 0(nonstate)
        //1-1= 0(nonstate)
        pin_state[i]-=pin_prev_state[i];
     }
    
}
void AVR_button::updateButtonState()
{
    updatePinState();
     for (uint8_t i = 0; i < MAX_BUTTON_NUMBER; i++)
    {
        if(buttons[i]==nullptr)
        {
          break;
        } 
            buttons[i]->setPrevState(buttons[i]->getState());
        if (buttons[i]->getMode()==buttonMode::Pullup)
        {
            if (pin_state[i]==1)
            {
                buttons[i]->setState(buttonState::Released);
            }
            else if(pin_state[i]==-1)
            {
                buttons[i]->setState(buttonState::Pressed);
            }
            else
            {
                buttons[i]->setState(buttonState::NonState);
            }
        }
        else if (buttons[i]->getMode()==buttonMode::Pulldown)
        {
            if (pin_state[i]==1)
            {
                buttons[i]->setState(buttonState::Pressed);
                buttons[i]->pressedTask(nullptr);
            }
            else if(pin_state[i]==-1)
            {
                buttons[i]->setState(buttonState::Released);
                buttons[i]->releasedTask(nullptr);
            }
            else
            {
                buttons[i]->setState(buttonState::NonState);
            }
        }
        
     }
    //TODO-add update Button State 
}
void AVR_button::updateButton()
{
    updatePinState();
    //TODO-add update Button  
}
#endif

AVR_button::AVR_button(uint8_t _port,uint8_t _pin)
{
   // TODO-ADD button configuration for AVR

}

void AVR_button::addButton(AVR_button* b)
{
   buttons[buttons_index]= b;
   buttons[buttons_index+1]= nullptr;
   buttons_index++;
}

