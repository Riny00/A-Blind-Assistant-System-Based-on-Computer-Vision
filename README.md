# 《基于计算机视觉的盲人辅助系统》

## 项目介绍

​	系统硬件部分由Jetson nano开发板、USB摄像头、HC05蓝牙模块、电源模块以及智能手机组成，软件部分由手机APP以及QT客户端组成，系统实现了实时位置定位、路线导航、语音唤醒、语音识别、目标检测与测距、语音播报、位置监测与路线绘制等功能。

## 开发环境

开发系统：Windows 10、阿里云Linux Ubuntu服务器

开发软件：Android studio 2022、Pycharm2022、Visual Studio2022



## 文件夹说明

APP文件夹为手机《语音导航助手APP》源码

Hardware文件夹为导盲仪源码包括yolov5、单目测距、TensorRt

Realtime_Monitoring文件夹为QT客户端《实时路线监测平台》源码

Server文件夹为LinuxC环境的服务端代码，用于部署在阿里云服务器上

## 系统架构

<img src="images\11.png" alt="11" style="zoom:50%;" />

## 系统部分功能截图

### 《语音导航助手APP》界面展示

<img src="images\location.png" style="zoom: 50%;" />



<img src="images\login.png" alt="login" style="zoom:50%;" />

<img src="images\wake-up.png" style="zoom:50%;" />

### 客户端界面展示

<img src="images\login2.png" style="zoom: 33%;" />

<img src="images\main.png" style="zoom: 50%;" />

### 硬件部分物体检测与测量距离

<img src="D:\Programmingtools\QT\code\images\detect.png" style="zoom: 80%;" />

### 项目小结

​	本毕业设计涉及多个领域方向如深度学习、三维重建、NVIDIA下高性能计算框架、通信技术、操作系统、人机交互等方面，需要对这些领域的原理和技术进行深入学习和应用。设计中需要将目标检测与测距算法进行结合，部署到硬件模块时需要进行推理加速，同时需要开发出手机端、服务端和客户端解决盲人用户的相应需求。综合来看，该毕业设计要求掌握多个领域的知识和技术，并进行系统的设计和实现。

### 项目特色

​	本设计结合了多种热门技术和方法，其中Jetson nano等硬件模块组成便携式导盲仪，具备识别速度快，准确度较高且续航时间长等特点。设计中还考虑到盲人的视力障碍问题，设计了一款语音导航助手APP，盲人可通过语音与APP进行交互，执行相应功能。而为了能更好守护盲人安全，家属可通过客户端查询盲人行走的数据，进而增强了盲人外出行走时的安全性。综合来看，该毕业设计结合了物联网技术和盲人用户的实际需求，具有一定的创新和实用性。