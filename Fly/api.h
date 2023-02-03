#ifndef API_H
#define API_H
#include <iostream>
#include <graphics.h>
#include <vector>
#include <conio.h>
#include "RankList.h"
#include "Enemy.h"
#include "prop.h"

//ȥ��ͼƬ��ɫ����
void transparentimage3(IMAGE* dstimg, int x, int y, IMAGE* srcimg);
//Char To TCHAR
void CharToTCHAR(const char* _char, TCHAR* tchar);
//����ж�
bool PointInRect(int x, int y, RECT& r);
//��ײ�ж�
bool RectDuangRect(RECT& r1, RECT& r2);
//չʾ���а�
void ShowRank(RankList m_ranklist);
//��ҳ
void Welcome(RankList& m_ranklist);
//��������
int Over(unsigned long long& kill, RankList& m_ranklist);
//���ӵл�
bool AddEnemy(std::vector<Enemy*>& enemy, IMAGE& enemyimg, IMAGE* boom);
//���ӵ���
void AddProp(std::vector<prop*>& Prop, IMAGE* Supply, int size);
//����˵��
void Instruction1();
#endif
