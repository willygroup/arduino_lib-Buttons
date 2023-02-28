/*
 * Button.h - Simple anti-bounce for buttons
 * Buttons 20230228 by willygroup
 */

#ifndef _BUTTONS_H
#define _BUTTONS_H

#include "Arduino.h"

#define BOUNCETIME 200

class Buttons
{
public:
	Buttons(int pin);
	Buttons(int pin, int debounce);
	boolean readValue();

private:
	void _init();
	void _setPin(int pin);
	void _setDebounce(int debounce);

	int _pin;			   // Arduino Pin to which is phisically connected the button
	int _previous;		   // Previous value
	int _lastDebounceTime; //
	int _debounce;		   // Debounce Time
	int _lastButtonState;  // the previous reading from the input pin
	int _buttonState;	   // the current reading from the input pin
};

#endif
