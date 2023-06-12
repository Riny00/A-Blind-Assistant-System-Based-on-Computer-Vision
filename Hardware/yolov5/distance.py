import threading

import serial#导入串口通信库
from time import sleep

ser = serial.Serial()

foc = 110.0  # 镜头焦距
real_hight_person = 64.96  # 行人高度
real_hight_car = 57.08  # 轿车高度

Res=""

def port_open_recv():#对串口的参数进行配置
    ser.port='/dev/ttyUSB0'
    ser.baudrate=9600
    ser.bytesize=8
    ser.stopbits=1
    ser.parity="N"#奇偶校验位
    ser.open()
    if(ser.isOpen()):
        print("串口打开成功！")
    else:
        print("串口打开失败！")
#isOpen()函数来查看串口的开闭状态
def port_close():
    ser.close()
    if(ser.isOpen()):
        print("串口关闭失败！")
    else:
        print("串口关闭成功！")

def send(send_data):
    if(ser.isOpen()):
        ser.write(send_data.encode('utf-8'))#编码
        print("发送成功",send_data)
    else:
        print("发送失败！")

    sleep(2)

# 自定义函数，单目测距
def detect_distance_person(h):
    dis_inch = (real_hight_person * foc) / (h - 2)
    dis_cm = dis_inch * 2.54
    dis_cm = int(dis_cm)
    dis_m = dis_cm / 100


    if (dis_m < 0.5):
        info = '前方{}米出有行人，注意避让'.format(dis_m)
        send(info)
    return dis_m


def detect_distance_car(h):
    dis_inch = (real_hight_car * foc) / (h - 2)
    dis_cm = dis_inch * 2.54
    dis_cm = int(dis_cm)
    dis_m = dis_cm / 100

    if (dis_m < 1):
        info = '前方{}米出有小汽车，注意避让'.format(dis_m)
        send(info)
    return dis_m


def detect_distance_object(name, h):
    if (name == 'person'):
        dis_m = detect_distance_person(h)
    if (name == 'red_light'):
        send('前方红灯，请等待')
    if (name == 'green_light'):
        send('前方绿灯，请通行')
    if (name == 'car'):
        dis_m = detect_distance_car(h)

    return dis_m


class MyThread(threading.Thread):
    # 开启子线程时,会自动执行run函数
    def __init__(self):
        super().__init__()
        self.ser = serial.Serial()

        self.port_open_recv()
        self.send("连接导盲设备成功,")

    def port_open_recv(self):  # 对串口的参数进行配置
        self.ser.port = '/dev/ttyUSB0'
        self.ser.baudrate = 9600
        self.ser.bytesize = 8
        self.ser.stopbits = 1
        self.ser.parity = "N"  # 奇偶校验位
        self.ser.open()
        self.res=""
        if (self.ser.isOpen()):
            print("串口打开成功！")
        else:
            print("串口打开失败！")

    def send(self,send_data):
        if (self.ser.isOpen()):
            self.ser.write(send_data.encode('utf-8'))  # 编码
            print("发送成功")
        else:
            print("发送失败！")

    def chagevalue(self,info):
        self.res=info
        return self.res

    def __del__(self):
        self.ser.close()
        if (self.ser.isOpen()):
            print("串口关闭失败！")
        else:
            print("串口关闭成功！")

    def run(self):
        # 模拟耗时操作，获取数据
        i=0
        while(i<10):
            sleep(2)
            # str=""
            # i=i+1
            # str=Res+format(i)
            # send_info=self.chagevalue(str)
            self.send(Res)


if __name__ =='__main__':
    t=MyThread()
    t.start()
    i=0
    while (1):

        i = i + 1
        Res = "距离" + format(i)


    t.join()