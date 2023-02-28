/*
 * Button.cpp - Simple anti-bounce for buttons
 * Buttons 20230228 by willygroup
 */
#include "Buttons.h"

/**
 * @brief Create a button by specifying the pin
 */
Buttons::Buttons(int pin)
{
	_init();
	_setPin(pin);
}

/**
 * @brief Create a button by specifying the pin and the bounce time
 */
Buttons::Buttons(int pin, int debounce)
{
	_init();
	_setPin(pin);
	_setDebounce(debounce);
}

void Buttons::_init()
{
	_previous = LOW;
	_lastButtonState = LOW;
	_lastDebounceTime = 0;
	_setDebounce(BOUNCETIME);
}

void Buttons::_setDebounce(int debounce)
{
	_debounce = debounce;
}

void Buttons::_setPin(int pin)
{
	_pin = pin;
	pinMode(_pin, INPUT);
}

/**
 * @brief Read the current status of the button
 */
boolean Buttons::readValue()
{
	int reading = digitalRead(_pin);
	if ((reading == HIGH && _previous == LOW) && (millis() - _lastDebounceTime > _debounce))
	{ // Status switched from LOW to HIGH and the debouce time is expired
		_lastDebounceTime = millis();
		_previous = reading;
		return true;
	}
	else if (reading == HIGH && _previous == HIGH)
	{
		_lastDebounceTime = millis();
	}
	_previous = reading;
	return false;

	int reading = digitalRead(_pin);

	// check to see if you just pressed the button
	// (i.e. the input went from LOW to HIGH),  and you've waited
	// long enough since the last press to ignore any noise:

	// If the switch changed, due to noise or pressing:
	if (reading != _lastButtonState)
	{
		// reset the debouncing timer
		_lastDebounceTime = millis();
	}

	if ((millis() - _lastDebounceTime) > _debounce)
	{
		// whatever the reading is at, it's been there for longer
		// than the debounce delay, so take it as the actual current state:

		// if the button state has changed:
		if (reading != _buttonState)
		{
			_buttonState = reading;

			// only toggle the LED if the new button state is HIGH
			if (_buttonState == HIGH)
			{
				_lastButtonState = reading;
				return true;
			}
		}
	}

	// save the reading.  Next time through the loop,
	// it'll be the lastButtonState:
	_lastButtonState = reading;
	return false;
}
