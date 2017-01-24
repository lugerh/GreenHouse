
/*
 * 
 * 
 */

#include "pins.h"
#include "config.h"
#include "debug.h"
#include "rtc.h"
#include "lcd.h"
#include "config_log.h"
#include "rele.h"
#include "rele2.h"

// Variables Glovales
uint8_t lastCodeError = -1;

//objetos

Rele bomba1(pinBomba1);
Rele bomba2(pinBomba2);
Rele bomba3(pinBomba3);
Rele bomba4(pinBomba4);
Rele valvula1(pinValvula1);
Rele valvula2(pinValvula2);
Rele valvula3(pinValvula3);
Rele valvula4(pinValvula4);


void setup()
{

    // Iniciar servicios
    configurarPines();
    lcd.begin(16, 2); // Inicializar LCD
    Serial.begin(baudDebug);
    // Actualizar fecha y hora en el RTC 
    if (getDate(__DATE__) && getTime(__TIME__))
    {
        // and configure the RTC with this info
        if (RTC.write(tm))
        {
            debug("Update Date & Time", 30, DEBUG, OUTDEBUG);
        }
    }
    if (!SD.begin(pin_CS))    // Montar uSD
    {
        debug("Initializing SD card..... Failed!", 81, DEBUG, OUTDEBUG);   // If wrong
        return;
    }
    else
    {
        debug("Initializing SD card..... Correcto!", 80, DEBUG, OUTDEBUG); // If OK
    }
    // Cargar Configuracion
    // Inicializar log?
    debug(getFecha() + "  " + getHora(), OK, DEBUG, OUTDEBUG);
    seeBanner();
    seeBannerDlabs();
    seeHour(getHora(), getFecha(), debug("System OK", lastCodeError=OK, DEBUG, OUTDEBUG));
}

void loop()
{
    seeBanner();
    seeBannerDlabs();
    seeHour(getHora(), getFecha(), "System ok");
}
String debug(String str, uint8_t valor, bool onOff, boolean serialOrLog) // 1=Serial 0=Log
{
    if (onOff==1)
    {
        if (serialOrLog==1)     // salida serie
        {
            Serial.println(str);
        }
        else                    //salida log (uSD)
        {
            logWrite(getFecha(), getHora(), str);
        }
    }
    return str;
}

