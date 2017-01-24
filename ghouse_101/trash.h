/*
 * pendiente extraer la parte de escritura en targeta
 * creando una funcion en el main para escribir el log
 */

uint8_t debug(String str, uint8_t valor, bool mostrar=true, uint8_t tipoSalida=0)
{
    if (mostrar)
    {
      Serial.println(str);
    }
    codeError=valor;
    myLog = SD.open("log.txt", FILE_WRITE);
    myLog.println(fecha +";" + hora + ";" + String(codeError)+";"+ str);
    myLog.close();
    switch (tipoSalida)
    {
        case 0: return valor;
        case 1: return str;
    }
}
