# Plane_Fight
基于EASY_X的一个简单2D飞机射击游戏，可实现飞机的自动驾驶。



## PS：

EASY_X提供的捕获按键的函数总是有问题，所以不用，使用_kbhit()和_getch()来替代

## 2023/1/27

完成基本游戏实现

## 2023/1/29

### 增加

排行榜

## 2023/1/30

### 增加 

1、2、3Level下的射击子弹模式

## 2023/1/31

### 增加

Enemy子弹碰撞Hero后消失

Hero碰撞Enemy后会死亡

对局游戏结束后新增 重新开始和结束游戏两个功能

实现BOSS关卡

### 更改

血条改为了左下角小飞机来表示

将部分较多选项的if else改为了switch

### 删减

## 2023/2/1

### 增加

飞机自动驾驶（待完善）

实现功能道具：提升HeroLevel的道具、加血包

Boss移动

## 2023/2/2

### 增加

完善了飞机的自动驾驶，差强人意

实现了护盾道具，但是没有实现图片素材

增加了初始界面的背景

### 更改

更改了部分游戏参数

发现存在内存泄漏，通过VS自带的工具解决。

## TO DO

BOSS的特殊射击
