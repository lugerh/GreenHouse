#include <Arduino.h>
#include <DS1307RTC.h>
tmElements_t tm;
const char *monthName[12] = {
  "Jan", "Feb", "Mar", "Apr", "May", "Jun",
  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

bool getTime(const char *str)
{
  int Hour, Min, Sec;

  if (sscanf(str, "%d:%d:%d", &Hour, &Min, &Sec) != 3) return false;
  tm.Hour = Hour;
  tm.Minute = Min;
  tm.Second = Sec;
  return true;
}

bool getDate(const char *str)
{
  char Month[12];
  int Day, Year;
  uint8_t monthIndex;

  if (sscanf(str, "%s %d %d", Month, &Day, &Year) != 3) return false;
  for (monthIndex = 0; monthIndex < 12; monthIndex++) {
    if (strcmp(Month, monthName[monthIndex]) == 0) break;
  }
  if (monthIndex >= 12) return false;
  tm.Day = Day;
  tm.Month = monthIndex + 1;
  tm.Year = CalendarYrToTm(Year);
  return true;
}

String getHora()
{
    String output, hora, minuto;
    if (tm.Hour<10 && tm.Hour>-1)
    {
      hora = '0' + String(tm.Hour);
    }
    else
    {
      hora = tm.Hour;
    }
    if (tm.Minute<10 && tm.Minute>-1)
    {
      minuto = '0' + String(tm.Minute);
    }
    else
    {
      minuto = tm.Minute;
    }
    output= hora +':'+ minuto;
    return output;
}
String getFecha()
{
    String output, dia, mes, ano;
    if (tm.Day<10 && tm.Day>-1)
    {
      dia = '0' + String(tm.Day);
    }
    else
    {
      dia = tm.Day;
    }
    if (tm.Month<10 && tm.Month>-1)
    {
      mes = '0' + String(tm.Month);
    }
    else
    {
      mes = tm.Month;
    }
    ano = tmYearToCalendar(tm.Year);  // año en formato calendario
    output= dia +'/'+ mes +'/'+ ano[2] + ano[3] ;
    return output;
}
/*
 * Libreria dedicada a al RTC ds3231
 * 
 */
 /*
#include <Arduino.h>
void setHora()
{
    //--------RTC SETUP ------------
    Rtc.Begin();
///////////// usa tiempo de compilacion para grabar la hora

    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);

/////////////

    if (!Rtc.IsDateTimeValid()) 
    {
        codeError = debug("RTC DateTime is invalid!",RTCNOK,DEBUG);
//        Serial.println("RTC DateTime is invalid!");
        Rtc.SetDateTime(compiled);
    }

    if (!Rtc.GetIsRunning())
    {
        codeError = debug("RTC starting now",OK,DEBUG);
//        Serial.println("RTC starting now");
        Rtc.SetIsRunning(true);
    }

    RtcDateTime now = Rtc.GetDateTime();
    if (now < compiled) 
    {
        codeError = debug("RTC Updating DateTime ",OK,DEBUG);
//        Serial.println("RTC Updating DateTime ");
        Rtc.SetDateTime(compiled);
    }
    else if (now > compiled) 
    {
        codeError = debug("RTC time this is expected",OK,DEBUG);
//        Serial.println("RTC time this is expected");
    }
    else if (now == compiled) 
    {
        codeError = debug("RTC is the same as compile time! (not expected but all is fine)",OK,DEBUG);
//        Serial.println("RTC is the same as compile time! (not expected but all is fine)");
    }
    Rtc.Enable32kHzPin(false); // Clock 32KHz disabled
    Rtc.SetSquareWavePin(DS3231SquareWavePin_ModeNone); // wave tipe none
}
    
float tempClock()
{
  RtcTemperature temp = Rtc.GetTemperature();
//  Serial.print(temp.AsFloat());
//  Serial.println("C");
  return temp.AsFloat();
}

String strFecha()
{
  RtcDateTime dt = Rtc.GetDateTime();
  String fecha = String(dt.Day()) + String("/") + String(dt.Month()) + String("/") +String(dt.Year());
  return fecha;
}

String strHora()
{
  String _minuto;
  String _hora;
  RtcDateTime dt=Rtc.GetDateTime();
  if (dt.Minute()<10)
  {
    _minuto="0"+String(dt.Minute());
  }
  else 
  {
    _minuto=String(dt.Minute());
  }
  if (dt.Hour()<10)
  {
    _hora="0"+String(dt.Hour());
  }
  else 
  {
    _hora=String(dt.Hour());
  }
  String hora = (_hora + ":" + _minuto);
  //String hora = String (dt.Hour()) +":" + String(dt.Minute()) +":" + String(dt.Second());
  return hora;
}

boolean compare_hour(int h_init, int m_init, int h_fin, int m_fin)
{
  RtcDateTime dt=Rtc.GetDateTime();
  boolean result=false;
  int h_actual, m_actual;
  h_actual=dt.Hour();
  m_actual=dt.Minute();
  if (h_actual>=h_init && h_actual<=h_fin && m_actual>=m_init && m_actual<=m_fin) result=true;
  else result=0;
  return result;
}*/

