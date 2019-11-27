void sensorInit(){
    SPI.begin(); 
    pinMode(PIN_CS_MAX6675,OUTPUT); 
    digitalWrite(PIN_CS_MAX6675,HIGH);
  }
float getTemperature(){
    digitalWrite(PIN_CS_MAX6675,LOW);
    temperatura=SPI.transfer(0); 
    temperatura<<=8; 
    temperatura|=SPI.transfer(0); 
    digitalWrite(PIN_CS_MAX6675,HIGH); 
    temperatura>>=3; 
    return(1.00*temperatura/4);
}

float printTemperature(float t){
    Serial.print("Temperatura de extrusion: "); 
    Serial.print(t); 
    Serial.println(" °C"); 
  }
