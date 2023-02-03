#include "BK.h"
extern const short sheight;
void BK::Show()
{
	if (y == 0) { y = -sheight; }
	y += 4;
	putimage(0, y, &img);
}