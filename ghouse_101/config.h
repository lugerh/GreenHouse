#include <Arduino.h> 
#include "pins.h"
#define baudDebug 9600
#define DEBUG 1                 // 1=enable 0=disable
#define OUTDEBUG 1              // 1=Serial 0=Log
void configurarPines()
{
    pinMode(pin_CS, OUTPUT);    // Pin enable sd
    pinMode(40, OUTPUT); // Pin bomba 1
    digitalWrite(40,HIGH);
}

