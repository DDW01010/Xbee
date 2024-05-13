#include <Zumo32U4.h>
#include <Zumo32U4Buttons.h>
#include <Wire.h>
Zumo32U4Motors motoren;


//initialiseer de te gebruiken variabelen voor deze code

int data;
String data2;
int speed2 = 100;

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
}

void loop() {
  //checkt of er een serieel bericht binnen komt vanuit de Xbee, zo ja dan wordt dit opgeslagen in de variabele genaamd data
  if (Serial1.available() > 0) {
    data = Serial1.read();

    //Wanneer de data die binnenkomt via de Xbee overeen komt met 65(hard naar links), 97(links), 119(voorwaarts), 87(snel voorwaarts), 115(achterwaarts), 83(snel achterwaarts), 100(rechts), 87(hard naar rechts) reageren de motoren hierop door in beweging te komen en reset elke keer weer de motoren zodat de Zumo niet door blijft rijden.
    if (data == 65) {
      motoren.setRightSpeed(400);
    }

    else if (data == 97) {
      motoren.setRightSpeed(150);
    } else if (data == 119) {
      motoren.setSpeeds(150, 150);

    } else if (data == 100) {
      motoren.setLeftSpeed(150);
    } else if (data == 87) {
      motoren.setSpeeds(400, 400);
    } else if (data == 68) {
      motoren.setLeftSpeed(400);
    } else if (data == 115) {
      motoren.setSpeeds(-150, -150);
    } else if (data == 83) {
      motoren.setSpeeds(-400, -400);
    } else {
      motoren.setSpeeds(0, 0);
    }
  }
}
