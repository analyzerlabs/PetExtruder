void motorInit(){
     pinMode(11,OUTPUT);
     digitalWrite(11,HIGH);
  }
void resistorInit(){
     pinMode(12,OUTPUT);
     digitalWrite(12,HIGH);
  }
void moveMotor(){
     digitalWrite(11,LOW);
  }
void stopMotor(){
     digitalWrite(11,HIGH);
  }
void startResistor(){
     digitalWrite(12,LOW);
  }
void stopResistor(){
     digitalWrite(12,HIGH);
  }
