#include "SelfDriving.h"
#include <graphics.h>
#include "api.h"
//void SelfDriving(RECT& r, std::vector<EBullet*> EnemyBullet, std::vector<Enemy*> enemy) {
//	//抽象为六个区域
//	RECT R1, R2, M1, M2, L1, L2;
//	int height, width;
//	height = r.bottom - r.top;
//	width = r.right - r.left;
//	M2 = r;
//	M1 = r;
//	M1.bottom = r.top;
//	M1.top = M1.bottom - height;
//	
//	R2.left = r.right;
//	R2.right = R2.left + width;
//	R2.bottom = r.bottom;
//	R2.top = r.top;
//	
//	R1 = R2;
//	R1.bottom = R2.top;
//	R1.top = R1.bottom - height;
//
//	L2.bottom = r.bottom;
//	L2.top = r.top;
//	L2.right = r.left;
//	L2.left = L2.right - width;
//
//	L1 = L2;
//	L1.bottom = L2.top;
//	L1.top = L1.bottom - height;
//	
//
//}