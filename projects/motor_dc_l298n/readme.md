# 使用ESP32和L298N电机驱动器控制直流电机

## 材料:
- 开发板NodeMCU-32S(1个)
- 直流电机(1个)
- L298N电机驱动器(1个)
- 12V直流电源(1个)
- 连接线(若干)

## 连线
- 12V电源正级------L298N的 +12V
- 12V电源负级------L298N的 GND
- ESP32的 GPIO27------L298N的 IN1
- ESP32的 GPIO26------L298N的 IN2
- ESP32的 GPIO14------L298N的 ENA

## 编译程序
点击visual code 左下脚platformio状态条的√进行编译.

## 上传到ESP32
点击visual code 左下脚platformio状态条的→上传到ESP32.

## 运行效果
电机先全速正转2秒,然后停止1秒,再全速反转2秒,然后停止1秒,然后电机以递增的转速正转.
