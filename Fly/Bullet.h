#ifndef _BULLET_H
#define _BULLET_H

#include <iostream>
#include <graphics.h>
#include <vector>
#include <conio.h>

class Bullet
{
public:
	Bullet(IMAGE& img, RECT pr)
		:img(img)
	{
		rect.left = pr.left + (pr.right - pr.left) / 2 - img.getwidth() / 2;
		rect.right = rect.left + img.getwidth();
		rect.top = pr.top - img.getheight();
		rect.bottom = rect.top + img.getheight();
	}
	bool Show();
	RECT& GetRect();

protected:
	IMAGE& img;
	RECT rect;
};
#endif // !BULLET_H

