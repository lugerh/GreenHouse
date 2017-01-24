#include <Arduino.h>
#include <SD.h>
File myLog;
char Cfile[9] = {'c', 'o', 'n', 'f', '.', 't', 'x', 't', '\0'};  // char array of name file(Cfile)
int logWrite(String fecha, String hora, String msj)
{
    char Cdir [8] = { 'l', 'o', 'g', '/', fecha[6], fecha[7], '/', '\0'};
    if (SD.exists(Cdir)) // si el directorio no existe:
    {
        SD.mkdir(Cdir);// Crear directorio
    }
    char Cfile[20] = {'l', 'o', 'g', '/', fecha[6], fecha[7], '/', fecha[6], fecha[7], '-', fecha[3], fecha[4], '-', fecha[0], fecha[1], '.', 't', 'x', 't', '\0'};
    if (myLog = SD.open(Cfile, FILE_WRITE))  // si no existe
    {
        myLog.println(fecha +";" + hora + ";" + msj); //+ ";" + String(lasCodeError) +";"+ msj);
    }
    else
    {
      
    }
    myLog.close();//crearlog del dia sacando la fecha del dsxxxx
}

int actualizarConfig()
{
    
    
}


/*
 * myLog.exists(Cfile)==0)
 *    myLog = SD.open(toCharArray(fecha + " " + hora + ".txt", FILE_WRITE);
    myLog.println(fecha +";" + hora + ";" + String(lasCodeError) +";"+ msj);
    myLog.close();
    
 */
