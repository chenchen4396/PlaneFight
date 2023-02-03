#include"EBullet.h"
extern const short sheight;
const int EBulletSpeed = 6;
bool EBullet::Show()
{
	if (rect.top >= sheight)
	{

		return false;
	}
	rect.top += EBulletSpeed;
	rect.bottom += EBulletSpeed;
	putimage(rect.left, rect.top, &img);

	return true;
}