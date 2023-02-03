// �ɻ���ս
// EasyX
#include <iostream>
#include <graphics.h>
#include <vector>
#include <conio.h>
#include<mmsystem.h>            //����������Ҫ��ͷ�ļ�
#pragma comment(lib,"WINMM.LIB")
#include"Hero.h"
#include"BK.h"
#include"Enemy.h"
#include"EBullet.h"
#include"RankList.h"
#include"api.h"
#include"BOSS.h"

extern const short BOSSHP;
extern const short swidth;
extern const short sheight;
extern const short SHP;
extern const short hurttime;
extern short HeroLevel;
extern const short EnemyNum;
using namespace std;

bool Play(RankList& m_ranklist)
{
	//����ѭ�������������ڽ���ʱʹ��������Ϸ��ѡ��
	int over = 1;
	//BGM
	//mciSendString(L"open ../music/jay_music1.mp3 alias music", 0, 0, 0);
	//mciSendString(L"play music ", NULL, 0, NULL);
	while (over) {
		bool is_play = true;
		setbkcolor(WHITE);
		cleardevice();
		//����һЩͼƬ��Դ
		IMAGE heroimg, enemyimg, bkimg, bulletimg,HeroBulletImg;
		loadimage(&heroimg, _T("../images/life.png"));
		loadimage(&enemyimg, _T("../images/enemy1.png"));
		loadimage(&bkimg, _T("../images/bk2.png"), swidth, sheight * 2);
		loadimage(&bulletimg, _T("../images/bullet1.png"));
		loadimage(&HeroBulletImg, _T("../images/bullet2.png"));
		IMAGE eboom[3];
		loadimage(&eboom[0], _T("../images/enemy1_down2.png"));
		loadimage(&eboom[1], _T("../images/enemy1_down3.png"));
		loadimage(&eboom[2], _T("../images/enemy1_down4.png"));
		IMAGE BossImg;
		loadimage(&BossImg, _T("../images/enemy3_hit.png"));
		IMAGE BossBoom[4];
		loadimage(&BossBoom[0], _T("../images/enemy3_down1.png"));
		loadimage(&BossBoom[1], _T("../images/enemy3_down2.png"));
		loadimage(&BossBoom[2], _T("../images/enemy3_down4.png"));
		loadimage(&BossBoom[3], _T("../images/enemy3_down5.png"));
		IMAGE Supply[3];
		loadimage(&Supply[1], _T("../images/bullet_supply.png"));
		loadimage(&Supply[0], _T("../images/shield_supply.png"));
		loadimage(&Supply[2], _T("../images/life_supply.png"));
		//KILL��Ļ
		TCHAR* str1 = new TCHAR[128];
		//����
		BK bk = BK(bkimg);
		//Hero
		Hero hp = Hero(heroimg);
		//�л�
		vector<Enemy*> enemy;
		//Hero�ӵ�
		vector<Bullet*> HerorBullet;
		//�л��ӵ�
		vector<EBullet*> EnemyBullet;
		//BOSS
		//vector<BOSS*> Boss;
		BOSS Boss = BOSS(BossImg, (swidth / 2 - BossImg.getwidth() / 2), BOSSHP, BossBoom);
		//����
		vector<prop*> Prop;
		//�˺�ʱ����
		clock_t hurtlast = clock();
		clock_t propstart = clock();
		clock_t proplast;
		clock_t shieldstart=clock();
		clock_t shieldend;
		unsigned long long kill = 0;
		int bsing = 0;
		HeroLevel = 1;
		bool BOSSlive = false;
		//�Զ���ʻ
		bool autofly = false;
		int shield = -1;
		while (is_play)
		{
			//�޵л���ʱ���ж�
			shieldend = clock();
			if ((shieldend - shieldstart) / CLOCKS_PER_SEC > 5) {
				shield = 0;
			}
			else if(shield==0) {
				shield = 1;
			}
			bsing++;
			//����Hero�ӵ�
			if (bsing % 10 == 0)
			{
				if (BOSSlive) {
					EnemyBullet.push_back(new EBullet(bulletimg, Boss.GetRect()));
				}
				//��ͬHeroLevel�µ��ӵ����ģʽ
				RECT RBulletRect = hp.GetRect();
				RECT LBulletRect = hp.GetRect();
				switch (HeroLevel)
				{
				case 1:
					HerorBullet.push_back(new Bullet(HeroBulletImg, hp.GetRect()));
					break;
				case 2:
					//�����ӵ�
					RBulletRect = hp.GetRect();
					RBulletRect.left += (RBulletRect.right - RBulletRect.left) / 2;
					RBulletRect.top += 20;
					HerorBullet.push_back(new Bullet(HeroBulletImg, RBulletRect));
					//�����ӵ�
					LBulletRect = hp.GetRect();
					LBulletRect.left -= (LBulletRect.right - LBulletRect.left) / 2;
					LBulletRect.top += 20;
					HerorBullet.push_back(new Bullet(HeroBulletImg, LBulletRect));
					break;
				case 3:
					//�����ӵ�
					RBulletRect = hp.GetRect();
					RBulletRect.left += (RBulletRect.right - RBulletRect.left) / 2;
					RBulletRect.top += 40;
					HerorBullet.push_back(new Bullet(HeroBulletImg, RBulletRect));
					//�м��ӵ�
					HerorBullet.push_back(new Bullet(HeroBulletImg, hp.GetRect()));
					//�����ӵ�
					LBulletRect = hp.GetRect();
					LBulletRect.left -= (LBulletRect.right-LBulletRect.left)/2;
					LBulletRect.top += 40;
					HerorBullet.push_back(new Bullet(HeroBulletImg, LBulletRect));
				default:
					break;
				}

			}
			//����Enemy�ӵ�
			if (bsing == 40)
			{
				bsing = 0;
				for (auto& i : enemy)
				{
					EnemyBullet.push_back(new EBullet(bulletimg, i->GetRect()));
				}
				//������ʽ

			}
			BeginBatchDraw();
			bk.Show();
			Sleep(2);
			//������ʽѡ��
			if (autofly) {
				hp.SelfDriving(EnemyBullet, enemy, Boss);
			}
			else {
				hp.Control();
			}
			flushmessage(EX_MOUSE);

			//��Ϸ�Ծ��еİ�������
			if (_kbhit())
			{
				char v = _getch();
				//��ͣ����
				if (v == 0x20)
				{
					Sleep(500);
					while (true)
					{
						if (_kbhit())
						{
							v = _getch();
							if (v == 0x20)
							{
								break;
							}
						}
						Sleep(16);
					}
				}
				//O�����Զ���ʻ
				if (v == 0x4F) {
					autofly = true;
				}
				//P�ر��Զ���ʻ
				if (v == 0x50) {
					autofly = false;
				}
			}

			//����HeroBullet.Show
			auto HeroBulletIter = HerorBullet.begin();
			while (HeroBulletIter != HerorBullet.end())
			{
				if (!(*HeroBulletIter)->Show())
				{
					delete (*HeroBulletIter);
					HeroBulletIter = HerorBullet.erase(HeroBulletIter);
				}
				else
				{
					HeroBulletIter++;
				}
			}

			//EnemyBullet��ײHero����
			auto EnemyBulletIter = EnemyBullet.begin();
			while (EnemyBulletIter != EnemyBullet.end())
			{
				if (!(*EnemyBulletIter)->Show())
				{
					delete (*EnemyBulletIter);
					EnemyBulletIter = EnemyBullet.erase(EnemyBulletIter);
				}
				//Enemy�ӵ���ײHero����ʧ
				else if (RectDuangRect((*EnemyBulletIter)->GetRect(), hp.GetRect())) {
					if (shield <= 0 && clock() - hurtlast >= hurttime)
					{
						is_play = hp.hurt();
						hurtlast = clock();
					}
					EnemyBulletIter = EnemyBullet.erase(EnemyBulletIter);
				}
				else
				{
					EnemyBulletIter++;
				}

			}

			//����Enemy
			auto EnemyIter = enemy.begin();
			while (EnemyIter != enemy.end())
			{
				//Enemy��Hero��ײ
				if (shield<=0 && RectDuangRect((*EnemyIter)->GetRect(), hp.GetRect())) {
					if (clock() - hurtlast >= hurttime) {
						is_play = hp.hurt();
						hurtlast = clock();
					}
					(*EnemyIter)->Isdie();
				}
				//HeroBullet��Enemy��ײ
				auto HeroBulletIter = HerorBullet.begin();
				while (HeroBulletIter != HerorBullet.end())
				{
					if (RectDuangRect((*HeroBulletIter)->GetRect(), (*EnemyIter)->GetRect()))
					{
						(*EnemyIter)->Isdie();
						delete (*HeroBulletIter);
						HerorBullet.erase(HeroBulletIter);
						kill++;
						break;
					}
					HeroBulletIter++;
				}
				//Enemy���
				if (!(*EnemyIter)->Show())
				{
					delete (*EnemyIter);
					enemy.erase(EnemyIter);
					EnemyIter = enemy.begin();
				}
				else {
					EnemyIter++;
				}

			}
			//BOSS
			if (BOSSlive) {
				Boss.Show();
				auto HeroBulletIter = HerorBullet.begin();
				while (HeroBulletIter != HerorBullet.end())
				{
					if (RectDuangRect((*HeroBulletIter)->GetRect(), Boss.GetRect()))
					{
						Boss.HP--;
						delete (*HeroBulletIter);
						HeroBulletIter=HerorBullet.erase(HeroBulletIter);
					}
					else {
						HeroBulletIter++;
					}
					
				}
				if (Boss.HP < 0) {
					kill++;
					BOSSlive = false;
					AddProp(Prop, Supply,3);
				}
			}
			//����
			proplast = clock();
			if ((proplast - propstart) / CLOCKS_PER_SEC > 5) {
				AddProp(Prop, Supply,3);
				propstart = clock();
			}
			auto PropIter = Prop.begin();
			while (PropIter != Prop.end())
			{
				if (!(*PropIter)->Show())
				{
					delete (*PropIter);
					Prop.erase(PropIter);
					PropIter = Prop.begin();
				}

				//prop��Hero��ײ
				else if (RectDuangRect((*PropIter)->GetRect(), hp.GetRect()) ){
					if ((*PropIter)->GetType() == 0)
					{
						shieldstart = clock();
					}
					else if ((*PropIter)->GetType() == 1 && HeroLevel < 3)
					{
						HeroLevel++;
					}
					else if ((*PropIter)->GetType() == 2)
					{
						hp.heal();
					}
					delete (*PropIter);
					Prop.erase(PropIter);
					break;
				}
				else {
					PropIter++;
				}
				

			}
			
			//��kill����һ������ʱ����BOSS������BOSSʱ��������ͨEnemy
			if (kill % 200 == 0 && kill>0) {
				BOSSlive = true;
				Boss.HP = BOSSHP;
				
			}
			else if(!BOSSlive){
				for (int i = 0; i < EnemyNum - enemy.size(); i++)
				{
					AddEnemy(enemy, enemyimg, eboom);
				}
			}
			hp.Show();//���������Ϊ������overʱ��hp��״̬�����µ�����



			settextstyle(20, 0, _T("����"));
			_stprintf_s(str1, 128, _T("��ɱ����%llu"), kill);
			outtextxy(0, 0, str1);
			if (shield > 0) {
				outtextxy(swidth / 2, 0, _T("�޵�"));
			}
			EndBatchDraw();
			if (BOSSlive) {
				printf_s("BOSSLIVE\n");
			}
			
		}
		over=Over(kill, m_ranklist);
		
	}
	//mciSendString(L"close music", 0, 0, 0);
	return true;
}

int main()
{
	// easy_x�ĳ�ʼ��
	initgraph(swidth, sheight, EW_NOMINIMIZE | EW_SHOWCONSOLE);
	//mciSendString(L"open ../music/jay_music1.mp3 alias music", 0, 0, 0);
	//mciSendString(L"play music repeat", NULL, 0, NULL);
	bool is_live = true;
	while (is_live)
	{

		RankList m_ranklist;
		Welcome(m_ranklist);
		// Play
		is_live = Play(m_ranklist);
	}
	//mciSendString(L"close music", 0, 0, 0);
	return 0;
}