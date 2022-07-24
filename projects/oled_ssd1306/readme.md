#使用ESP32在SSD1306屏幕上显示动画

## 材料:
- 开发板NodeMCU-32S(1个)
- SSD1306屏幕(1个)
- 连接线(4根)

## 连线
- ESP32的 GPIO22------OLED屏幕的 SCL
- ESP32的 GPIO21------OLED屏幕的 SDA
- ESP32的 GND---------OLED屏幕的 GND
- ESP32的 3V3---------OLED屏幕的 VCC

## 编译程序
点击visual code 左下脚platformio状态条的√进行编译.

## 上传到ESP32
点击visual code 左下脚platformio状态条的→上传到ESP32.

## 运行效果
屏幕第一行显示一串静态文字.下方可以看到一个运动的小汽车.

在线仿真: https://wokwi.com/projects/337615937207272018
