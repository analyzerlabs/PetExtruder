void menuInicio(){       //funcion para mostrar el menu de inicio
  lcd.setCursor(0,0);
  lcd.print("- EXTRUSORA PET ");  // mensaje de inicio
  for(int i=0 ; i<16;i++){     //carga de corazones en pantalla
    lcd.setCursor(i,1);        
    lcd.write(byte(1));   
    delay(100);
  }
  delay(500);                 //espera 0.5 segundos
}


// LOOP DE EXTRUSION
void extrusion(){
   lcd.setCursor(0,0);
   lcd.print("                ");
   wait(1500);
   lcd.setCursor(0,0);                //mueve el cursos a la columna 0 de la fila 1
   lcd.write(byte(7));                //imprime el icono pelota
   t = millis();
   int n = 0;
   boolean i=0;
   lcd.setCursor(8, 1);
   lcd.print("T: ");
   while(true){    //bucle de extrusion incia automaticamente
      if((millis()-t)>300){//condicion cada segundo de los 30 seg
         t = millis();
         float K = getTemperature();
         printTemperature(K);
         
         if(K > 220)moveMotor();                    
         if(K >= 240)stopResistor();
         if(K < 210){
            startResistor();
            stopMotor();
         }
   
         i = !i;                    // cambia el simbolo reloj
         lcd.setCursor(0, 1);
         lcd.write(byte(6+int(i)));  // imprime el simbolo reloj en LCD con movimiento
         lcd.print(":");
         lcd.setCursor(11, 1);
         lcd.print(K);
      }
   } 
   delay(2000);
   control = ! control;        //variable de control de juego para reiniciar
}


void lcdInit(){
  lcd.begin(16, 2); //Inicializa la pantalla LCD 16x2 CARACTERES
  lcd.createChar(0, heart);      //se genera el caracter corazon
  lcd.createChar(1, carga);
  lcd.createChar(2, happy);    //se genera el caracter carita feliz
  lcd.createChar(3, sad);       //se genera el caracter carita triste
  lcd.createChar(4, pong1);    //se genera el caracter pelota arriba
  lcd.createChar(5, pong2);    //se genera el caracter pelota abajo
  lcd.createChar(6, reloj1);    //se genera el caracter reloj de arena lleno
  lcd.createChar(7, reloj2);    //se genera el caracter reloj de arena vacio
  menuInicio();                 //se llama a la funcion menu inicio
}
