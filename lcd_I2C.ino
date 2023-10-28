#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // Muestra la dirección de la LCD a 0x27 

void setup()
{
  lcd.init();                      //Inicializa el LCD
 
  // Muestra mensaje en lcd.
  lcd.backlight();
  lcd.print("Hola, Mundo!");
}

void loop()
{
}