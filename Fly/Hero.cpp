#include"Hero.h"
#include"var.h"
#include "EBullet.h"
int count;
int left, right, mid;
void Hero::SelfDriving(std::vector<EBullet*> EnemyBullet, std::vector<Enemy*> enemy, BOSS& boss) {
	//抽象多个矩形区域
	RECT R1, R2, M1, M2, L1, L2;
	RECT R0, L0, M0;
	//rect.left = 0;
	//rect.right = rect.left + (rect.right - rect.left);
	int height, width;
	RECT r = rect;
	height = r.bottom - r.top;
	width = r.right - r.left;
	int speed = width/10;
	M2 = rect;
	M1 = M2;
	M1.bottom = M2.top;
	M1.top = M1.bottom - height;
	M0 = M1;
	M0.bottom = M1.top;
	M0.top = M1.top-5*height;
	

	R2.left = M2.right;
	R2.right = R2.left + width;
	R2.bottom = M2.bottom;
	R2.top = M1.top - height / 2;
	if (R2.right > swidth) {
		R2.right = swidth;
	}
	L2.right = M2.left;
	L2.left = L2.right - width;
	L2.bottom = M2.bottom;
	L2.top = M1.top-height/2;
	if (L2.left < 0) {
		L2.left = 0;
	}
	//R1 = R2;
	//R1.bottom = R2.top;
	//R1.top = R1.bottom - height;
	R0.left = M2.right;
	R0.right = swidth;
	R0.bottom = R2.top;
	R0.top = 0;

	//L1 = L2;
	//L1.bottom = L2.top;
	//L1.top = L1.bottom - height;
	L0.right = M2.left;
	L0.left = 0;
	L0.bottom = L2.top;
	L0.top = 0;
	left = 0;
	right = 0;
	mid = 0;
	/*
	躲避原则：
	一.当M1出现障碍物或者M0无敌机，进行移动，判断L2和R2是否存在子弹与飞机，存在情况如下：

​		1、L2和R2都不存在障碍物，则选择有敌机的一面进行移动以便于攻击；

​		2、L2和R2都存在障碍物，则不移动;

​		3、L2和R2某一边存在障碍物，则移动到不存在障碍物的一方;
	*/
		//监测敌机子弹
		auto EnemyBulletIter = EnemyBullet.begin();
		while (EnemyBulletIter != EnemyBullet.end())
		{
			//M0无障碍物或M1出现障碍物
			if ((RectDuangRect((*EnemyBulletIter)->GetRect(), M1) || !(RectDuangRect((*EnemyBulletIter)->GetRect(), M0)))) {
				////L2和R2都存在障碍物，则不移动;
				//if ((RectDuangRect((*EnemyBulletIter)->GetRect(), L2)) && (RectDuangRect((*EnemyBulletIter)->GetRect(), R2))) {
				//	left++;
				//	right++;
				//}
				////L2和R2某一边存在障碍物，则移动到不存在障碍物的一方;
				////L2存在障碍物，R2不存在
				//else if ((RectDuangRect((*EnemyBulletIter)->GetRect(), L2)) && !(RectDuangRect((*EnemyBulletIter)->GetRect(), R2))) {
				//	left++;
				//}
				////R2存在,L2不存在障碍物
				//else if (!(RectDuangRect((*EnemyBulletIter)->GetRect(), L2)) && (RectDuangRect((*EnemyBulletIter)->GetRect(), R2))) {
				//	right++;
				//}
				////L2和R2都不存在障碍物，则选择有敌机的一面进行移动以便于攻击；
				//else if (!(RectDuangRect((*EnemyBulletIter)->GetRect(), L2)) && !(RectDuangRect((*EnemyBulletIter)->GetRect(), R2))) {
				//	 
				//}
				if (RectDuangRect((*EnemyBulletIter)->GetRect(), L2)) {
					left++;
				}
				else if (RectDuangRect((*EnemyBulletIter)->GetRect(), R2)) {
					right++;
				}
			}
			EnemyBulletIter++;
		}
		//检测敌机
		auto EnemyIter = enemy.begin();
		while (EnemyIter != enemy.end())
		{
			//M0无障碍物或M1出现障碍物
			if ((RectDuangRect((*EnemyIter)->GetRect(), M1)) || !(RectDuangRect((*EnemyIter)->GetRect(), M0))) {
				////L2和R2都存在障碍物，则不移动;
				//if ((RectDuangRect((*EnemyIter)->GetRect(), L2)) && (RectDuangRect((*EnemyIter)->GetRect(), R2))) {
				//	left++;
				//	right++;
				//}
				////L2和R2某一边存在障碍物，则移动到不存在障碍物的一方;
				////L2存在障碍物，R2不存在
				//else if ((RectDuangRect((*EnemyIter)->GetRect(), L2)) && !(RectDuangRect((*EnemyIter)->GetRect(), R2))) {
				//	left++;
				//}
				////R2存在,L2不存在障碍物
				//else if (!(RectDuangRect((*EnemyIter)->GetRect(), L2)) && (RectDuangRect((*EnemyIter)->GetRect(), R2))) {
				//	right++;
				//}
				////L2和R2都不存在障碍物，则选择有敌机的一面进行移动以便于攻击；
				//else if (!(RectDuangRect((*EnemyIter)->GetRect(), L2)) && !(RectDuangRect((*EnemyIter)->GetRect(), R2))) {
				//}

				//哪一边出现障碍物则不可移动到那一边，最终移动的方向为 其值为0的方向
				if (RectDuangRect((*EnemyIter)->GetRect(), L2)) {
					left++;
				}
				else if (RectDuangRect((*EnemyIter)->GetRect(), R2)) {
					right++;
				}

			}
			EnemyIter++;
		}
		if (rect.left == 0) {
			left++;
		}
		else if (rect.right == swidth) {
			right++;
		}
		int lc = 0, rc = 0;
		count = 0;
		std::cout << "************************************************" << std::endl;
		printf_s("1——left:%d,right:%d\n", left, right);
		//左右两侧都无障碍物
		if (left == 0 && right == 0) {

			EnemyIter = enemy.begin();
			while (EnemyIter != enemy.end()) {
				if ((RectDuangRect((*EnemyIter)->GetRect(), L0))) {
					lc++;
				}
				else if ((RectDuangRect((*EnemyIter)->GetRect(), R0))) {
					rc++;
				}
				EnemyIter++; 
			}
			if (lc==0&&rc==0) {
				if ((RectDuangRect(boss.GetRect(), L0))) {
					lc++;
				}
				else if ((RectDuangRect(boss.GetRect(), R0))) {
					rc++;
				}
				printf_s("BOSS-HP:%d\n", boss.HP);
			}
			if (lc > rc)
				right++;
			else if (lc < rc)
				left++;
			else
				left++;
			printf_s("4——left:%d,right:%d\n", left, right);
			if (left == 0)
			{
				if (rect.left > 0) {
					rect.left -= (L2.right - L2.left);
					if (rect.left < 0) {
						rect.left = 0;
					}
					rect.right = rect.left + width;
				}
			}
			else if (right == 0) {
				if (rect.right < swidth) {
					rect.right += (R2.right - R2.left);
					if (rect.right > swidth) {
						rect.right = swidth;
					}
					rect.left = rect.right - width;
				}
			}
			return;
			
		}
		std::cout << "************************************************" << std::endl;
		if (left == 0)
		{
			if (rect.left > 0) {
				rect.left -= speed;
				if (rect.left < 0) {
					rect.left = 0;
				}
				rect.right = rect.left + width;
			}
		}
		else if (right == 0) {
			if (rect.right < swidth) {
				rect.right += speed;
				if (rect.right > swidth) {
					rect.right = swidth;
				}
				rect.left = rect.right - width;
			}
		}
		return;
	}



