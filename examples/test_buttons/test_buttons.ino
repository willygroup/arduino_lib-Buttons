/*
        Buttons Test

        Simple example that shows how the Buttons library works
        If you press the button before the bounce time is elapsed
        the led won't change state

        Created 20131112
        By willygroup
        Modified 20230228
        By willygroup

*/

#include <Buttons.h>

#define LED 13
#define BUTTON 2
#define BOUNCE_TIME 500

Buttons b1(BUTTON, BOUNCE_TIME);

int state = LOW;

void setup()
{
    pinMode(LED, OUTPUT);
    digitalWrite(LED, state);
}
void loop()
{
    int reading = b1.readValue();
    if (reading)
    {
        state = !state;
    }
    digitalWrite(LED, state);
}
