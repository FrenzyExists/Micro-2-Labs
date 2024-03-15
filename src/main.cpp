
#include "heltec.h"
#include "Arduino.h"

// rotate only for GEOMETRY_128_64
SSD1306Wire display(0x3c, SDA_OLED, SCL_OLED, RST_OLED);

/**
 * This is a starter code from the examples from Heltec Automation.
 * 
 * Change this later, we'll need to test out how lora works with the API
 * For Future Pikachu, Angel, Jan and Victor:
 * 
 * We need to write an esp-df version of this, shouldn't be so bad. For now lets just concentrate
 * on the arduino implementation till we have something working and then we can do the proper
 * implementation. ESP-DF has features that I'm not sure we'll have access by using the Arduino
 * framework, gotta double-check that.
 * 
 * Also I need to use the CNC, can't keep using a regular hand saw and sand it manually forever
*/

void VextON(void)
{
  pinMode(Vext, OUTPUT);
  digitalWrite(Vext, LOW);
}

void VextOFF(void) // Vext default OFF
{
  pinMode(Vext, OUTPUT);
  digitalWrite(Vext, HIGH);
}

void setup()
{

  VextON();
  delay(100);

  display.init();
  display.clear();
  display.display();

  display.setContrast(255);

  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.clear();
  display.display();
}

void loop()
{
  display.screenRotate(ANGLE_0_DEGREE);
  display.setFont(ArialMT_Plain_16);
  display.drawString(64, 32 - 16 / 2, "ROTATE_0");
  display.display();
  delay(2000);

  display.clear();
  display.display();
  display.screenRotate(ANGLE_90_DEGREE);
  display.setFont(ArialMT_Plain_10);
  display.drawString(32, 64 - 10 / 2, "ROTATE_90");
  display.display();
  delay(2000);

  display.clear();
  display.display();
  display.screenRotate(ANGLE_180_DEGREE);
  display.setFont(ArialMT_Plain_16);
  display.drawString(64, 32 - 16 / 2, "ROTATE_180");
  display.display();
  delay(2000);

  display.clear();
  display.display();
  display.screenRotate(ANGLE_270_DEGREE);
  display.setFont(ArialMT_Plain_10);
  display.drawString(32, 64 - 10 / 2, "ROTATE_270");
  display.display();
  delay(2000);
}