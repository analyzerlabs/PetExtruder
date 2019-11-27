void sensorInit(){
    SPI.begin(); 
    pinMode(PIN_CS_MAX6675,OUTPUT); 
    digitalWrite(PIN_CS_MAX6675,HIGH);
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
