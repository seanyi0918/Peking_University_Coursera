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

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值这两种属性。

有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。

双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。

不同的武士有不同的特点。

dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。

ninjia可以拥有两件武器。编号为n的ninjia降生时即获得编号为 n%3 和 (n+1)%3的武器。

iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。

lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。

wolf没特点。

请注意，在以后的题目里，武士的士气，生命值，忠诚度在其生存期间都可能发生变化，都有作用，武士手中的武器随着使用攻击力也会发生变化。

武士在刚降生的时候有一个生命值。

在每个整点，双方的司令部中各有一个武士降生。

红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序循环制造武士。

蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序循环制造武士。

制造武士需要生命元。

制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。

给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。

一共有两种事件，其对应的输出样例如下：

1) 武士降生

输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter

表示在 4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5,降生后蓝魔司令部里共有2个lion武士。(为简单起见，不考虑单词的复数形式)注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。

如果造出的是dragon，那么还要输出一行，例：

It has a arrow,and it's morale is 23.34

表示该dragon降生时得到了arrow,其士气是23.34（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）

如果造出的是ninjia，那么还要输出一行，例：

It has a bomb and a arrow

表示该ninjia降生时得到了bomb和arrow。

如果造出的是iceman，那么还要输出一行，例：

It has a sword

表示该iceman降生时得到了sword。

如果造出的是lion，那么还要输出一行，例：

It's loyalty is 24

表示该lion降生时的忠诚度是24。

2) 司令部停止制造武士

输出样例： 010 red headquarter stops making warriors

表示在 10点整，红方司令部停止制造武士

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入

第一行是一个整数,代表测试数据组数。

每组测试数据共两行。

第一行，一个整数M。其含义为： 每个司令部一开始都有M个生命元( 1 <= M <= 10000)

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000

输出

对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。

对每组测试数据，首先输出“Case:n" n是测试数据的编号，从1开始

接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。

样例输入

1
20
3 4 5 6 7
样例输出

Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
It has a bomb
000 blue lion 1 born with strength 6,1 lion in blue headquarter
It's loyalty is 14
001 red lion 2 born with strength 6,1 lion in red headquarter
It's loyalty is 9
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
It has a arrow,and it's morale is 3.67
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
It has a sword and a bomb
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
It has a bomb
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

class Weapon
{
 private:
	int name;
	int wPower;
 public:
	 Weapon(int name_ = 0, int wPower_ = 0) : name(name_), wPower(wPower_) {};
	 static char * weapon_list[WEAPON_NUM];
	 char *getWeaponName(void) { return weapon_list[name]; }
};

class Headquarter;
class Warrior
{
private:
	Headquarter * pHeadquarter;
	int kindNo; //武士的种类编号 0 dragon 1 ninja 2 iceman 3 lion 4 wolf
	int no;
public:
	static char * product_s[WARRIOR_NUM];
	static int initialLifeValue[WARRIOR_NUM];
	Warrior(Headquarter * p, int no_, int kindNo_);
	void PrintResult(int nTime);
};

class Dragon : public Warrior
{
 private:
	Weapon weapon;
	double morale;
 public:
	 Dragon(Headquarter * p, int no_, int kindNo_, int weapon_name, double morale_): Warrior(p, no_, kindNo_), weapon(weapon_name), morale(morale_) {};
	 void PrintResult(int nTime);
};

class Ninjia : public Warrior
{
private:
	Weapon weapon1;
	Weapon weapon2;
public:
	Ninjia(Headquarter * p, int no_, int kindNo_, int weapon_name[2]) : Warrior(p, no_, kindNo_), weapon1(weapon_name[0]), weapon2(weapon_name[1]) {};
	void PrintResult(int nTime);
};

class Iceman : public Warrior
{
 private:
	Weapon weapon;
 public:
	 Iceman(Headquarter * p, int no_, int kindNo_, int weapon_name) : Warrior(p, no_, kindNo_), weapon(weapon_name) {};
	 void PrintResult(int nTime);
};

class Lion : public Warrior
{
 private:
	 int loyalty;
 public:
	 Lion(Headquarter * p, int no_, int kindNo_, int loyalty_) : Warrior(p, no_, kindNo_), loyalty(loyalty_) {};
	 void PrintResult(int nTime);
};

class Wolf : public Warrior
{
 public:
	 Wolf(Headquarter * p, int no_, int kindNo_) : Warrior(p, no_, kindNo_) {};
	 void PrintResult(int nTime);
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
	Dragon * pDragon[1000];
	Ninjia * pNinjia[1000];
	Iceman * pIceman[1000];
	Lion * pLion[1000];
	Wolf * pWolf[1000];
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
}

