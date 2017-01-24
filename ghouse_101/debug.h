
#include <Arduino.h>

// valores

#define OK        10
#define NOK       11
#define WIFIOK    20
#define WIFINOK   21
#define RTCOK     30
#define RTCNOK    31
#define DHTOK     40
#define DHTNOK    41
#define LCDOK     50
#define LCDNOK    51
#define PHOK      60
#define PHNOK     61
#define PTOK      70
#define PTNOK     71
#define SDOK      80
#define SDNOK     81

// funciones
/*
uint8_t debug(String str, uint8_t valor, bool mostrar=true, int salida)
{
    if (mostrar)
    {
        Serial.println(str);
    }
    if (salida==0) return valor;
    if (salida==1) return str;
    return -1;
}*/
