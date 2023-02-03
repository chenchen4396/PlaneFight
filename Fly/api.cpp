#include"api.h"
extern const short swidth;
extern const short sheight;
extern const unsigned int SHP;
extern const short hurttime;
extern short HeroLevel;
#pragma comment( lib, "MSIMG32.LIB")

//ȥ��ͼƬ������ɫ
void transparentimage3(IMAGE* dstimg, int x, int y, IMAGE* srcimg) //�°�png
{
    HDC dstDC = GetImageHDC(dstimg);
    HDC srcDC = GetImageHDC(srcimg);
    int w = srcimg->getwidth();
    int h = srcimg->getheight();
    BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
    AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
}
//CHAR TO TCHAR
void CharToTCHAR(const char* _char, TCHAR* tchar)
{
    int iLength;
    iLength = MultiByteToWideChar(CP_UTF8, 0, _char, strlen(_char) + 1, NULL, 0);
    MultiByteToWideChar(CP_UTF8, 0, _char, strlen(_char) + 1, tchar, iLength);

}
//����ж�
bool PointInRect(int x, int y, RECT& r)
{
    return (r.left <= x && x <= r.right && r.top <= y && y <= r.bottom);
}
//��ײ�ж�
bool RectDuangRect(RECT& r1, RECT& r2)
{
    RECT r;
    r.left = r1.left - (r2.right - r2.left);
    r.right = r1.right;
    r.top = r1.top - (r2.bottom - r2.top);
    r.bottom = r1.bottom;
    return (r.left < r2.left&& r2.left <= r.right && r.top <= r2.top && r2.top <= r.bottom);
}
//���а�
void ShowRank(RankList m_ranklist)
{
	//�����Ļ
	setbkcolor(WHITE);//���ñ���ɫ
	cleardevice();
	LPCTSTR back = _T("����");
	/*--------------���ƹ���----------*/
	settextstyle(60, 0, L"����");
	settextcolor(BLACK);
	outtextxy(160, 40, L"���а�");


	settextstyle(20, 0, L"����");
	outtextxy(22, 22, back);
	RECT backr;
	backr.left = 22;
	backr.right = 22 + textwidth(back);
	backr.top = 22;
	backr.bottom = 22 + textheight(back);

	/*---------------�������а���Ϣ---------------*/

	settextstyle(20, 0, L"����");
	outtextxy(140, 120, L"����");
	outtextxy(240, 120, L"����");
	outtextxy(340, 120, L"����");
	outtextxy(490, 120, L"����");

	std::vector<PlayerMsg> msg = m_ranklist.getRankList();
	for (int i = 0; i < msg.size(); ++i)
	{
		if (i == 0)
		{
			settextstyle(15, 0, L"����");
		}
		else
		{
			settextstyle(15, 0, L"����");
		}
		TCHAR t[40];
		_stprintf_s(t, _T("%d"), msg[i].id);
		outtextxy(145, 150 + 30 * i, t);

		CharToTCHAR(msg[i].name.c_str(), t);
		outtextxy(245, 150 + 30 * i, t);

		_stprintf_s(t, _T("%llu"), msg[i].score);
		outtextxy(345, 150 + 30 * i, t);

		CharToTCHAR(msg[i].r_time.c_str(), t);

		outtextxy(450, 150 + 30 * i, t);

	}
	while (true)
	{
		ExMessage mess;
		getmessage(&mess, EM_MOUSE);
		if (mess.lbutton)
		{
			if (PointInRect(mess.x, mess.y, backr))
			{
				return;
			}
		}
	}
}
// һ����ʼ����
void Welcome(RankList& m_ranklist)
{
	while (true) {

		

		LPCTSTR title = _T("�ɻ���ս");
		LPCTSTR tplay = _T("��ʼ��Ϸ");
		LPCTSTR Instruction = _T("����˵��");
		LPCTSTR trl = _T("���а�");
		LPCTSTR texit = _T("�˳���Ϸ");
		RECT tplayr, texitr, trlr, Instructionr;
		BeginBatchDraw();
		setbkcolor(WHITE);
		cleardevice();
		settextstyle(60, 0, _T("����"));
		settextcolor(BLACK);
		outtextxy(swidth / 2 - textwidth(title) / 2, sheight / 5, title);
		IMAGE bk;
		loadimage(&bk, _T("../images/karsa.png"));
		transparentimage3(NULL,-400,0,&bk);
		//putimage(0, 0, &bk);
		settextstyle(40, 0, _T("����"));
		tplayr.left = swidth / 2 - textwidth(tplay) / 2;
		tplayr.right = tplayr.left + textwidth(tplay);
		tplayr.top = sheight / 5 * 2.5;
		tplayr.bottom = tplayr.top + textheight(tplay);

		Instructionr.left = swidth / 2 - textwidth(Instruction) / 2;
		Instructionr.right = Instructionr.left + textwidth(Instruction);
		Instructionr.top = sheight / 5 * 3;
		Instructionr.bottom = Instructionr.top + textheight(Instruction);


		texitr.left = swidth / 2 - textwidth(texit) / 2;
		texitr.right = texitr.left + textwidth(texit);
		texitr.top = sheight / 5 * 4;
		texitr.bottom = texitr.top + textheight(texit);

		trlr.left = swidth / 2 - textwidth(trl) / 2;
		trlr.right = texitr.left + textwidth(trl);
		trlr.top = sheight / 5 * 3.5;
		trlr.bottom = texitr.top + textheight(trl);
		
		outtextxy(tplayr.left, tplayr.top, tplay);
		outtextxy(Instructionr.left, Instructionr.top, Instruction);
		outtextxy(trlr.left, trlr.top, trl);
		outtextxy(texitr.left, texitr.top, texit);

		EndBatchDraw();

		while (true)
		{
			ExMessage mess;
			getmessage(&mess, EM_MOUSE);
			if (mess.lbutton)
			{
				if (PointInRect(mess.x, mess.y, tplayr))
				{
					return;
				}
				else if (PointInRect(mess.x, mess.y, texitr))
				{
					exit(0);
				}
				else if (PointInRect(mess.x, mess.y, trlr))
				{
					ShowRank(m_ranklist);
					break;
				}
				else if (PointInRect(mess.x, mess.y, Instructionr)) {
					Instruction1();
					break;
				}
			}
		}
	}
}
//��������
int Over(unsigned long long& kill, RankList& m_ranklist)
{
	struct PlayerMsg m_msg;
	//printf_s("o");
	TCHAR* str = new TCHAR[128];
	_stprintf_s(str, 128, _T("��ɱ����%llu"), kill);
	m_msg.score = kill;
	settextcolor(RED);
	outtextxy(swidth / 2 - textwidth(str) / 2, sheight / 5, str);

	//�����¼�����Enter���أ�
	LPCTSTR info = _T("��Enter����");
	settextstyle(20, 0, _T("����"));
	outtextxy(swidth - textwidth(info), sheight - textheight(info), info);

	while (true) {
		if (_kbhit())
		{
			char v = _getch();
			//��ͣ����
			if (v == 0x0D) {
				Sleep(100);
				wchar_t s[128];
				std::string str;
				InputBox(s, 128, L"�������������,����Enterȷ��");
				DWORD dwNum = WideCharToMultiByte(CP_OEMCP, NULL, s, -1, NULL, 0, NULL, FALSE);
				char* psText;
				psText = new char[dwNum];
				WideCharToMultiByte(CP_OEMCP, NULL, s, -1, psText, dwNum, NULL, FALSE);
				str = psText;
				// ɾ����ʱ����
				delete[]psText;
				m_msg.name = str;
				m_ranklist.SaveMsg(m_msg);
				m_ranklist.SaveToRank();
				break;
			}
			
		}
	}
	
	IMAGE EndGame;
	IMAGE ReGame;
	loadimage(&EndGame, _T("../images/gameover.png"));
	loadimage(&ReGame, _T("../images/again.png"));
	transparentimage3(NULL, swidth / 2 - EndGame.getwidth() / 2, sheight / 2 - EndGame.getheight(), &EndGame);
	transparentimage3(NULL, swidth / 2 - ReGame.getwidth() / 2, sheight / 2 + EndGame.getheight(), &ReGame);
	RECT gameover;
	gameover.left = swidth / 2 - EndGame.getwidth();
	gameover.right = gameover.left + EndGame.getwidth();
	gameover.top = sheight / 2 - EndGame.getheight();
	gameover.bottom = gameover.top + EndGame.getheight();
	RECT regame;
	regame.left = swidth / 2 - ReGame.getwidth();
	regame.right = regame.left + ReGame.getwidth();
	regame.top = sheight / 2 + EndGame.getheight();
	regame.bottom = regame.top + ReGame.getheight();
	while (true) {
		ExMessage mess1;
		getmessage(&mess1, EM_MOUSE);
		if (mess1.lbutton)
		{
			if (PointInRect(mess1.x, mess1.y, regame))
			{
				return 1;
			}
			else if (PointInRect(mess1.x, mess1.y,gameover))
			{
				return 0;
			}
		}
	}
}
//���ӵл�
bool AddEnemy(std::vector<Enemy*>& enemy, IMAGE& enemyimg, IMAGE* boom)
{
	Enemy* e = new Enemy(enemyimg, abs(rand()) % (swidth - enemyimg.getwidth()), boom);
	for (auto& i : enemy)
	{
		if (RectDuangRect(i->GetRect(), e->GetRect()))
		{
			delete e;
			return false;
		}
	}
	enemy.push_back(e);
	return true;

}
void AddProp(std::vector<prop*>& Prop, IMAGE *Supply, int size) {
	int x = abs(rand()) % 3;
	prop* p = new prop(Supply[x], abs(rand()) % (swidth - Supply[x].getwidth()), x);
	Prop.push_back(p);
	return;
}

