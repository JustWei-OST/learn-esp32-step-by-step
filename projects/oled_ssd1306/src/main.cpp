#include <Arduino.h>
//#include <wire.h>
//#include "SSD1306.h"
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE, /* clock=*/22, /* data=*/21); // ESP32 Thing, HW I2C with pin remapping

void setup()
{

  u8g2.begin();
  u8g2.enableUTF8Print();                 // enable UTF8 support for the Arduino print() function
  u8g2.setFont(u8g2_font_wqy14_t_gb2312); // 使用指定的字库
  u8g2.setFontPosTop();

  // u8g2.setFontRefHeightExtendedText();
  // u8g2.setDrawColor(1);
  // u8g2.setFontDirection(0);
}
void loop()
{

  // u8g2.firstPage();

  for (int i = -31; i < 128; i++)
  {
    u8g2.clearBuffer();
    u8g2.setCursor(0, 4);
    u8g2.print("...Go Go 向前冲...");
    u8g2.drawBox(0 + i, 54 - i % 2, 31, 6);
    u8g2.drawBox(7 + i, 48 - i % 2, 17, 6);
    u8g2.drawDisc(7 + i, 59, 4);
    u8g2.drawDisc(22 + i, 59, 4);
    switch (i % 6)
    {
    case 0:
      u8g2.drawDisc(-6 + i, 59, 1);
      break;
    case 1:
      u8g2.drawDisc(-12 + i, 58, 2);
      break;
    case 2:
      u8g2.drawDisc(-16 + i, 57, 3);
      break;
    default:
      break;
    }
    Serial.println(i);
    delay(50);
    u8g2.sendBuffer();
  }
}