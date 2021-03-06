/*
 * Funciones adicionales para lcd
 * Depende de FaBoLCD_PCF8574.h
 * 
 * 
 */
 
#include <Arduino.h>
#include <FaBoLCD_PCF8574.h>
FaBoLCD_PCF8574 lcd;

#define waitRefresh 3000

void printState(String msj)
{
    //lastState=msjError;
    uint8_t _x=0;
    uint8_t _X=0;
    uint8_t msjLen = strlen(msj.c_str()); // convertir a char array y sacar longitud del array
    if (msjLen >= 16) _x=0;  
    if (msjLen%2==0)       // si msj es par 
    {
        _x = (16/2)-(msjLen/2);
        _X =  (16/2)+(msjLen/2);
    }
    else                   // si msj es impar
    {
        _x= (16/2)-((msjLen+1)/2);
        _X =  (16/2)+((msjLen-1)/2);
    }
    lcd.setCursor(_x,1); // (<X>,<Y>)
    lcd.print(msj);
    
    for (int i=0;i<_x;i++)
    {
        lcd.setCursor(i,1); // (<X>,<Y>)
        lcd.print(" ");
    }
    for (int i=_X;i<=16;i++)
    {
        lcd.setCursor(i,1); // (<X>,<Y>)
        lcd.print(" ");
    }
}
void seeHour(String hora, String fecha, String lastState)
{
    lcd.clear();
    lcd.setCursor(0,0); // (<X>,<Y>)
    lcd.print(fecha + "  " + hora); 
    printState(lastState);
    delay(waitRefresh);
    lcd.setCursor(11,0);
    lcd.print(hora);
}

void seeBanner()
{
    lcd.clear();
    lcd.setCursor(2,0); // (<X>,<Y>)
    lcd.print("Green House ");
    lcd.setCursor(3,1); // (<X>,<Y>)
    lcd.print("by lugerh");
    delay(waitRefresh);
    lcd.clear();  
}

void seeBannerDlabs()
{
    lcd.clear();
    lcd.setCursor(1,0); // (<X>,<Y>)
    lcd.print("in cooperation");
    lcd.setCursor(1,1); // (<X>,<Y>)
    lcd.print("with  Dlabs.co ");
    delay(waitRefresh);
    lcd.clear();  
}
