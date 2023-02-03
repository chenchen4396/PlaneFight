
#ifndef _PROP_H
#define _PROP_H
#include <iostream>
#include <graphics.h>
#include <vector>
#include <conio.h>


class prop
{
public:
	prop(IMAGE& img, int x,int typ)
		:img(img)
	{
		rect.left = x;
		rect.right = rect.left + img.getwidth();
		rect.top = 0;
		rect.bottom = rect.top + img.getheight();
		type = typ;
	}
	bool Show();
	RECT& GetRect();
	int GetType();
private:
	IMAGE& img;
	RECT rect;
	int type; //0�����ܣ�1�����ӵ���2��������
};
#endif // 

