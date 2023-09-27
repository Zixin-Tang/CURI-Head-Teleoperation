
# CURI Robot 头部使用指南

## 先决条件

- **软件与硬件要求**:
  - Windows 10
  - Visual Studio 2022
  - ZED SDK 4.0
  - Oculus
  - Quest 2

- 请先查看 **PTU-46 使用说明书** 并测试云台是否正常工作。正常工作则进入下一步。

## 操作步骤

1. 打开 `Tera Term`，选择对应串口后，输入指令:
   ```
   PS1500
   ```
   然后按回车，再输入:
   ```
   TS1500
   ```
   然后按回车。这样设置横纵速度为 1500 position/second。

2. 打开 `Visual Studio 2022`，克隆存储库，输入网址: [https://github.com/bril-user/OculusMonitor.git](https://github.com/bril-user/OculusMonitor.git)。克隆到本地后执行即可，可以发现打开一个窗口但显示“Fail to create the session”，并关闭。

3. 从 [ZED SDK 4.0 官方下载页面](https://www.stereolabs.com/developers/release/) 下载并安装 ZED SDK 4.0。安装完成后，连接机器人头部相机，并打开 `ZED Explorer` 测试是否成功连接相机。

4. 从 [Oculus 官方下载页面](https://www.oculus.com/Setup/?locale=zh_CN) 下载并安装 Oculus。开启 `Quest 2`，密码为 `M`。使用 `Air link` 与电脑进行配对，配对成功后即可进入白色空间，控制器点击下方桌面，可显示电脑画面。

5. 一切准备就绪后，带上 VR，从 VR 中用控制器点击电脑桌面上 VS 的执行按钮。稍等片刻，CURI 头部即可与您的头部一起运动，并可以用控制器打开电脑的 `ZED Explorer`，显示 CURI 观察的画面。

## 备注

若想调整坐标，比如想令侧面为初始界面，重启 VR 即可。您所见即 CURI 所得。


---


# CURI Robot Head Usage Guide

## Prerequisites

- **Software & Hardware Requirements**:
  - Windows 10
  - Visual Studio 2022
  - ZED SDK 4.0
  - Oculus
  - Quest 2

- Please first refer to the **PTU-46 User Manual** and test if the gimbal works properly. If it works, proceed to the next step.

## Operation Steps

1. Open `Tera Term`, select the corresponding port and enter the command:
   ```
   PS1500
   ```
   Press Enter, then enter:
   ```
   TS1500
   ```
   and press Enter. This sets the horizontal and vertical speed to 1500 positions/second.

2. Open `Visual Studio 2022`, clone the repository using the URL: [https://github.com/bril-user/OculusMonitor.git](https://github.com/bril-user/OculusMonitor.git). After cloning, execute and you may see a window indicating “Fail to create the session”, which then closes.

3. Download and install ZED SDK 4.0 from the [ZED SDK 4.0 official download page](https://www.stereolabs.com/developers/release/). Once installed, connect the robot head camera and open `ZED Explorer` to test if the camera connects successfully.

4. Download and install Oculus from the [Oculus official download page](https://www.oculus.com/Setup/?locale=zh_CN). Turn on `Quest 2`, password is `M`. Use `Air link` to pair with your computer. Once paired, you will enter a white space; use the controller to click on the desktop below to display the computer screen.

5. Once everything is ready, wear the VR headset. From within VR, use the controller to click on the execute button on the computer's desktop in VS. Wait for a moment, and the CURI robot head will move in sync with your head. You can also use the controller to open the computer's `ZED Explorer` to display what CURI sees.

## Note

If you want to adjust the coordinates, for example, you want the side to be the initial interface, just restart the VR. What you see is what CURI sees.
