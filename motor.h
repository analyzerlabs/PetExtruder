void motorInit(){
     pinMode(7,OUTPUT);
     digitalWrite(7,HIGH);
  }
void resistorInit(){
     pinMode(6,OUTPUT);
     digitalWrite(6,HIGH);
  }
void moveMotor(){
     Serial.println("****************");
     Serial.println("Iniciando Motor");
     digitalWrite(7,LOW);
  }
void stopMotor(){
     digitalWrite(7,HIGH);
  }
void startResistor(){
     digitalWrite(6,LOW);
  }
void stopResistor(){
     digitalWrite(6,HIGH);
  }
