// Como se usa el sensor  DHT-11  con Arduino
//   Sensor de Temperatura y Humedad 
// Conexión de LCD a Arduino Uno
 //  SDA --> A4
 //  SCL --> A5

//Librerias a utilizar para sensor DHT11
#include <DHT.h>;
//I2C LCD:
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2); // configurar la dirección LCD en 0x27 para una pantalla de 16 caracteres y 2 líneas
  
//Constants
#define DHTPIN 7     // El pin digital que nosotros conectemos
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE); //// Inicializa el sensor DHT

//Variables
//int chk;
int h;  //Almacena el valor de humedad
int t; //Almacena el valor de la temperatura

void setup()
{
    Serial.begin(9600);
    Serial.println("Temperature and Humidity Sensor Test");
    dht.begin();
    lcd.init(); //Inicializar el LCD
    lcd.backlight(); //Abre la retroiluminación
}

void loop()
{
    //Lee los datos y almacenarlos en las variables h (humedad) y t (temperatura)
    // La lectura de temperatura o humedad tarda unos 250 milisegundos!
    h = dht.readHumidity();
    t = dht.readTemperature();
    
    //Imprime los valores de temperatura y humedad en el monitor serial
    Serial.print("Humedad: ");
    Serial.print(h);
    Serial.print(" %, Temperatura: ");
    Serial.print(t);
    Serial.println(" ° Celsius");
        
// set the cursor to (0,0):
// print from 0 to 9:

    lcd.setCursor(0, 0);
    lcd.println(" Temperatura Actual ");
    
    lcd.setCursor(0, 1);
    lcd.print("T:");
    lcd.print(t);
    lcd.print("C");

    lcd.setCursor(6, 1);
    lcd.println("STEAM ");
     
    lcd.setCursor(11, 1);
    lcd.print("H:");
    lcd.print(h);
    lcd.print("%");
    
  delay(1000); //Espera 1 segundo
}
