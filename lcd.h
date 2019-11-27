//****************************************************************//
//  Creamos la funcion Inicio del Extrusor para la pantalla LCD16X2
//  se incluye una pequeña "carga" del sistema
//****************************************************************//

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

//****************************************************************//
//  Creamos la funcion Menu de Extrusor  para la pantalla LCD16X2
//****************************************************************//
 
void menuExtrusion(){
  boolean aux = digitalRead(19);   // lee el pin del boton
  while(control == true){          //si no se detecta cambio se queda en el while
      if(digitalRead(19)==false && aux == true)control = !control; //si hay cambio sale
      lcd.setCursor(0,0);
      lcd.print(" Pulse el Boton ");  // mensaje de inicio
      lcd.setCursor(0,1);
      lcd.print("Iniciar Extrusor");
  }
}

//****************************************************************//
//  Creamos la funcion Iniciar Extrusor para la pantalla LCD16X2
//  ademas esta funcion inicia el proceso de la maquina
//****************************************************************//
void extrusionInit(){
   lcd.clear();
   lcd.setCursor(0,0);                //mueve el cursos a la columna 0 de la fila 1
   
   lcd.setCursor(8, 1);
   lcd.write(byte(2));
   lcd.print(":");
   t = millis();
   tc = millis();
   t_precalentamiento = millis();
   while(millis()- tc < 600000 ){    //bucle de extrusion incia automaticamente  
      if((millis()-t)>500){//condicion cada segundo de los 30 seg
         t = millis();
         unsigned long t_restante = 600 - (millis()-tc)/1000;
         if(t_restante >= 100)lcd.setCursor(3,1);   //condifciones para imprimir numeros
         else if(t_restante < 100 && t_restante >= 100){//que cambian de 2 a 1 digito en lcd
            lcd.setCursor(3,1);                           
            lcd.print(" ");
            lcd.setCursor(4,1);
         }
         else if(t_restante < 100 && t_restante >= 100){//que cambian de 2 a 1 digito en lcd
            lcd.setCursor(4,1);                           
            lcd.print(" ");
            lcd.setCursor(5,1);
         }
         lcd.print(t_restante);     // imprime el tiempo restante
         lcd.setCursor(6,1);
         lcd.print("s");
         
         float K = getTemperature();
         printTemperature(K);

         if(millis() - t_precalentamiento < 60000){
            precalentar(K);
         }
         else{
            calentar(K);
         }

         i = !i;                    // cambia el simbolo reloj
         lcd.setCursor(0, 1);
         lcd.write(byte(6+int(i)));  // imprime el simbolo reloj en LCD con movimiento
         Serial.print(byte(6+int(i)));
         lcd.print(":");
         lcd.setCursor(11, 1);
         lcd.print(K);
         lcd.setCursor(15, 1);
         lcd.write(byte(0));
      }
   } 
   delay(2000);
   control = ! control;        //variable de control de juego para reiniciar
}


void lcdInit(){
  lcd.begin(16, 2); //Inicializa la pantalla LCD 16x2 CARACTERES
  lcd.createChar(0, centigrados);      //se genera el caracter grados centigrados
  lcd.createChar(1, carga);
  lcd.createChar(2, termometer);    //se genera el caracter termometro
  lcd.createChar(3, a1);       
  lcd.createChar(4, a2);    
  lcd.createChar(5, a3);    
  lcd.createChar(6, reloj1);    //se genera el caracter reloj de arena lleno
  lcd.createChar(7, reloj2);    //se genera el caracter reloj de arena vacio
  menuInicio();                 //se llama a la funcion menu inicio
}
