#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <max6675.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int ktcSO = A3;                     
int ktcCS = A2;
int ktcCLK = A1;

MAX6675 ktc(ktcCLK, ktcCS, ktcSO);
void setup()
{
   
  Serial.begin(9600);              // PREPARAR LA INTERFAZ SERIAL
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();                 //Se enciende la luz de fondo de lcd
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  lcd.setCursor(2,1);
  lcd.print("Ywrobot Arduino!");
   lcd.setCursor(0,2);
  lcd.print("Arduino LCM IIC 2004");
   lcd.setCursor(2,3);
  lcd.print("Power By Ec-yuan!");
  delay(1000);
}


void loop()
{
  // LEER EL TERMOPAR Y ALMACENAR EL VALOR EN UNA VARIABLE
  double t = ktc.readCelsius();
 
  // PRIMERO LIMPIAMOS LA PANTALLA Y LUEGO IMPRIMIMOS LA TEMPERATURA
  
  lcd.setCursor(0,2);
  lcd.print(F("Temperatura :        "));
  lcd.setCursor( 14, 2 );
  lcd.print(t);
 
  // IMPRIMIR LA TEMPERATURA EN LA TERMINAL SERIAL
  Serial.print("C = ");
  Serial.println(t);
 
  // ESPERAR UN SEGUNDO ENTRE LAS LECTURAS
  delay(1000);
}