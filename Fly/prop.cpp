#include"prop.h"
#include"api.h"
#include"var.h"
bool prop::Show()
{
	if (rect.top >= sheight)
	{

		return false;
	}
	rect.top += 3;
	rect.bottom += 3;

	transparentimage3(NULL, rect.left, rect.top, &img);
	return true;
}
RECT& prop::GetRect() { return rect; }
int prop::GetType() { return type; }