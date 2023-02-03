#pragma once
//Circle_queue 头文件名
#ifndef HERO_H //就是头文件名（全大写后加个_H
#define HERO_H
#include <iostream>
#include <graphics.h>
#include <vector>
#include <conio.h>
#include"api.h"
#include"EBullet.h"
#include"BOSS.h"
extern const short SHP;
extern const short swidth;
extern const short sheight;
class Hero
{
public:
	Hero(IMAGE& img)
		:img(img), HP(SHP)
	{
		rect.left = swidth / 2 - img.getwidth() / 2;
		rect.top = sheight - img.getheight();
		rect.right = rect.left + img.getwidth();
		rect.bottom = sheight;
	}
	void Show();
	void Control();
	bool hurt();
	void SelfDriving(std::vector<EBullet*> EnemyBullet, std::vector<Enemy*> enemy, BOSS& boss);
	void heal();
	RECT& GetRect();

private:
	IMAGE& img;
	RECT rect;

	unsigned int HP;

};

#endif
