const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);    //se  defiunen los pines de la pantalla lcd 16x2

#define PIN_CS_MAX6675 9     // pin de control para el sensor de températura
#define ESPERA_ENTRE_LECTURAS 500 // Un valo  r mayor que 220 ms (al menos 250 ms por seguridad)

int temperatura; // Entero en el que se almacenan los datos recibidos desde el MAX6675
unsigned long t;
unsigned long tc;
unsigned long t_precalentamiento;

boolean control = false;
int controlPin = 19;
boolean i = true;
int n = 0;
byte centigrados[8] =     //variable para generar el caracter Corazon
{
  0b01000,
  0b10100,
  0b01000,
  0b00011,
  0b00100,
  0b00100,
  0b00100,
  0b00011
};

byte carga   [8] =   //variable para carga de la pantalla
{
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
};

byte termometer[8] =   //variable para generar el caracter carita feliz
{
   0b00100,
   0b01010,
   0b01010,
   0b01110,
   0b01110,
   0b11111,
   0b11111,
   0b01110
  };

byte a1[8] =     //variable para generar el caracter carita triste
{
0b00000,
0b01010,
0b01010,
0b00000,
0b00000,
0b01110,
0b00001,
0b00000,
};

byte a2[8] =     //variable para generar el caracter pelota arriba
{
0b00000,
0b00000,
0b01110,
0b11111,
0b11111,
0b11111,
0b01110,
0b00000,
};

byte a3[8] =     //variable para generar el caracter pelota abajo
{
0b00000,
0b01110,
0b11111,
0b11111,
0b11111,
0b01110,
0b00000,
0b00000,
};

byte reloj1[8] =    //variable para generar el caracter reloj de arena lleno
{
0b11111,
0b10001,
0b01110,
0b00100,
0b01010,
0b10001,
0b10001,
0b11111,
};

byte reloj2[8] =     //variable para generar el caracter reloj de arena vacio
{
0b11111,
0b10001,
0b01110,
0b00100,
0b01010,
0b10001,
0b11111,
0b11111,
};

//Funcion para generar retraso de tiempo
void wait(int tiempo){      
  unsigned long T = millis();
  while(millis()<T+tiempo){}
}
