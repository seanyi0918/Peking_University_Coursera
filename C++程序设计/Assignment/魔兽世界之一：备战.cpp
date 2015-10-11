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
using namespace std;

const int WARRIOR_NUM = 5;

void changeTime(char *TIME);

class Headquarter;
class Warrior
{
private:
    Headquarter * pHeadquarter;                                 // 用来指向当前武士所在的总部
    char * name;                                                // 当前武士类型
    int num;                                                    // 当前武士编号
    int HP;                                                     // 当前武士生命值
    int power;                                                  // 当前武士的攻击力
    
public:
    Warrior(Headquarter * p, char * name_, int num_, int HP_, int power_ = 0)
    {
        pHeadquarter = p;
        name = name_;
        num = num_;
        HP = HP_;
        power = power_;
    }
};

class Headquarter
{
private:
    int lifeValue;                                              // 总生命值
    int Color_C;                                                // 总部颜色
    int life_R;                                                 // 已生产的总生命值, 要更新
    int HP_R;                                                   // 剩余总生命值, 要更新
    int line[WARRIOR_NUM];                                      // 对应的生产顺序武士所需要的生命值
    int count[WARRIOR_NUM];                                     // 对应的每个武士已生产的数量, 要更新
    int id;                                                     // 总编号, 要更新
    int tmp_id;                                                 // 当前即将有可能生产的武士编号
    int totalWarriorNum;                                        // 已经生产的武士总数
    Warrior * pWarriors[1000];                                  // 拥有的武士们
public:
    friend class Warrior;
    Headquarter(int lifevalue_, int Color_C, int line_[]);
    ~Headquarter();
    char * getColor(void);                                      // 获取对应总部的颜色
    char * getproduct(void);                                    // 获取当前生产的武士
    int produce(char *TIME);                                    // 生产新的武士
    int get_tmpid(void);                                        // 获取当前生产的武士
    static char *color[2];                                      // 颜色阵营
    static char * product_S[WARRIOR_NUM];                       // 武士名字阵营
    static int sequence[2][WARRIOR_NUM];                        // 武士的制作排列
};

char * Headquarter::color[] = {(char *)"red", (char *)"blue"};
char * Headquarter::product_S[] = {(char *)"dragon", (char *)"ninja", (char *)"iceman", (char *)"lion", (char *)"wolf"};
int Headquarter::sequence[2][WARRIOR_NUM] = {{ 2, 3, 4, 1, 0 }, { 3, 0, 1, 2, 4 }};

char * Headquarter::getproduct(void)
{
    int tdid = sequence[Color_C][tmp_id - 1];
    return product_S[tdid];
}

int Headquarter::get_tmpid(void)
{
    return sequence[Color_C][tmp_id - 1];
}

int Headquarter::produce(char * TIME)
{
    int i = 0;
    for ( ; i < WARRIOR_NUM; i++ )
    {
        int ttid = (tmp_id + i) % WARRIOR_NUM;
        int tdid = sequence[Color_C][ttid];
        //                cout << ttid << endl;
        if ( line[tdid] <= HP_R )
        {
            tmp_id = ttid + 1;
            id = id + 1;
            cout << TIME << " ";
            HP_R -= line[tdid];
            life_R += line[tdid];
            count[tdid] += 1;
            changeTime(TIME);
            pWarriors[totalWarriorNum] = new Warrior(this, product_S[tdid], id, line[tdid]);
            totalWarriorNum += 1;
            cout << this->getColor() << " " << this->product_S[tdid] << " " << id;
            cout << " born with strength " << line[tdid] << ",";
            cout << count[tdid] << " " << this->product_S[tdid];
            cout << " in " << this->getColor() << " headquarter" << endl;
            break;
        }
    }
    
    if ( i == WARRIOR_NUM )
    {
        cout << TIME << " " << this->getColor() << " " << "headquarter" << " ";
        cout << "stops making warriors" << endl;
        return 0;
    }
    
    return 1;
}

char * Headquarter::getColor(void)
{
    return color[Color_C];
}

Headquarter::Headquarter(int lifevalue_, int Color_C_, int line_[WARRIOR_NUM])
{
    lifeValue = lifevalue_;
    Color_C = Color_C_;
    life_R = 0;
    HP_R = lifeValue;
    id = 0;                                                         // 总编号, 要更新
    tmp_id = 0;                                                     // 当前即将有可能生产的武士编号
    totalWarriorNum = 0;
    for ( int i = 0; i < WARRIOR_NUM; i++ )
    {
        line[i] = line_[i];
        count[i] = 0;                                               // 对应的每个武士已生产的数量, 要更新
    }
}

Headquarter::~Headquarter()
{
    for ( int i = 0; i < totalWarriorNum; i++ )
        delete pWarriors[i];
}


int main(void)
{
    int K;                                                      // 测试数据组数
    int M;                                                      // 程序输入的能够用来生产总生命值数
    int casecount = 1;                                          // 输出case
    int aline[WARRIOR_NUM] = {0, 0, 0, 0, 0};
    
    cin >> K;
    
    while ( K-- )
    {
        cin >> M;
        
        for ( int i = 0; i < WARRIOR_NUM; i++ )
            cin >> aline[i];
        
        cout << "case:" << casecount << endl;
        
        char TIME_red[4] = {'0', '0', '0', '\0'};                   // 用来显示红色军营时间
        char TIME_blue[4] = {'0', '0', '0', '\0'};                  // 用来显示蓝色军营时间
        
        Headquarter Headred(M, 0, aline);
        Headquarter Headblue(M, 1, aline);
        
        int red = 1, blue = 1;
        
        while ( true )
        {
            if ( red == 1 )
                red = Headred.produce(TIME_red);
            
            if ( blue == 1 )
                blue = Headblue.produce(TIME_blue);
            
            if ( red == 0 && blue == 0 )
                break;
        }
        
        casecount++;
    }
    
    return 0;
}

void changeTime(char *TIME)
{
    if ( TIME[2] >= '0' && TIME[2] < '9' )
        TIME[2] += 1;
    else if ( TIME[2] == '9' )
    {
        TIME[2] = '0';
        if ( TIME[1] >= '0' && TIME[1] < '9' )
            TIME[1] += 1;
        else
        {
            TIME[1] = '0';
            TIME[0] += 1;
        }
    }
}