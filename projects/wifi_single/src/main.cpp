#include <Arduino.h>
#include <WiFi.h>

// const char *ssid = "Just_Wei";
// const char *password = "JustWei512";

const char *ssid = "Wokwi-GUEST";// 您的WiFi网络名称
const char *password = "";// 您的WiFi网络密码

void setup()
{
  Serial.begin(9600);
  Serial.print("正在连接WiFi");

  WiFi.begin(ssid, password);
  // WiFi.begin(ssid, password, 6);// 可以明确指定信道,加快连接速度,但不太建设这样做的话,可能会导致连接失败

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi已连接.");
  Serial.println("IP地址: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
  delay(100);
}