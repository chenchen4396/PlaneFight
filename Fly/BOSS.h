#ifndef BOSS_H
#define BOSS_H
#include <iostream>
#include <graphics.h>
#include <vector>
#include <conio.h>
class BOSS
{
public:
	int HP;
	BOSS(IMAGE& img, int x,int BOSSHP,IMAGE* boom)
		:img(img), HP(BOSSHP)
	{
		selfboom[0] = boom[0];
		selfboom[1] = boom[1];
		selfboom[2] = boom[2];
		selfboom[3] = boom[3];
		rect.left = x;
		rect.right = rect.left + img.getwidth();
		rect.top = 0;
		rect.bottom = img.getheight();;
	}
	bool Show();
	RECT& GetRect();

private:
	IMAGE& img;
	RECT rect;
	IMAGE selfboom[4];
};
#endif

