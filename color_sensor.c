/*
    Project name : Color Sensor
    Modified Date: 10-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-nano-color-sensor
*/

#include <Wire.h>
#include <Adafruit_TCS34725.h>

#define TCS34725_ADDR (0x29) // I2C address

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_ADDR);

void setup() {
  Serial.begin(9600);
  
  if (!tcs.begin()) {
    Serial.println("Color sensor not found. Check connections.");
    while (1); // Halt if no sensor is found
  }

  Serial.println("Color sensor found!");
}

void loop() {
  uint16_t red, green, blue, clear;

  tcs.getRawData(&red, &green, &blue, &clear);

  Serial.print("Red: "); Serial.print(red);
  Serial.print(" Green: "); Serial.print(green);
  Serial.print(" Blue: "); Serial.print(blue);
  Serial.print(" Clear: "); Serial.println(clear);

  delay(1000); // Adjust delay as needed
}
