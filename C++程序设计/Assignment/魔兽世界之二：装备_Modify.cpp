//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*

描述

魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。

红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。

双方的武士编号都是从1开始计算。红方制造出来的第n个武士，编号就是n。同样，蓝方制造出来的第n个武士，编号也是n。

武士在刚降生的时候有一个生命值。

在每个整点，双方的司令部中各有一个武士降生。

红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。

蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。

制造武士需要生命元。

制造一个初始生命值为m的武士，司令部中的生命元就要减少m个。

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。

给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。

一共有两种事件，其对应的输出样例如下：

1) 武士降生

输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter

表示在4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5，降生后蓝魔司令部里共有2个lion武士。（为简单起见，不考虑单词的复数形式）注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。

2) 司令部停止制造武士

输出样例： 010 red headquarter stops making warriors

表示在10点整，红方司令部停止制造武士

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入

第一行是一个整数，代表测试数据组数。

每组测试数据共两行。

第一行：一个整数M。其含义为， 每个司令部一开始都有M个生命元( 1 <= M <= 10000)。

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000。

输出

对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。

对每组测试数据，首先输出"Case:n" n是测试数据的编号，从1开始 。

接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。

样例输入

1
20
3 4 5 6 7
样例输出

Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
000 blue lion 1 born with strength 6,1 lion in blue headquarter
001 red lion 2 born with strength 6,1 lion in red headquarter
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
004 blue headquarter stops making warriors

*/

// 输出时间的方式可以是: cout << setfill('0') << setw(3) << time

#include <iostream>
#include <iomanip>
using namespace std;
const int WARRIOR_NUM = 5;
const int WEAPON_NUM = 3;
/*
char * Warrior::product_s[WARRIOR_NUM] = { "dragon","ninja","iceman","lion","wolf" };
红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序制造武士。
蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序制造武士。
*/

class Headquarter;
class Warrior
{
private:
	Headquarter * pHeadquarter;
	int kindNo;										//武士的种类编号 0 dragon 1 ninja 2 iceman 3 lion 4 wolf
	int no;
	int weaponNum;									// 拥有武器的数量
	int weaponNo[2];								// 武器编号
	double morale;									// 士气
	int loyalty;									// 忠诚度
public:
	static char * product_s[WARRIOR_NUM];
	static char * weapon_list[WEAPON_NUM];
	static int initialLifeValue[WARRIOR_NUM];
	Warrior(Headquarter * p, int no_, int kindNo_);
	void PrintResult(int nTime);
	void PrintInfo(void);
};

class Headquarter
{
private:
	int totalLifeValue;
	bool stopped;
	int totalWarriorNum;
	int Color_C;
	int curMakingSeqIdx; //当前要制造的武士是制造序列中的第几个
	int warriorNum[WARRIOR_NUM]; //存放每种武士的数量
	Warrior * pWarriors[1000];
public:
	friend class Warrior;
	static int makingSeq[2][WARRIOR_NUM]; //武士的制作顺序序列
	void Init(int color_, int lifevalue_);
	~Headquarter();
	int Produce(int nTime);
	char * GetColor();
	static char * color[2];
};

Warrior::Warrior(Headquarter * p, int no_, int kindNo_)
{
	no = no_;
	kindNo = kindNo_;
	pHeadquarter = p;

	if (kindNo != 3 && kindNo != 4)
	{
		if (kindNo == 1)
			weaponNum = 2;
		else
			weaponNum = 1;
	}
	else
		weaponNum = 0;
	for (int i = 0; i < weaponNum; i++)
		weaponNo[i] = (no + i) % 3;

	morale = (kindNo == 0) ? ((double)p->totalLifeValue / initialLifeValue[0]) : 0;
	loyalty = (kindNo == 3) ? (p->totalLifeValue) : 0;
}

