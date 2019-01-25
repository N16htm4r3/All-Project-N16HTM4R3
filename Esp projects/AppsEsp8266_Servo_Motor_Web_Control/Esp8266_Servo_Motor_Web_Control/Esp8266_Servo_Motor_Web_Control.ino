#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo;
Servo servo1;
Servo servo2;
Servo servo3;
char auth[] = "6714d52ddd9e481baa51deb2d7908d22";
char ssid[] = "N16HTM4R3";
char pass[] = "12121212";

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  servo.attach(15); // NodeMCU D8 pin
  servo1.attach(13); //D7
  servo2.attach(12); //D6
  servo3.attach(14); //D5
 }
  
void loop()
{
  
  Blynk.run();
  
}
BLYNK_WRITE(V1)
{
   servo.write(param.asInt());
}

BLYNK_WRITE(V2)
{
  servo1.write(param.asInt());
}
BLYNK_WRITE(V3)
{
  servo2.write(param.asInt());
}
BLYNK_WRITE(V4)
{
  servo3.write(param.asInt());
}

/*
BLYNK_WRITE(V5)
{
   servo.write(param.asInt());
}
BLYNK_WRITE(V6)
{
   servo.write(param.asInt());
}
*/
