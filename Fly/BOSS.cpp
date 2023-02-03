#include "BOSS.h"
#include"api.h"
#include"var.h"
extern const short sheight;
bool BOSS::Show()
{
	//不同HP的展示
	if (HP >= 60) {
		transparentimage3(NULL, rect.left, rect.top, &img);
	}
	else if (HP >= 35) {
		transparentimage3(NULL, rect.left, rect.top, selfboom + 1);
	}
	else if (HP > 0) {
		transparentimage3(NULL, rect.left, rect.top, selfboom + 2);
	}
	else if (HP <= 0) {
		transparentimage3(NULL, rect.left, rect.top, selfboom + 3);
		return false;
	}

	int x = (rand() % 19) - 9;
	while (rect.left + x < 0 || rect.right+x> swidth) {
		x = (rand() % 19) -9;
	}

	rect.left = rect.left + x;
	rect.right = rect.left + img.getwidth();
	
	x = (rand() % 19) - 9;
	while (rect.top + x < 0 || rect.bottom+x>sheight/2) {
		x = (rand() % 19) - 9;
	}

	
	rect.top = rect.top + x;
	rect.bottom = rect.top + img.getheight();

	//血条
	setlinecolor(RED);
	setlinestyle(PS_SOLID, 4);
	line(rect.left, rect.bottom - 3, rect.left + (img.getwidth()*(static_cast<double> (HP)/ static_cast<double>(BOSSHP))), rect.bottom - 3);
	return true;
}
RECT& BOSS::GetRect() {
	return rect;
}