void Hero::Show()
{
	IMAGE life;
	loadimage(&life, _T("../images/life.png"));
	transparentimage3(NULL, rect.left, rect.top, &img);
	switch (HP) {
	case 1:
		transparentimage3(NULL, 0, sheight - life.getheight(), &life);
		break;
	case 2:
		transparentimage3(NULL, 0, sheight - life.getheight(), &life);
		transparentimage3(NULL, life.getwidth(), sheight - life.getheight(), &life);
		break;
	case 3:
		transparentimage3(NULL, 0, sheight - life.getheight(), &life);
		transparentimage3(NULL, life.getwidth(), sheight - life.getheight(), &life);
		transparentimage3(NULL, life.getwidth() * 2, sheight - life.getheight(), &life);
		break;
	case 4:
		transparentimage3(NULL, 0, sheight - life.getheight(), &life);
		transparentimage3(NULL, life.getwidth(), sheight - life.getheight(), &life);
		transparentimage3(NULL, life.getwidth() * 2, sheight - life.getheight(), &life);
		transparentimage3(NULL, life.getwidth() * 3, sheight - life.getheight(), &life);
		break;
	default:
		break;
	}


}
void Hero::Control()
{
	ExMessage mess;
	if (peekmessage(&mess, EM_MOUSE))
	{
		rect.left = mess.x - img.getwidth() / 2;
		rect.top = mess.y - img.getheight() / 2;
		rect.right = rect.left + img.getwidth();
		rect.bottom = rect.top + img.getheight();
	}
}
bool Hero::hurt()
{
	HP--;
	return (HP == 0) ? false : true;
}
void Hero::heal()
{
	if (HP < 4) {
		HP++;
	}
}
RECT& Hero::GetRect() { return rect; }