void Warrior::PrintResult(int nTime)
{
	cout << setfill('0') << setw(3) << nTime << " ";
	cout << pHeadquarter->GetColor() << " " << product_s[kindNo] << " " << no;
	cout << " born with strength " << initialLifeValue[kindNo] << ",";
	cout << pHeadquarter->warriorNum[kindNo] << " " << product_s[kindNo];
	cout << " in " << pHeadquarter->GetColor() << " headquarter" << endl;
}

void Warrior::PrintInfo(void)
{
	if (kindNo == 0)
		cout << "It has a " << weapon_list[weaponNo[0]] << ",and it's morale is " << morale << endl;
	else if (kindNo == 1)
		cout << "It has a " << weapon_list[weaponNo[0]] << "and a " << weapon_list[weaponNo[1]] << endl;
	else if (kindNo == 2)
		cout << "It has a " << weapon_list[weaponNo[0]] << endl;
	else if (kindNo == 3)
		cout << "It's loyalty is " << loyalty << endl;
}

void Headquarter::Init(int color_, int lifevalue_)
{
	Color_C = color_;
	totalLifeValue = lifevalue_;
	totalWarriorNum = 0;
	stopped = false;
	curMakingSeqIdx = 0;
	for (int i = 0; i < WARRIOR_NUM; i++)
		warriorNum[i] = 0;
}

Headquarter::~Headquarter()
{
	for (int i = 0; i < totalWarriorNum; i++)
		delete pWarriors[i];
}

int Headquarter::Produce(int nTime)
{
	if (stopped)
		return 0;

	int searchingTimes = 0;
	while (Warrior::initialLifeValue[makingSeq[Color_C][curMakingSeqIdx]] > totalLifeValue && searchingTimes < WARRIOR_NUM)
	{
		curMakingSeqIdx = (curMakingSeqIdx + 1) % WARRIOR_NUM;
		searchingTimes++;
	}

	int kindNo = makingSeq[Color_C][curMakingSeqIdx];

	if (Warrior::initialLifeValue[kindNo] > totalLifeValue)
	{
		stopped = true;

		cout << setfill('0') << setw(3) << nTime << " ";
		cout << this->GetColor() << " headquarter stops making warriors" << endl;

		return 0;
	}
	//制作士兵：
	totalLifeValue -= Warrior::initialLifeValue[kindNo];
	curMakingSeqIdx = (curMakingSeqIdx + 1) % WARRIOR_NUM;
	pWarriors[totalWarriorNum] = new Warrior(this, totalWarriorNum + 1, kindNo);
	warriorNum[kindNo]++;
	pWarriors[totalWarriorNum]->PrintResult(nTime);
	pWarriors[totalWarriorNum]->PrintInfo();
	totalWarriorNum++;

	return 1;
}

char * Headquarter::GetColor(void)
{
	return color[Color_C];
}

char * Warrior::product_s[] = { (char *)"dragon", (char *)"ninja", (char *)"iceman", (char *)"lion", (char *)"wolf" };
char * Warrior::weapon_list[WEAPON_NUM] = { (char *)"sword", (char *)"bomb", (char *)"arrow" };
int Warrior::initialLifeValue[WARRIOR_NUM];
int Headquarter::makingSeq[2][WARRIOR_NUM] = { { 2, 3, 4, 1, 0 },{ 3, 0, 1, 2, 4 } }; //两个司令部武士的制作顺序序列
char * Headquarter::color[] = { (char *)"red", (char *)"blue" };

int main()
{
	int K;
	int M;
	int casecount = 1;
	Headquarter RedHead, BlueHead;

	cin >> K;

	while (K--)
	{
		cout << "Case:" << casecount << endl;
		casecount++;

		cin >> M;
		for (int i = 0; i < WARRIOR_NUM; i++)
			cin >> Warrior::initialLifeValue[i];

		RedHead.Init(0, M);
		BlueHead.Init(1, M);
		int nTime = 0;

		while (true)
		{
			int red = RedHead.Produce(nTime);
			int blue = BlueHead.Produce(nTime);
			if (red == 0 && blue == 0)
				break;
			nTime++;
		}
	}

	return 0;
}
