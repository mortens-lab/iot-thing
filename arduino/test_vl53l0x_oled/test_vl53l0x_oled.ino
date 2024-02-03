/* This example shows how to take
range measurements with the VL53L0X and display on a SSD1306 OLED.

The range readings are in units of mm. */

#include <Wire.h>
#include "Adafruit_VL53L0X.h"
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

Adafruit_SH1107 display = Adafruit_SH1107(64, 128, &Wire);


Adafruit_VL53L0X lox = Adafruit_VL53L0X();


void setup()
{
  Serial.begin(115200);
  Wire.begin(22,23);
  Serial.println("128x64 OLED FeatherWing test");
  delay(250); // wait for the OLED to power up
  display.begin(0x3C, true); // Address 0x3C default
  Serial.println("OLED begun");

//  Wire.begin();

  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }

  // text display big!
  display.setTextSize(4);
  display.setTextColor(SH110X_WHITE);
  display.setRotation(1);
  display.display();

  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  digitalWrite(13, HIGH);  
  digitalWrite(14, HIGH);  
  digitalWrite(15, HIGH);  
}

void loop()
{
  VL53L0X_RangingMeasurementData_t measure;

  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) 
  {  // phase failures have incorrect data
      display.clearDisplay();
      display.setCursor(0,0);
      display.print(measure.RangeMilliMeter);
      display.print("mm");
      display.display();
      Serial.println();
      delay(50);
      if (measure.RangeMilliMeter>100)
      {
         digitalWrite(14, LOW);  
         digitalWrite(15, HIGH);  
      }
      else
      {
        digitalWrite(14, HIGH);  
        digitalWrite(15, LOW);  
      }
    }
    else 
    {
      display.display();
      display.clearDisplay();
      return;
    }
}