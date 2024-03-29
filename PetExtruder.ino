
#include <SPI.h>          // incluimos la libreria de SPI,  
#include <LiquidCrystal.h>//incluimos la libreria de LCD16X2
#include "variables.h"    //incluimos las variables
#include "motor.h"
#include "sensor.h"    //incluimos las variables
#include "lcd.h"          //incluimos las funciones generadas para la pantalla

void setup() {
    Serial.begin(9600); 
    sensorInit();
    motorInit(),
    resistorInit();
    lcdInit();
}

void loop() {
  //  (COLUMNA, FILA)
   menuExtrusion();
   extrusionInit();
}
