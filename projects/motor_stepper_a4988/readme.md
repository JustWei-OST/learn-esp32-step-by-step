# 使用ESP32和A4988模块控制42步进电机

## 材料:
- 开发板NodeMCU-32S(1个)
- 42步进电机(1个)
- A4988模块(1个)
- 12V直流电源(1个)
- 连接线(若干)

## 连线
- 12V电源正级------A4988模块 VMOT
- 12V电源负级------A4988模块 GND
- ESP32的 GPIO14------A4988模块 STEP
- ESP32的 GPIO12------A4988模块 DIR

## 请注意
A4988模块需要外接电源供电,否则无法正常工作.使用前需要调节电位器的电压范围.

1. A4988模块的VDD引脚需要连接+5V电压（可连接Arduino的+5V引脚）
2. A4988模块的GND引脚必须与电路中的其它设备共地（可连接Arduino的GND引脚）

参考: http://www.taichi-maker.com/homepage/reference-index/motor-reference-index/arduino-a4988-nema-stepper-motor/

## 编译程序
点击visual code 左下脚platformio状态条的√进行编译.

## 上传到ESP32
点击visual code 左下脚platformio状态条的→上传到ESP32.

## 运行效果
可以看到步进电机循环以不同的速度正反步进一定的角度.

在线仿真: https://wokwi.com/projects/338061044100366931