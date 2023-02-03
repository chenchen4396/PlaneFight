#ifndef API_H
#define API_H
#include <iostream>
#include <graphics.h>
#include <vector>
#include <conio.h>
#include "RankList.h"
#include "Enemy.h"
#include "prop.h"

//去除图片黑色背景
void transparentimage3(IMAGE* dstimg, int x, int y, IMAGE* srcimg);
//Char To TCHAR
void CharToTCHAR(const char* _char, TCHAR* tchar);
//点击判断
bool PointInRect(int x, int y, RECT& r);
//碰撞判断
bool RectDuangRect(RECT& r1, RECT& r2);
//展示排行榜
void ShowRank(RankList m_ranklist);
//首页
void Welcome(RankList& m_ranklist);
//结束界面
int Over(unsigned long long& kill, RankList& m_ranklist);
//增加敌机
bool AddEnemy(std::vector<Enemy*>& enemy, IMAGE& enemyimg, IMAGE* boom);
//增加道具
void AddProp(std::vector<prop*>& Prop, IMAGE* Supply, int size);
//操作说明
void Instruction1();
#endif
