//connect the pins to the pins metioned below, make sure that these pins mentioned here are nodemcu pins. 
// Refer the pin diagram of nodemcu before connecting
// RGB strip which i have used is common cathode
#define RED_PIN   14
#define GREEN_PIN 12
#define BLUE_PIN  13
#define NORMAL_PIN  0
#define E1 4
#define E2 5
#include "config.h"

// Enter your adafruit feed name below inplace of feed name.
AdafruitIO_Feed *analog = io.feed("feedname");




void setup() {
 
pinMode (E1, OUTPUT);
pinMode (E2, OUTPUT);
pinMode (NORMAL_PIN, OUTPUT);
pinMode (BLUE_PIN, OUTPUT);
pinMode (RED_PIN, OUTPUT);
pinMode (GREEN_PIN, OUTPUT);
  digitalWrite(E1, HIGH);
  digitalWrite(E2, HIGH);
  Serial.begin(115200);
  while(! Serial);
  Serial.print("Connecting to Adafruit IO");
  io.connect();
  analog->onMessage(handleMessage);
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println(io.statusText());
  analog->get();

 
}
void loop() {
  io.run();
  
}
void handleMessage(AdafruitIO_Data *data) {
 int reading = data->toInt();
  Serial.print("received <- ");
  Serial.println(reading);
 // for each button you press in remote you get one colour
  if(reading == 16)
  {
analogWrite (RED_PIN, 200);
analogWrite (GREEN_PIN, HIGH);
digitalWrite (BLUE_PIN, HIGH);
digitalWrite (NORMAL_PIN, HIGH);
  }
   else if(reading == 17)
  {
digitalWrite (RED_PIN, HIGH);
digitalWrite (GREEN_PIN, LOW);
digitalWrite (BLUE_PIN, HIGH);
digitalWrite (NORMAL_PIN, HIGH);
  }
     else if(reading == 18)
  {
digitalWrite (RED_PIN, HIGH);
digitalWrite (GREEN_PIN, HIGH);
digitalWrite (BLUE_PIN, LOW);
digitalWrite (NORMAL_PIN, HIGH);
  }
       else if(reading == 20)
  {
digitalWrite (RED_PIN, HIGH);
digitalWrite (GREEN_PIN, LOW);
digitalWrite (BLUE_PIN, LOW);
digitalWrite (NORMAL_PIN, HIGH);
  }
         else if(reading == 21)
  {
digitalWrite (RED_PIN, LOW);
digitalWrite (GREEN_PIN, HIGH);
digitalWrite (BLUE_PIN, LOW);
digitalWrite (NORMAL_PIN, HIGH);
  }
           else if(reading == 22)
  {digitalWrite (RED_PIN, LOW);
digitalWrite (GREEN_PIN, LOW);
digitalWrite (BLUE_PIN, HIGH);
digitalWrite (NORMAL_PIN, HIGH);
  }         
  else if(reading == 24)
  {
digitalWrite (RED_PIN, LOW);
digitalWrite (GREEN_PIN, LOW);
digitalWrite (BLUE_PIN, LOW);
digitalWrite (NORMAL_PIN, HIGH);
  }
  else
   {
digitalWrite (RED_PIN, HIGH);
digitalWrite (GREEN_PIN, HIGH);
digitalWrite (BLUE_PIN, HIGH);
digitalWrite (NORMAL_PIN, HIGH);
  }
}
