


#include <Arduino.h>
void relOnOff(uint8_t pin, bool estado)
{
    estado==0? LOW : HIGH;
    digitalWrite(pin, estado );
}
