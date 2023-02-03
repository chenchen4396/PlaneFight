#include "Enemy.h"
#include"api.h"
extern const short sheight;
bool Enemy::Show()
{

	if (isdie)
	{
		if (boomsum == 3)
		{
			return false;
		}
		//putimage(rect.left, rect.top, selfboom + boomsum);
		transparentimage3(NULL, rect.left, rect.top, selfboom+boomsum);//Í¸Ã÷png
		boomsum++;

		return true;
	}

	if (rect.top >= sheight)
	{
		return false;
	}
	rect.top += 4;
	rect.bottom += 4;
	//putimage(rect.left, rect.top, &img);
	transparentimage3(NULL, rect.left, rect.top, &img);//Í¸Ã÷png
	return true;
}
void Enemy::Isdie()
{
	isdie = true;
}
RECT& Enemy::GetRect() { 
	return rect; 
}