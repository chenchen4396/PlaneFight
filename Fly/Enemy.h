#pragma once
#ifndef ENEMY_H
#define	ENEMY_H
#include <iostream>
#include <graphics.h>
#include <vector>
#include <conio.h>
class Enemy
{
public:
	Enemy(IMAGE& img, int x, IMAGE*& boom)
		:img(img), isdie(false), boomsum(0)
	{
		selfboom[0] = boom[0];
		selfboom[1] = boom[1];
		selfboom[2] = boom[2];
		rect.left = x;
		rect.right = rect.left + img.getwidth();
		rect.top = -img.getheight();
		rect.bottom = 0;
	}
	bool Show();
	void Isdie();
	RECT& GetRect();

private:
	IMAGE& img;
	RECT rect;
	IMAGE selfboom[3];
	bool isdie;
	int boomsum;
};

#endif 


