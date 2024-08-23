
# CURI Robot 头部使用指南
头部硬件: FLIR PTU-E46云台，Orbbec Gemini 2相机

## Keypoint
本repo来源于[https://github.com/jus1ka/OculusMonitor](https://github.com/jus1ka/OculusMonitor)，利用OculusMonitor和串口通信方式实现CURI头部遥操

## 先决条件

- **软件与硬件要求**:
  - Windows 10
  - Visual Studio 2022 (Windows SDK10.0, boost1.83.0)
  - Oculus Quest 2
  - Meta Quest Link
  - OrbbecViewer

- 请先查看 **PTU-46 使用说明书** 并测试云台是否正常工作。正常工作则进入下一步。
  - 通过串口线正确连接云台和主机
  - 打开云台控制器开关，云台将自动进行自标定
  - 下载并打开 `Tera Term`串口控制软件
  - 输入指令:
   `PP2500`然后按回车，可以观察到云台平转。再输入:
   `PP0`然后按回车，云台将回到原位。
   `TP900`然后按回车，云台将俯仰转动。再输入
   `TP0`然后按回车，云台将回到原位。
  - 输入指令:
   `PS1500`然后按回车，再输入:
   `TS1500`然后按回车。这样设置横纵速度为 1500   position/second。
  - 以上指令都通过，说明串口通讯无误，关闭Tera Term


## Teleoperation Implementation

1. . 打开 `Visual Studio 2022`，克隆存储库，输入网址: [https://github.com/Zixin-Tang/CURI-Head-Teleoperation.git](https://github.com/Zixin-Tang/CURI-Head-Teleoperation.git),克隆到本地.
2. 在项目文件夹，`.vcxproc`文件可以查看项目配置，双击`.sln`文件可以进入项目预备运行界面。
3. 在VS菜单栏点击项目-属性，完成以下配置
+ `常规` 选择Windows SDK为安装版本 （推荐10.0，已测试），选择平台工具集为Visual Studio2022
+ `VC++目录` 包含目录中添加boost的安装路径，如C:\boost_1_83_0
4. 点击本地Windows调试器运行程序，可以看到，“Fail to create the session”，关闭即可，因为此时Oculus还没有和电脑配对。

5. 在Windows上安装Meta Quest Link软件，并和Oculus头戴设备使用 `Air link` 与进行配对，配对成功后即可进入白色空间，控制器点击下方桌面，可显示电脑画面。

6. 从 [Orbbec开发者中心](https://vcp.developer.orbbec.com.cn/resourceCenter) 下载并解压 OrbbecViewer。安装完成后，连接机器人头部相机，并打开 `OrbbecViewer` 测试是否成功连接相机。


5. 一切准备就绪后，带上 VR，从 VR 中用控制器点击电脑桌面上 VS 的执行按钮。稍等片刻，CURI 头部即可与您的头部一起运动，并可以用控制器打开电脑的 `OrbbecViewer`，显示 CURI 观察的画面。

