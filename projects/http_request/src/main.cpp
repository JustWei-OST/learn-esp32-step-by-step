#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

String httpGetRequest(const char *url);

// const char *ssid = "Just_Wei";
// const char *password = "JustWei512";

const char *ssid = "Wokwi-GUEST"; // 您的WiFi网络名称
const char *password = "";        // 您的WiFi网络密码

String url = "http://ua.mojinyun.com/home/ip";

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
  delay(1000);
  //如果wifi连接成功,则每秒请求一次url,并在串口中打印返回的内容
  if (WiFi.status() == WL_CONNECTED)
  {
    String res = httpGetRequest(url.c_str());
    Serial.println(res);
    DynamicJsonDocument doc(1024);
    deserializeJson(doc, res);

    String ip = doc["Data"]["ip"];
    String country = doc["Data"]["country"];
    String province = doc["Data"]["province"];
    String city = doc["Data"]["city"];

    Serial.println("您的ip是:" + ip + "  来自:" + country + " " + province + " " + city);
  }
}

String httpGetRequest(const char *url)
{
  WiFiClient client;
  HTTPClient http;

  http.begin(client, url);

  // Send HTTP GET request
  int httpResponseCode = http.GET();

  String payload = "";

  if (httpResponseCode > 0)
  {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else
  {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpResponseCode).c_str());
  }
  // Free resources
  http.end();

  return payload;
}