#pragma once
#ifndef RankList_H
#define RankList_H
#include <iostream>
#include <graphics.h>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#pragma once
#pragma warning(disable:4996)
struct PlayerMsg
{
	int id;
	unsigned long long score;
	std::string name;
	std::string r_time;	//¼ÇÂ¼Ê±¼ä

	PlayerMsg()
	{
		id = 99;
		score = 0;
		name = "";
		r_time = "";
	}
};

class RankList
{
private:
	std::vector<PlayerMsg> m_msg;
	const std::string m_rankfile = "retro";
	const int MAX_RANK = 10;
	void WriteTime(PlayerMsg& msg);
	void ReadFile();
	void WriteFile();
public:
	RankList();
	void SaveMsg(PlayerMsg& msg);
	std::vector<PlayerMsg> getRankList();
	void SaveToRank();


};
struct SortPlayerMsg
{
	bool operator()(const PlayerMsg& msg1, const PlayerMsg& msg2)
	{
		if (msg1.score == msg2.score)
		{
			return msg1.r_time > msg2.r_time;
		}
		else return msg1.score > msg2.score;
	}
};
#endif