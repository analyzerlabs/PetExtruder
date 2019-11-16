#include <LiquidCrystal.h>
#include <SPI.h> 

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define PIN_CS_MAX6675 9 
#define ESPERA_ENTRE_LECTURAS 1000 // Un valor mayor que 220 ms (al menos 250 ms por seguridad)

int temperatura; // Entero en el que se almacenan los datos recibidos desde el MAX6675

void setup() {
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    lcd.begin(16, 2);
    Serial.begin(9600); 
    SPI.begin(); 
    pinMode(PIN_CS_MAX6675,OUTPUT); 
    digitalWrite(PIN_CS_MAX6675,HIGH);
}

void loop() {
  //         (COLUMNA, FILA)
    lcd.setCursor(0, 0);
    lcd.print("Extrusora PET");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.setCursor(6, 1);
    lcd.print((float)temperatura/4.0,DEC);
}

void getTemperature(){
    digitalWrite(PIN_CS_MAX6675,LOW);
    temperatura=SPI.transfer(0); 
    temperatura<<=8; 
    temperatura|=SPI.transfer(0); 
    digitalWrite(PIN_CS_MAX6675,HIGH); 
    temperatura>>=3; 
    Serial.print("Temperatura del horno: "); 
    Serial.print((float)temperatura/4.0,DEC); 
    Serial.println(" °C"); 
    delay(ESPERA_ENTRE_LECTURAS); 
}
