
#include <DHT.h>

//Constants
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11  (AM2302)
// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum

void setup()
{
    Serial.begin(9600);
  dht.begin();
    
}

void loop()
{ int sensorReading = analogRead(A0);
  // map the sensor range (four options):
  // ex: 'long int map(long int, long int, long int, long int, long int)'
  int range = map(sensorReading, sensorMin, sensorMax, 0, 255);
 Serial.print(range);
 Serial.print("-");
 int a1=analogRead(A1);
 Serial.print(a1);

  
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    //Print temp and humidity values to serial monitor
    Serial.print("-");
    Serial.print(hum);
    Serial.print("-");
    Serial.println(temp);
 //   Serial.println("-");
    delay(2000); //Delay 2 sec.
}

   
