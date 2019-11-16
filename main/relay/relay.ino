#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define PIN_CS_MAX6675 9 // Pin de Arduino al que se conecta la señal CS del MAX6675
#define ESPERA_ENTRE_LECTURAS 1000 // Un valor mayor que 220 ms (al menos 250 ms por seguridad)
 
#include <SPI.h> // Añadir al código la librería de comunicaciones SPI
 
int temperatura; // Entero en el que se almacenan los datos recibidos desde el MAX6675
void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  lcd.begin(16, 2);

  
  Serial.begin(9600); // Inicializar las comunicaciones serie para mostrar la temperatura en la consola
  SPI.begin(); // Inicializar las comunicaciones SPI
  pinMode(PIN_CS_MAX6675,OUTPUT); // Declarar como salida el pin al que se conecta el MAX6675
  digitalWrite(PIN_CS_MAX6675,HIGH); // Establecer CS a nivel alto (inhabilitar las comunicaciones SPI con el MAX6675)
}

void loop() {
  //         (COLUMNA, FILA)
  
  
  digitalWrite(PIN_CS_MAX6675,LOW); // Habilitar las comunicaciones SPI con el MAX6675
  temperatura=SPI.transfer(0); // Recibir el byte más significativo
  temperatura<<=8; // Colocar los 8 bits más significativos en su posición
  temperatura|=SPI.transfer(0); // Añadir los 8 bits del siguiente byte recibido desde el MAX6675
  digitalWrite(PIN_CS_MAX6675,HIGH); // Desactivar las comunicaciones SPI con el MAX6675
  temperatura>>=3; // Reubicar en la variable los datos de la temperatura (para que el LSB del valor quede en su posición)
  Serial.print("Temperatura del horno: "); // Mostrar un mensaje para identificar qué temperatura se está monitorizando (un horno de cerámica, por ejemplo)
  Serial.print((float)temperatura/4.0,DEC); // Dividir el valor entre 4 (el valor representa cuartos de grado)
  Serial.println(" °C"); // Indicar las unidades en las que se muestra la temperatura
  delay(ESPERA_ENTRE_LECTURAS); // Una forma poco elegante pero muy elocuente de leer la temperatura cada cierto intervalo

  lcd.setCursor(0, 0);
  lcd.print("Extrusora PET");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.setCursor(6, 1);
  lcd.print((float)temperatura/4.0,DEC);
  
  
}
