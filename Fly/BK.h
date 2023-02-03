#ifndef BK_H
#define BK_H
#include <iostream>
#include <graphics.h>
#include <vector>
#include <conio.h>
extern const short sheight;

class BK
{
public:
	BK(IMAGE& img)
		:img(img), y(-sheight)
	{
	}
	void Show();
private:
	IMAGE& img;
	int y;

};


#endif