void Warrior::PrintResult(int nTime)
{
	cout << setfill('0') << setw(3) << nTime << " ";
	cout << pHeadquarter->GetColor() << " " << product_s[kindNo] << " " << no;
	cout << " born with strength " << initialLifeValue[kindNo] << ",";
	cout << pHeadquarter->warriorNum[kindNo] << " " << product_s[kindNo];
	cout << " in " << pHeadquarter->GetColor() << " headquarter" << endl;
}

void Dragon::PrintResult(int nTime)
{
	Warrior::PrintResult(nTime);
	cout << "It has a " << weapon.getWeaponName() << ",";
	cout << "and it's morale is ";
	cout << fixed << setprecision(2) << this->morale << endl;
}

void Ninjia::PrintResult(int nTime)
{
	Warrior::PrintResult(nTime);
	cout << "It has a " << weapon1.getWeaponName() << ",";
	cout << "and a " << weapon2.getWeaponName() << endl;
}

void Iceman::PrintResult(int nTime)
{
	Warrior::PrintResult(nTime);
	cout << "It has a " << weapon.getWeaponName() << endl;
}

void Lion::PrintResult(int nTime)
{
	Warrior::PrintResult(nTime);
	cout << "It's loyalty is " << loyalty << endl;
}

void Wolf::PrintResult(int nTime)
{
	Warrior::PrintResult(nTime);
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
	/*totalLifeValue -= Warrior::initialLifeValue[kindNo];
	curMakingSeqIdx = (curMakingSeqIdx + 1) % WARRIOR_NUM;
	pWarriors[totalWarriorNum] = new Warrior(this, totalWarriorNum + 1, kindNo);
	warriorNum[kindNo]++;
	pWarriors[totalWarriorNum]->PrintResult(nTime);
	totalWarriorNum++;*/
	totalLifeValue -= Warrior::initialLifeValue[kindNo];
	curMakingSeqIdx = (curMakingSeqIdx + 1) % WARRIOR_NUM;
	int weaponnametmp, loyalty_;
	double moraletmp;
	int weapon_[2];
	switch (kindNo)
	{
		case 0:
			weaponnametmp = (totalWarriorNum + 1) % 3;
			moraletmp = (double)totalLifeValue / (double)Warrior::initialLifeValue[kindNo];
			pDragon[warriorNum[kindNo]] = new Dragon(this, totalWarriorNum + 1, kindNo, weaponnametmp, moraletmp);
			pWarriors[totalWarriorNum] = pDragon[warriorNum[kindNo]];
			warriorNum[kindNo]++;
			pDragon[warriorNum[kindNo]-1]->PrintResult(nTime);
			break;
		case 1:
			weapon_[0] = (totalWarriorNum + 1) % 3;
			weapon_[1] = (totalWarriorNum + 2) % 3;
			pNinjia[warriorNum[kindNo]] = new Ninjia(this, totalWarriorNum + 1, kindNo, weapon_);
			pWarriors[totalWarriorNum] = pNinjia[warriorNum[kindNo]];
			warriorNum[kindNo]++;
			pNinjia[warriorNum[kindNo]-1]->PrintResult(nTime);
			break;
		case 2:
			weaponnametmp = (totalWarriorNum + 1) % 3;
			pIceman[warriorNum[kindNo]] = new Iceman(this, totalWarriorNum + 1, kindNo, weaponnametmp);
			pWarriors[totalWarriorNum] = pIceman[warriorNum[kindNo]];
			warriorNum[kindNo]++;
			pIceman[warriorNum[kindNo]-1]->PrintResult(nTime);
			break;
		case 3:
			loyalty_ = totalLifeValue;
			pLion[warriorNum[kindNo]] = new Lion(this, totalWarriorNum + 1, kindNo, loyalty_);
			pWarriors[totalWarriorNum] = pLion[warriorNum[kindNo]];
			warriorNum[kindNo]++;
			pLion[warriorNum[kindNo]-1]->PrintResult(nTime);
			break;
		case 4:
			pWolf[warriorNum[kindNo]] = new Wolf(this, totalWarriorNum + 1, kindNo);
			pWarriors[totalWarriorNum] = pWolf[warriorNum[kindNo]];
			warriorNum[kindNo]++;
			pWolf[warriorNum[kindNo]-1]->PrintResult(nTime);
			break;
	}

	totalWarriorNum++;
	return 1;
}

char * Headquarter::GetColor(void)
{
	return color[Color_C];
}

char * Weapon::weapon_list[WEAPON_NUM] = { (char *)"sword", (char *)"bomb", (char *)"arrow" };
char * Warrior::product_s[] = { (char *)"dragon", (char *)"ninja", (char *)"iceman", (char *)"lion", (char *)"wolf" };
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
