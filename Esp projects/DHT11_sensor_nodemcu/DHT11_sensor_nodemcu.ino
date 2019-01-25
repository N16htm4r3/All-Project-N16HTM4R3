#define BLYNK_PRINT Serial // Comment this out to disable prints and save space
#include <SPI.h>;
#include <ESP8266WiFi.h>;
#include <BlynkSimpleEsp8266.h>;
//#include <SimpleTimer.h>;
#include <DHT.h>;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "6714d52ddd9e481baa51deb2d7908d22";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Zogolderr";
char pass[] = "12345678";

#define DHTPIN 2 // What digital pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11 // DHT 11
//#define DHTTYPE DHT22 // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21 // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE);
SimpleTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5, 6, 7 &amp;amp;amp;amp;amp;amp; 8).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor()
{
 float h = dht.readHumidity();
 float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

 if (isnan(h) || isnan(t)) {
 Serial.println("Failed to read from DHT sensor!");
 return;
 }
 // You can send any value at any time.
 // Please don't send more that 10 values per second.
 Blynk.virtualWrite(V5, h); // Humidity for gauge
 Blynk.virtualWrite(V6, t); // Temperature for gauge
 Blynk.virtualWrite(V7, h); // Humidity for graph
 Blynk.virtualWrite(V8, t); // Temperature for graph
}

void setup()
{
 Serial.begin(115200); // See the connection status in Serial Monitor
 Blynk.begin(auth, ssid, pass);

 dht.begin();

 // Setup a function to be called every second
 timer.setInterval(1000L, sendSensor);
}

void loop()
{
 Blynk.run(); // Initiates Blynk
 timer.run(); // Initiates SimpleTimer
}
