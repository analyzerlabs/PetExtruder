void menuInicio(){       //funcion para mostrar el menu de inicio
  lcd.setCursor(0,0);
  lcd.print("- EXTRUSORA PET ");  // mensaje de inicio
  for(int i=0 ; i<16;i++){     //carga de corazones en pantalla
    lcd.setCursor(i,1);        
    lcd.write(byte(1));   
    delay(200);
  }
  delay(500);                 //espera 0.5 segundos
}


// LOOP DE EXTRUSION
void extrusion(){
   lcd.setCursor(0,0);                        //mueve el cursos a la columna 0 de la fila 0
   lcd.print("INICIANDO ");             //imprime "Iniciando Juego"
   lcd.setCursor(0,0);
   lcd.print("                ");
   wait(1500);
   lcd.setCursor(0,1);                //mueve el cursos a la columna 0 de la fila 1
   lcd.write(byte(7));                //imprime el icono pelota
   t=millis();
   int n = 0;
   boolean i=0;
   lcd.setCursor(8, 1);
   lcd.print("T: ");
   while((30-(millis()-t)/1000) > 0){    //bucle de inicio de juego pr 30 seg
      if((millis()-t)>500*n){           //condicion cada segundo de los 30 seg
         float K = getTemperature();
         if(K > 220){
            moveMotor();                    
         }
         n++;                            //retroalimenta la condicion
         unsigned long t_restante = 30 - (millis()-t)/1000;     //calcula el tiempo restante
         if(t_restante >= 10)lcd.setCursor(2,1);   //condifciones para imprimir numeros
         if(t_restante < 10){                      //que cambian de 2 a 1 digito en lcd
            lcd.setCursor(2,1);                           
            lcd.print(" ");
            lcd.setCursor(3,1);
         }
         lcd.print(t_restante);     // imprime el tiempo restante
         lcd.setCursor(4,0);
         lcd.print("        ");
         i = !i;                    // cambia el simbolo reloj
         lcd.setCursor(0,1);        // posciona el simbolo reloj
         lcd.write(byte(6+int(i)));  // imprime el simbolo reloj en LCD con movimiento
         lcd.print(":");
         lcd.setCursor(11, 1);
         lcd.print((float)temperatura/4.0,DEC);
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