void Instruction1() {
	setbkcolor(WHITE);//���ñ���ɫ
	cleardevice();
	LPCTSTR t1 = _T("����ƶ����Ʒɻ�");
	LPCTSTR t2 = _T("����O�������˼�ʻ");
	LPCTSTR t3 = _T("����P�ر����˼�ʻ");
	LPCTSTR t4 = _T("�ո���ͣ");
	LPCTSTR back = _T("����");

	settextstyle(20, 0, _T("����"));
	settextcolor(BLACK);
	
	outtextxy(swidth / 2 - textwidth(t1) / 2, sheight / 5 * 2.5 , t1);
	outtextxy(swidth / 2 - textwidth(t2) / 2, sheight / 5 * 3 , t2);
	outtextxy(swidth / 2 - textwidth(t3) / 2, sheight / 5 * 3.5 , t3);
	outtextxy(swidth / 2 - textwidth(t4) / 2, sheight / 5 * 4, t4);
	outtextxy(22, 22, back);
	RECT backr;
	backr.left = 22;
	backr.right = 22 + textwidth(back);
	backr.top = 22;
	backr.bottom = 22 + textheight(back);
	
	while (true)
	{
		ExMessage mess;
		getmessage(&mess, EM_MOUSE);
		if (mess.lbutton)
		{
			if (PointInRect(mess.x, mess.y, backr))
			{
				return;
			}
		}
	}
	return;
}