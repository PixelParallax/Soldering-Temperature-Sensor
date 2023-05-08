// Packages
#include "max6675.h"

// Config
bool dev = true; // While true this will print to the serial monitor
int warmT = 40;
int solderT = 200;

// Thermocouple Variables

int thermoCLK = 8;
int thermoCS = 9;
int thermoDO = 12;

// LED Variables
#define BLUE_LED 2
#define RED_LED 6
#define GREEN_LED 10

// Thermocouple Setup
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

// Program Begin //

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  if(dev = true) {
    Serial.begin(9600);
    Serial.println("Starting...");
    delay(500);
  }
}

void loop() {
  if(dev = true) {
    Serial.print("Current Temp (C): ");
    Serial.println(thermocouple.readCelsius());
  }

  if (thermocouple.readCelsius() < warmT) {
    analogWrite(RED_LED, 0);
    analogWrite(GREEN_LED, 255);
    analogWrite(BLUE_LED, 0);
  } else if (thermocouple.readCelsius() > warmT && thermocouple.readCelsius() < solderT) {
    analogWrite(RED_LED, 255);
    analogWrite(GREEN_LED, 50);
    analogWrite(BLUE_LED, 0);
  } else if (thermocouple.readCelsius() > solderT) {
      analogWrite(RED_LED, 255);
      analogWrite(GREEN_LED, 0);
      analogWrite(BLUE_LED, 0);
  } else {
    analogWrite(RED_LED, 0);
    analogWrite(GREEN_LED, 0);
    analogWrite(BLUE_LED, 255);
  }
  delay(400);
}
