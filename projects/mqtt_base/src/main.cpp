#include <Arduino.h>
#include <WiFi.h>
// 参考: https://github.com/plapointe6/EspMQTTClient/blob/master/examples/SimpleMQTTClient/SimpleMQTTClient.ino
#include "EspMQTTClient.h"

const char *ssid = "your_ssid";
const char *password = "your_password";

const char *testTopic = "hello/world";

EspMQTTClient client(
    ssid,
    password,
    "192.168.0.8", // MQTT服务器的ip或域名,请确保在esp32连接的wifi网络中能够访问到该服务器
    "MQTTUsername",     // 如果不需要,可以省略
    "MQTTPassword",     // Can be omitted if not needed
    "TestClient"        // Client name that uniquely identify your device
);

unsigned long lastMillis = 0;

void setup()
{
  Serial.begin(115200);

  //设置最大包长度,默认128,如果太小了,会导致接收不到数据
  // see: https://github.com/plapointe6/EspMQTTClient/issues/1
  //      https://github.com/plapointe6/EspMQTTClient/issues/53
  client.setMaxPacketSize(5120);

  // EspMQTTClient 可选功能
  client.enableDebuggingMessages(); // 启用向串口输出调试信息
  // client.enableHTTPWebUpdater(); // Enable the web updater. User and password default to values of MQTTUsername and MQTTPassword. These can be overridded with enableHTTPWebUpdater("user", "password").
  // client.enableOTA(); // Enable OTA (Over The Air) updates. Password defaults to MQTTPassword. Port is the default OTA port. Can be overridden with enableOTA("password", port).
  // client.enableLastWillMessage(testTopic, "I am going offline");  // 您可以通过将第三个参数设置为true来激活retain标志
}

// 当wifi和mqtt连接成功后,会调用此函数一次.
// 如果您使用EspMQTTClient,您必须实现这个函数.
// 如果您想要在连接成功后执行一些操作,可以在此函数中实现.
void onConnectionEstablished()
{

  // 订阅一个主题,并从串口输出接收到的消息.
  client.subscribe(testTopic, [](const String &topic, const String &payload)
  { 
    Serial.println("(收到消息) topic: " + topic + ", payload: " + payload); 
  });

  // 往指定的主题上发送一条消息.
  client.publish(testTopic, "This is a message");
}

void loop()
{
  client.loop();
}