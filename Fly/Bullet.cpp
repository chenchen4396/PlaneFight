#include "Bullet.h"

bool Bullet::Show()
{
	if (rect.bottom <= 0)
	{

		return false;
	}
	rect.top -= 3;
	rect.bottom -= 3;

	putimage(rect.left, rect.top, &img);
	return true;
}
RECT& Bullet::GetRect() { return rect; }