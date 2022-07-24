#include <Arduino.h>

// 电机引脚定义
int motor1Pin1 = 27;
int motor1Pin2 = 26;
int enable1Pin = 14;

// 设置PWM参数
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 200;

void setup()
{
  // 将引脚设置为输出:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);

  // 配置LED PWM功能
  ledcSetup(pwmChannel, freq, resolution);
  // 将该通道连接到要控制的GPIO
  ledcAttachPin(enable1Pin, pwmChannel);

  Serial.begin(115200);

  Serial.print("Testing DC Motor...");
}

void loop()
{
  // 电机最大速度正转
  Serial.println("Moving Forward");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  delay(2000);

  // 电机停止
  Serial.println("Motor stopped");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  delay(1000);

  // 电机最大速度反转
  Serial.println("Moving Backwards");
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  delay(2000);

  // 电机停止
  Serial.println("Motor stopped");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  delay(1000);

  // 电机以递增速度正转
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  while (dutyCycle <= 255)
  {
    ledcWrite(pwmChannel, dutyCycle);
    Serial.print("Forward with duty cycle: ");
    Serial.println(dutyCycle);
    dutyCycle = dutyCycle + 5;
    delay(500);
  }
  dutyCycle = 200;
}