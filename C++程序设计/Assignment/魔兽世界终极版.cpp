//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 */

// 输出时间的方式可以是: cout << setfill('0') << setw(3) << time

#include <iostream>
#include <iomanip>
using namespace std;
const int WARRIOR_NUM = 5;
const int WEAPON_NUM = 3;
const int CITY_NUM = 20;
/*
 char * Warrior::product_s[WARRIOR_NUM] = { "dragon","ninja","iceman","lion","wolf" };
 红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序制造武士。
 蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序制造武士。
 */

class Headquarter;
class Warrior;

class Weapon
{
private:
    int wKindNo;                // 武器编号
    Warrior * wpwarrior;        // 拥有武器的武士
    bool useful;                // 武器是否还有用
public:
    Weapon(int wKindNo_, Warrior * wpwarrior_) : wKindNo(wKindNo_), wpwarrior(wpwarrior_) { useful = true; }
    static char * weapon_list[WEAPON_NUM];
    virtual bool getWeaponUseful() { return useful; }
    int getWeaponNo() { return wKindNo; }
    char * getWeaponName() { return weapon_list[wKindNo]; }
    virtual void afterFight() {}
    virtual int getWeaponPower() { return 0; }
    void setWeaponuse(bool use) { useful = use; }
};

class Sword :public Weapon
{
private:
    int swordPower;             // sword攻击力
public:
    Sword(int wKindNo_, Warrior * wpwarrior_, int swordPower_) :Weapon(wKindNo_, wpwarrior_), swordPower(swordPower_) {}
    virtual bool getWeaponUseful() { return (swordPower != 0); }                // 是否还有攻击力
    virtual void afterFight() { swordPower = swordPower * 4 / 5; }
    virtual int getWeaponPower() { return swordPower; }
};

class Arrow :public Weapon
{
private:
    int arrowuse;               // Arrow 还剩的次数
public:
    static int arrowPower;
    Arrow(int wKindNo_, Warrior * wpwarrior_, int arrowuse_ = 3) : Weapon(wKindNo_, wpwarrior_) { arrowuse = arrowuse_; }
    virtual void afterFight() { if (arrowuse > 0) arrowuse -= 1; }
    virtual bool getWeaponUseful() { return (arrowuse > 0); }
    virtual int getWeaponPower() { return arrowuse; }
};

class Bomb : public Weapon
{
    bool bombuse;
public:
    Bomb(int wKindNo_, Warrior * wpwarrior_) : Weapon(wKindNo_, wpwarrior_) { bombuse = true; }
    virtual bool getWeaponUseful() { return bombuse; }
    virtual void afterFight() { bombuse = false; }
    virtual int getWeaponPower() { return bombuse; }
};

class Warrior
{
protected:
    Headquarter * pHeadquarter;
    int element;
    int force;
    int kindNo;                         // 武士的种类编号 0 dragon 1 ninja 2 iceman 3 lion 4 wolf
    int no;
    Weapon * weapon[3];					// Wolf因为有缴获技能, 因此最多有可能有三种武器
    int weaponCount;                    // 武士的武器数量
    int addrCity;                       // 走到的城市
    int addrForward;					// 走过的步数
    bool notReached;
public:
    static char * product_s[WARRIOR_NUM];
    static int initialLifeValue[WARRIOR_NUM];
    static int initialForce[WARRIOR_NUM];
    Warrior(Headquarter * p, int no_, int kindNo_);
    void WarriorPrintPre(int nHour, int nMinute);
    void WarriorPrintInfo();
    virtual void PrintProduce(int nHour, int nMinute);
    void PrintWarriorPreAttack(int nHour, int nMinute, Warrior * uApwarrior, int cityNum);
    virtual int WarriorAttack(int nHour, int nMinute, Warrior * uApwarrior, int cityNum);
    virtual int Hurted(int nPower);
    void PrintWarriorFightBack(Warrior * uFpwarrior, int cityNum, int nHour, int nMinute);
    virtual int FightBack(Warrior * uFpwarrior);
    void PrintWarriorDown(int cityNum, int nHour, int nMinute);
    int getKindNo() { return kindNo; }
    virtual int getLoyalty() { return 0; }
    int getWeaponCount() { return weaponCount; }
    int getWarriorWeaponNo(int weapon_num) { if (weapon_num < weaponCount) return weapon[weapon_num]->getWeaponNo(); else return -1; }
    int getWarriorWeaponPower(int weapon_num) { if (weapon_num < weaponCount) return weapon[weapon_num]->getWeaponPower(); else return -1; }
    int getAddrCity() { return addrCity; }
    bool isOutAddrCity() { return (addrCity == 100); }
    void setAddrCity(int address = 100) { addrCity = address; }
    void PrintRunAway(int nHour, int nMinute);
    int WarriorMarch(int nHour, int nMinute);
    void PrintMarch(int nHour, int nMinute);
    void EarnForHead(int EarnLife_);
    void PrintEarnForHead(int EarnLife_, int nHour, int nMinute);
    int WarriorGetAward();
    int warriorActivePotentialHurt();			// 主动攻击可能造成的伤害
    int warriorBackPotentialHurt();				// 反击可能造成的伤害
    int warriorHasArrow();
    int warriorHasBomb();
    int warriorHasSword();
    int warriorArrowAttack(Warrior * uAAwarrior, int weaponnum, int nHour, int nMinute);	// -1: 射死对方; 1: 没有射死对方
    void warriorBombAttack(Warrior * uBAwarrior, int weaponnum, int nHour, int nMinute);
    void PrintArrowAttack(Warrior * uAAwarrior, int attackResult, int nHour, int nMinute);
    void PrintBombAttack(Warrior * uBAwarrior, int nHour, int nMinute);
    int getElement() { return element; }	// 取得现有的生命值
    int getForce() { return force; }
    void setElement(int element_) { element += element_; }
    void WarriorReportWeapon(int nHour, int nMinute);
    bool getNotReached() { return notReached; }
    void setNotReached(bool notReached_) { notReached = notReached_; }
    void updateWeapon(int updateMode = 0);
    //* Dragon virtual
    virtual double getMorale() { return 0.0; }
    virtual void DragonYell(int cityNum, int nHour, int nMinute) {}
    virtual void setMorale(int setMode = 0, double morale_ = 0.2) {}
    //* Iceman virtual
    virtual void IcemanDec() {}
    //* Lion virtual
    virtual void setLoyalty(int setMode = 0) {}
    //* Wolf virtual
    virtual void WolfCaptureWeapon(Warrior * uAwarrior) {}
    
    void PrintExec();
};

class Dragon :public Warrior
{
private:
    double morale;
public:
    Dragon(Headquarter * p, int no_, int kindNo_, double morale_) : Warrior(p, no_, kindNo_), morale(morale_) {}
    virtual void PrintProduce(int nHour, int nMinute);
    virtual int WarriorAttack(int nHour, int nMinute, Warrior * uApwarrior, int cityNum);
    virtual int Hurted(int nPower);
    virtual int FightBack(Warrior * uFpwarrior);
    virtual double getMorale() { return morale; }
    virtual void DragonYell(int cityNum, int nHour, int nMinute) { WarriorPrintPre(nHour, nMinute); cout << " yelled in city " << cityNum << endl; }
    virtual void setMorale(int setMode = 0, double morale_ = 0.2) { if (setMode == 0) morale += morale_; else morale -= morale_; }
};

class Ninjia :public Warrior
{
public:
    Ninjia(Headquarter * p, int no_, int kindNo_) : Warrior(p, no_, kindNo_) {}
    virtual void PrintProduce(int nHour, int nMinute);
    virtual int WarriorAttack(int nHour, int nMinute, Warrior * uApwarrior, int cityNum);
    virtual int Hurted(int nPower);
    virtual int FightBack(Warrior * uFpwarrior);
};

class Iceman : public Warrior
{
public:
    Iceman(Headquarter * p, int no_, int kindNo_) : Warrior(p, no_, kindNo_) {}
    virtual void PrintProduce(int nHour, int nMinute);
    virtual int WarriorAttack(int nHour, int nMinute, Warrior * uApwarrior, int cityNum);
    virtual int Hurted(int nPower);
    virtual int FightBack(Warrior * uFpwarrior);
    virtual void IcemanDec()
    {
        if (element > 9) element -= 9; else element = 1;
        force += 20;
    }
};

class Lion : public Warrior
{
private:
    int loyalty;
public:
    Lion(Headquarter * p, int no_, int kindNo_, int loyalty_) : Warrior(p, no_, kindNo_), loyalty(loyalty_) {}
    virtual void PrintProduce(int nHour, int nMinute);
    virtual int WarriorAttack(int nHour, int nMinute, Warrior * uApwarrior, int cityNum);
    virtual int Hurted(int nPower);
    virtual int FightBack(Warrior * uFpwarrior);
    virtual int getLoyalty() { return loyalty; }
    virtual void setLoyalty(int setMode = 0) { if (setMode == 0) loyalty -= Lion::decreaseLoyalty; }
    static int decreaseLoyalty;
};

class Wolf : public Warrior
{
public:
    Wolf(Headquarter * p, int no_, int kindNo_) : Warrior(p, no_, kindNo_) {}
    virtual void PrintProduce(int nHour, int nMinute);
    virtual int WarriorAttack(int nHour, int nMinute, Warrior * uApwarrior, int cityNum);
    virtual int Hurted(int nPower);
    virtual int FightBack(Warrior * uFpwarrior);
    virtual void WolfCaptureWeapon(Warrior * uAwarrior)
    {
        /*cout << "进入captureWeapon" << endl;
         cout << "俘获者现有" << getWeaponCount() << "个武器" << "\t" << "被俘获者有" << uAwarrior->getWeaponCount() << "个武器" << endl;*/
        for (int i = 0; i < uAwarrior->getWeaponCount(); i++)
        {
            int j = 0;
            int uAWeaponNo = uAwarrior->getWarriorWeaponNo(i);
            while (j < this->weaponCount && uAWeaponNo != this->getWarriorWeaponNo(j))
                j++;
            if (j == this->weaponCount)
            {
                if (uAWeaponNo == 0) weapon[j] = new Sword(uAWeaponNo, this, uAwarrior->getWarriorWeaponPower(i));
                else if (uAWeaponNo == 1) weapon[j] = new Bomb(uAWeaponNo, this);
                else if (uAWeaponNo == 2) weapon[j] = new Arrow(uAWeaponNo, this, uAwarrior->getWarriorWeaponPower(i));
                weaponCount += 1;
            }
        }
    }
};

void Warrior::WarriorReportWeapon(int nHour, int nMinute) // 交代武器情况时，次序依次是：arrow,bomb,sword
{
    int count = 0;
    WarriorPrintPre(nHour, nMinute);
    cout << " has ";
    int hasArrow = warriorHasArrow();
    int hasBomb = warriorHasBomb();
    int hasSword = warriorHasSword();
    if (count < weaponCount && hasArrow != -1)   // 如果有弓箭, 则输出弓箭
    {
        cout << Weapon::weapon_list[2] << "(" << weapon[hasArrow]->getWeaponPower() << ")";
        count++;
    }
    if (count < weaponCount && hasBomb != -1)
    {
        if (count >= 1)
            cout << ",";
        cout << Weapon::weapon_list[1];
        count++;
    }
    if (count < weaponCount && hasSword != -1)
    {
        if (count >= 1)
            cout << ",";
        cout << Weapon::weapon_list[0] << "(" << weapon[hasSword]->getWeaponPower() << ")";
    }
    if (weaponCount == 0)
        cout << "no weapon";
    cout << endl;
}

void Warrior::updateWeapon(int updateMode) // updateMode = 0: 更新sword; updateMode = 1: 更新Bomb; updateMode = 2: 更新Arrow; updateMode = 3: 生产时更新
{
    bool updateFlag = false;									// 用来记录是否需要丢弃已经没有用的武器
    int updateModeTmp = updateMode;
    if ( updateMode == 3 )
        updateModeTmp = 0;
    for (int i = 0; i < this->weaponCount; i++)
    {
        if (weapon[i]->getWeaponNo() == updateModeTmp)				// 如果是updateMode对应的武器
        {
            if (updateMode != 3)
                weapon[i]->afterFight();
            if (!weapon[i]->getWeaponUseful())					// 如果武器失去攻击力, 先置为空
            {
                weapon[i] = NULL;
                updateFlag = true;
            }
            break;				// 对于特定的一次使用武器, 无论是弓箭攻击, 炸弹攻击还是Sword攻击, 都只会使用一种武器
        }
    }
    if (updateFlag)												// 如果需要丢弃已经没有用的武器
    {
        int weaponcountnew = 0;
        for (int i = 0; i < this->weaponCount; i++)
        {
            if (weapon[i] != NULL)
            {
                weapon[weaponcountnew] = weapon[i];
                weaponcountnew += 1;
            }
        }
        this->weaponCount = weaponcountnew;
    }
}

class City
{
private:
    int cityLifeValue;
    int cityNum;
    Warrior * redWarrior;
    Warrior * blueWarrior;
    int flag;                                  // flag = -1: 没插旗帜; flag = 0: 红旗; flag = 1: 蓝旗
    int BattleResult;						   // 记录上一场战斗的结果
public:
    City(int cityLifeValue_, int cityNum_);
    void Init(int cityLifeValue_, int cityNum_);
    void CityAddLife(int cityAddValue_ = 10) { cityLifeValue += cityAddValue_; }
    void setCityLifeValue(int cityLifeValue_) { cityLifeValue = cityLifeValue_; }
    void EarnLifeForHead(int nHour, int nMinute, int Post = 0);	// Post = 0: 需要打印赢取生命元的行为; Post = 1: 不需要打印
    int CityAwardWarrior(int color = 0); // color = 0: 奖励红色的士兵, color = 1: 奖励蓝色的士兵; 返回值 = -1: 司令部没有足够生命元用来奖励; 返回值 = 1: 司令部还有足够的生命元用来奖励
    void setredWarrior(Warrior * redWarrior_) { redWarrior = redWarrior_; }
    void setblueWarrior(Warrior * blueWarrior_) { blueWarrior = blueWarrior_; }
    Warrior * getblueWarrior() { return blueWarrior; }
    int getCityNum() { return cityNum; }
    int getCityLifeValue() { return cityLifeValue; }
    static int citytotal;
    void CityRunAway(int nHour, int nMinute);
    int CityMarch(City * nexcity, int nHour, int nMinute);		// = 0: 红武士胜利; = 1: 蓝武士胜利; = -1: 两边均没有两个敌人到达
    void CityArrowAttack(City * Bcity, City * ACity, int nHour, int nMinute);
    bool ActiveAttack();
    int CityBattlePotential();							// = 0: 红武士胜; = 1: 蓝武士胜; = -1: 没有武士死亡
    bool CityBombAttack(int nHour, int nMinute);		// = true: 双方同归于尽; = false: 没有使用bomb
    void updateBattleResult(int nHour, int nMinute, int afterBattle);
    void PrintFlagRaise(int nHour, int nMinute);
    int CityBattle(int nHour, int nMinute);				// = 0: 红武士胜; = 1: 蓝武士胜; = -1: 没有武士死亡
    void CityReportWeapon(int nHour, int nMinute, int color);		// 报告武器情况
    
    void PrintEachCityAfterExec();						// 测试用, 打印城市武士信息
};

City::City(int cityLifeValue_, int cityNum_)
{
    cityNum = cityNum_;
    cityLifeValue = cityLifeValue_;
    flag = -1;
    BattleResult = -1;
    redWarrior = NULL;
    blueWarrior = NULL;
}

void City::Init(int cityLifeValue_, int cityNum_)
{
    cityNum = cityNum_;
    cityLifeValue = cityLifeValue_;
    flag = -1;
    BattleResult = -1;
    redWarrior = NULL;
    blueWarrior = NULL;
}

void City::CityRunAway(int nHour, int nMinute)
{
    if (redWarrior != NULL && redWarrior->getKindNo() == 3 && redWarrior->getLoyalty() <= 0)
    {
        if (redWarrior->getAddrCity() != (City::citytotal + 1))
        {
            redWarrior->PrintRunAway(nHour, nMinute);
            redWarrior->setAddrCity();										// addrCity很大(默认100), 表示逃到不见
            redWarrior = NULL;
        }
    }
    if (blueWarrior != NULL && blueWarrior->getKindNo() == 3 && blueWarrior->getLoyalty() <= 0)
    {
        if (blueWarrior->getAddrCity() != 0)
        {
            blueWarrior->PrintRunAway(nHour, nMinute);
            blueWarrior->setAddrCity();
            blueWarrior = NULL;
        }
    }
}

int City::CityMarch(City * nextcity, int nHour, int nMinute)
{
    int occupationFlag = -1;
    int occupationFlagTmp = -1;
    if (nextcity->blueWarrior != NULL && nextcity->blueWarrior->getAddrCity() != 0)
    {
        occupationFlagTmp = nextcity->blueWarrior->WarriorMarch(nHour, nMinute);
        if (occupationFlagTmp == 1)
        {
            occupationFlag = 1;
            cout << setfill('0') << setw(3) << nHour << ":" << setw(2) << nMinute << " ";
            cout << "red headquarter was taken" << endl;
        }
        else if (occupationFlagTmp == 3) // 如果第一个蓝武士到达红方司令部
        {
            // 要setcity[0]的bluewarrior
            this->setblueWarrior(nextcity->blueWarrior);
        }
        nextcity->blueWarrior = NULL;
    }
    if (redWarrior != NULL && redWarrior->getAddrCity() != (City::citytotal + 1)) // 红方前进
    {
        occupationFlagTmp = redWarrior->WarriorMarch(nHour, nMinute);
        if (occupationFlagTmp == 0)
        {
            occupationFlag = 0;
            cout << setfill('0') << setw(3) << nHour << ":" << setw(2) << nMinute << " ";
            cout << "blue headquarter was taken" << endl;
        }
        if (occupationFlagTmp == 2) // 如果第一个红武士到达蓝方司令部
        {
            // 要setcity[N]的红武士;
            nextcity->setredWarrior(this->redWarrior);
        }
        redWarrior = NULL;
    }
    if ( occupationFlag == -1 )
        occupationFlag = occupationFlagTmp;
    return occupationFlag;
}

void City::EarnLifeForHead(int nHour, int nMinute, int Post)
{
    if (redWarrior != NULL && blueWarrior == NULL && cityLifeValue != 0)
    {
        redWarrior->EarnForHead(cityLifeValue);
        if (Post == 0)
            redWarrior->PrintEarnForHead(cityLifeValue, nHour, nMinute);
        setCityLifeValue(0);
    }
    else if (redWarrior == NULL && blueWarrior != NULL && cityLifeValue != 0)
    {
        blueWarrior->EarnForHead(cityLifeValue);
        if (Post == 0)
            blueWarrior->PrintEarnForHead(cityLifeValue, nHour, nMinute);
        setCityLifeValue(0);
    }
}

int City::CityAwardWarrior(int color) // color = 0: 奖励红色的士兵, color = 1: 奖励蓝色的士兵; 返回值 = -1: 司令部没有足够生命元用来奖励; 返回值 = 1: 司令部还有足够的生命元用来奖励
{
    int AwardResult = 1;
    if (color == 0 && redWarrior != NULL && blueWarrior == NULL && cityLifeValue != 0)
        AwardResult = redWarrior->WarriorGetAward();
    else if (color == 1 && blueWarrior != NULL && redWarrior == NULL && cityLifeValue != 0)
        AwardResult = blueWarrior->WarriorGetAward();
    return AwardResult;
}

void City::CityArrowAttack(City * Bcity, City * Acity, int nHour, int nMinute)
{
    int redArrow = 1, blueArrow = 1;
    if (redWarrior != NULL && Acity->blueWarrior != NULL)
    {
        if (cityNum < City::citytotal && redWarrior->warriorHasArrow() != -1)
            redArrow = redWarrior->warriorArrowAttack(Acity->blueWarrior, redWarrior->warriorHasArrow(), nHour, nMinute);
    }
    if ( blueWarrior != NULL && Bcity->redWarrior != NULL)
    {
        if (cityNum > 1 && blueWarrior->warriorHasArrow() != -1)
            blueArrow = blueWarrior->warriorArrowAttack(Bcity->redWarrior, blueWarrior->warriorHasArrow(), nHour, nMinute);
    }
    
    if (redArrow == -1)
        Acity->blueWarrior->setAddrCity();										// addrCity很大(默认100), 表示被杀死
    if (blueArrow == -1)
        Bcity->redWarrior->setAddrCity();                                       // addrCity很大(默认100), 表示被杀死
}

bool City::ActiveAttack()
{
    if ((flag == -1 && cityNum % 2 == 1) || flag == 0)				// 由红武士先发起进攻
        return true;
    return false;
}

void City::updateBattleResult(int nHour, int nMinute, int afterBattle)	// afterBattle = 0: 红武士胜; = 1: 蓝武士胜; = -1: 平局
{
    if (afterBattle != BattleResult)
        BattleResult = afterBattle;
    else if (BattleResult != -1 && afterBattle == BattleResult && flag != afterBattle)
    {
        flag = afterBattle;
        this->PrintFlagRaise(nHour, nMinute);
    }
}
void City::PrintFlagRaise(int nHour, int nMinute)
{
    cout << setfill('0') << setw(3) << nHour << ":" << setw(2) << nMinute << " ";
    if (flag == 0) cout << "red"; else cout << "blue";
    cout << " flag raised in city " << cityNum << endl;
}

int City::CityBattle(int nHour, int nMinute)						// = 0: 红武士胜; = 1: 蓝武士胜; = -1: 没有武士死亡或者没有发生战斗
{
    int cityBattlePotential = CityBattlePotential(); // 判断战斗结果, = 0: 红武士胜; = 1: 蓝武士胜; = -1: 没有交战; = 2: 红武士战前已经被射死, 蓝武士相当于胜利; = 3: 蓝武士战前已经被射死, 红武士相当于胜利; = 4: 红武士和蓝武士战前均被射死或炸死; = 5: 双方幸存
    int battleResult = -1; // = -1: 没有任何一方死亡; = 0: 主动进攻者胜利, 被进攻者死亡; = 1: 被动进攻者胜利, 主动进攻者死亡; = 2: 战前主动者已死; = 3: 战前被动者已死
    if (redWarrior != NULL && redWarrior->isOutAddrCity() && blueWarrior == NULL)		// 一个被射死, 一个为NULL
    {
        redWarrior->setAddrCity();
        redWarrior = NULL;
    }
    else if (blueWarrior != NULL && blueWarrior->isOutAddrCity() && redWarrior == NULL)	// 一个被射死, 一个为NULL
    {
        blueWarrior->setAddrCity();
        blueWarrior = NULL;
    }
    if (redWarrior == NULL || blueWarrior == NULL)
        return -1;
    if (ActiveAttack())												// 由红武士先发起进攻
        battleResult = redWarrior->WarriorAttack(nHour, nMinute, blueWarrior, cityNum);
    else
        battleResult = blueWarrior->WarriorAttack(nHour, nMinute, redWarrior, cityNum);		// 由蓝武士先发起进攻
    if (cityBattlePotential == 0 || cityBattlePotential == 3)
    {
        redWarrior->PrintEarnForHead(cityLifeValue, nHour, nMinute);	// 先打印为headquarter赢得生命元, 之后再实质性的加上这些生命元
        blueWarrior->setAddrCity();
        blueWarrior = NULL;
        this->updateBattleResult(nHour, nMinute, 0); // 更新战斗结果BattleResult, 红武士胜;
    }
    else if (cityBattlePotential == 1 || cityBattlePotential == 2)
    {
        blueWarrior->PrintEarnForHead(cityLifeValue, nHour, nMinute);	// 先打印为headquarter赢得生命元, 之后再实质性的加上这些生命元
        redWarrior->setAddrCity();
        redWarrior = NULL;
        this->updateBattleResult(nHour, nMinute, 1); // 更新战斗结果BattleResult, 蓝武士胜;
    }
    else if (cityBattlePotential == 4)	// 战前两者就死了
    {
        redWarrior = NULL;
        blueWarrior = NULL;
    }
    else if (cityBattlePotential == 5)	// 双方战后均幸存
        this->updateBattleResult(nHour, nMinute, -1); // 更新战斗结果BattleResult, 双方平局;
    return cityBattlePotential;
}

int City::CityBattlePotential()												// 判断战斗结果, = 0: 红武士胜; = 1: 蓝武士胜; = -1: 没有武士死亡或者没有交战
{																			// = 2: 红武士战前已经被射死, 蓝武士相当于胜利; = 3: 蓝武士战前已经被射死, 红武士相当于胜利
    if (redWarrior == NULL || blueWarrior == NULL)							// = 4: 红武士和蓝武士战前均被射死或炸死; = 5: 双方幸存
        return -1;
    if (redWarrior->isOutAddrCity() && !blueWarrior->isOutAddrCity())		// 如果战斗开始前红武士已经被箭射死;
        return 2;
    else if (blueWarrior->isOutAddrCity() && !redWarrior->isOutAddrCity())	// 如果战斗开始前蓝武士已经被箭射死;
        return 3;
    else if (redWarrior->isOutAddrCity() && blueWarrior->isOutAddrCity())	// 如果战斗开始前红武士和蓝武士均被射死
        return 4;
    if (ActiveAttack())														// 由红武士先发起进攻
    {
        if (redWarrior->warriorActivePotentialHurt() >= blueWarrior->getElement())
            return 0;
        else if (blueWarrior->getKindNo() != 1 && blueWarrior->warriorBackPotentialHurt() >= redWarrior->getElement()) // 如果不是ninjia才会反击
            return 1;
    }
    else
    {
        if (blueWarrior->warriorActivePotentialHurt() >= redWarrior->getElement())
            return 1;
        else if (redWarrior->getKindNo() != 1 && redWarrior->warriorBackPotentialHurt() >= blueWarrior->getElement()) // 如果不是ninjia才会反击
            return 0;
    }
    
    return 5;	// 双方幸存
}

bool City::CityBombAttack(int nHour, int nMinute)				// = true: 两边同归于尽; = false: 没有发生bomb事件
{
    bool bombflag = false;
    int cBT = CityBattlePotential();	// = 0: 红胜; = 1: 蓝胜; = 2: 红战前死; = 3: 蓝战前死; = 4: 战前均死; = 5: 双方幸存
    if (cBT == -1 || cBT == 5)
        return false;
    else if (cBT == 0 && blueWarrior->warriorHasBomb() != -1)
    {
        blueWarrior->warriorBombAttack(redWarrior, blueWarrior->warriorHasBomb(), nHour, nMinute);
        bombflag = true;
    }
    else if (cBT == 1 && redWarrior->warriorHasBomb() != -1)
    {
        redWarrior->warriorBombAttack(blueWarrior, redWarrior->warriorHasBomb(), nHour, nMinute);
        bombflag = true;
    }
    if (bombflag)
    {
        redWarrior->setAddrCity();												// addrCity很大(默认100), 表示被杀死
        //redWarrior = NULL;
        blueWarrior->setAddrCity();												// addrCity很大(默认100), 表示被杀死
        //blueWarrior = NULL;
        return true;
    }
    return false;
}

void City::CityReportWeapon(int nHour, int nMinute, int color)
{
    if (color == 0 && redWarrior != NULL)
        redWarrior->WarriorReportWeapon(nHour, nMinute);
    if (color == 1 && blueWarrior != NULL)
        blueWarrior->WarriorReportWeapon(nHour, nMinute);
}

void City::PrintEachCityAfterExec()
{
    if (cityNum == 0)
        cout << "(红总" << ":";
    else if (cityNum == (City::citytotal + 1))
        cout << "(蓝总" << ":";
    else
        cout << "(城市" << cityNum << ":";
    cout << "红";
    if (redWarrior != NULL)
    {
        redWarrior->PrintExec();
        cout << ", ";
    }
    else
        cout << "空" << ", ";
    cout << "蓝";
    if (blueWarrior != NULL)
    {
        blueWarrior->PrintExec();
        cout << ")";
    }
    else
        cout << "空" << ")";
}

class Headquarter
{
private:
    int totalLifeValue;
    bool stopped;
    int totalWarriorNum;
    int Color_C;
    int curMakingSeqIdx;                            //当前要制造的武士是制造序列中的第几个
    int warriorNum[WARRIOR_NUM];                    //存放每种武士的数量
    Warrior * pWarriors[1000];
    int occupation;									// 到达对方司令部的武士数量
public:
    friend class Warrior;
    static int makingSeq[2][WARRIOR_NUM];           //武士的制作顺序序列
    void Init(int color_, int lifevalue_);
    ~Headquarter();
    int Produce(int nHour, int nMinute);
    void UpdateCityWarrior();
    char * GetColor();
    int getColor() { return Color_C; }
    static char * color[2];
    static City * cityN[CITY_NUM + 2];
    static int citiesN[CITY_NUM];					// 用来保存每个城市战斗后的胜利方; = 0: 没有胜利者; = 1: 红方胜; = 2: 蓝方胜
    Warrior * getpwarrior(int id) { return pWarriors[id - 1]; }
    void AddLife(int addLifeValue_) { totalLifeValue += addLifeValue_; }
    int getTotalLifeValue() { return totalLifeValue; }
    void setTotalLifeValue(int lifeValue_) { totalLifeValue -= lifeValue_; }
    void PrintLifeValue(int nHour, int nMinute);
    int getOccupation() { return occupation; }
};

Warrior::Warrior(Headquarter * p, int no_, int kindNo_)
{
    no = no_;
    kindNo = kindNo_;
    pHeadquarter = p;
    force = initialForce[kindNo_];
    element = initialLifeValue[kindNo_];
    addrForward = 0;
    notReached = true;
    if (p->getColor() == 0) addrCity = 0;
    else if (p->getColor() == 1) addrCity = City::citytotal + 1;
    if (kindNo == 0) weaponCount = 1;
    else if (kindNo == 1) weaponCount = 2;
    else if (kindNo == 2) weaponCount = 1;
    else if (kindNo == 3) weaponCount = 0;
    else if (kindNo == 4) weaponCount = 0;
    for (int i = 0; i < weaponCount; i++)
    {
        int weapon_num = (no_ + i) % 3;
        if (weapon_num == 0) weapon[i] = new Sword(weapon_num, this, force / 5);
        else if (weapon_num == 1) weapon[i] = new Bomb(weapon_num, this);
        else if (weapon_num == 2) weapon[i] = new Arrow(weapon_num, this);
    }
    updateWeapon(3);
}

int Warrior::warriorActivePotentialHurt()
{
    int forceTmp = this->force;
    for (int i = 0; i < weaponCount; i++)
    {
        if (weapon[i]->getWeaponUseful() && weapon[i]->getWeaponNo() == 0)
            forceTmp += weapon[i]->getWeaponPower();
    }
    return forceTmp;
}
int Warrior::warriorBackPotentialHurt()
{
    int forceTmp = this->force / 2;
    for (int i = 0; i < weaponCount; i++)
    {
        if (weapon[i]->getWeaponUseful() && weapon[i]->getWeaponNo() == 0)
            forceTmp += weapon[i]->getWeaponPower();
    }
    return forceTmp;
}

void Warrior::PrintWarriorPreAttack(int nHour, int nMinute, Warrior * uApwarrior, int cityNum)
{
    WarriorPrintPre(nHour, nMinute);
    cout << " attacked ";
    uApwarrior->WarriorPrintInfo();
    cout << " in city " << cityNum << " with " << element << " elements and force " << force << endl;
}
int Warrior::WarriorAttack(int nHour, int nMinute, Warrior * uApwarrior, int cityNum)
{
    int attackResult = -1; // = -1: 没有任何一方死亡; = 0: 主动进攻者胜利, 被进攻者死亡; = 1: 被动进攻者胜利, 主动进攻者死亡; = 2: 战前主动者已死; = 3: 战前被动者已死
    if (this->isOutAddrCity() && uApwarrior->isOutAddrCity())	// 战前均已死
    {
        attackResult = 4;
        return attackResult;
    }
    if (this->isOutAddrCity() && !uApwarrior->isOutAddrCity())	// 战前主动攻击者已死
        attackResult = 2;
    else if (!this->isOutAddrCity() && uApwarrior->isOutAddrCity())	// 战前被攻击者已死
        attackResult = 3;
    //* 如果战斗开始前没有武士被射死或者双方同归于尽, 那么会发生下面的战斗
    if (attackResult == -1)
    {
        //cout << "主动攻击者 = " << this->getElement() << "; arrCity = " << this->getAddrCity() << "; attackResult = " << attackResult << endl;
        PrintWarriorPreAttack(nHour, nMinute, uApwarrior, cityNum);
        int APreElement = element;									// 战斗前主动攻击者的生命值
        int uAPreElement = uApwarrior->element;						// 战斗前被动攻击者的生命值
        int hurted = uApwarrior->Hurted(warriorActivePotentialHurt());
        this->updateWeapon();										// 如果有Sword, 需要更新Sword攻击力
        if (hurted == 1 && uApwarrior->kindNo != 1)					// 如果被攻击者没有战死并且被攻击者不是Ninjia, 就要反击
        {
            uApwarrior->PrintWarriorFightBack(this, cityNum, nHour, nMinute);
            hurted = uApwarrior->FightBack(this);
            uApwarrior->updateWeapon();							// 如果有Sword, 需要更新Sword攻击力
            if (hurted == -1)									// 反击者胜利, 主动攻击者战死
            {
                attackResult = 1;
                this->PrintWarriorDown(cityNum, nHour, nMinute);
                if (kindNo == 3)								// 如果战死者是Lion, 则其战斗前的生命值就会转移到对手身上
                    uApwarrior->setElement(APreElement);
            }
        }
        else if (hurted == -1)								// 主动攻击者胜利, 被攻击者战死
        {
            uApwarrior->PrintWarriorDown(cityNum, nHour, nMinute);
            attackResult = 0;
            if (uApwarrior->kindNo == 3)					// 如果战死者是Lion, 则其战斗前的生命值就会转移到对手身上
                this->setElement(uAPreElement);
        }
    }
    
    if (attackResult == -1)	// 如果没有武士战死, 那么无论攻击者还是被攻击者如果是Dragon士气就减少0.2, 如果是Lion则忠诚度降低Lion::decreaseLoyalty
    {
        if (this->kindNo == 0)
            this->setMorale(1);
        if (this->kindNo == 3)
            this->setLoyalty();
        if (uApwarrior->kindNo == 0)
            uApwarrior->setMorale(1);
        else if (uApwarrior->kindNo == 3)
            uApwarrior->setLoyalty();
    }
    else if (attackResult == 1 || attackResult == 2)	// 战前主动攻击者已死或战后战死
    {
        // 发生一切被攻击者战斗胜利该发生的事情;
        if (uApwarrior->kindNo == 0)					// 如果战胜者是Dragon, 那么士气增加0.2
            uApwarrior->setMorale();
        else if (uApwarrior->kindNo == 4)				// 如果胜利者是Wolf, 那么要缴获战死者的武器
            uApwarrior->WolfCaptureWeapon(this);
    }
    else if (attackResult == 0 || attackResult == 3)	// 战前被攻击者已死或战后战死
    {
        // 发生一切主动攻击者胜利会发生的事情;
        if (this->kindNo == 0)							// 如果主动攻击者是Dragon, 则士气增加0.2
            this->setMorale();
        else if (this->kindNo == 4)						// 如果胜利者是Wolf, 那么要缴获战死者的武器
            this->WolfCaptureWeapon(uApwarrior);
    }
    
    if (this->kindNo == 0 && this->element > 0 && this->getMorale() > 0.8)	// 如果主动攻击者是Dragon并且战斗结束没有战死并且士气大于0.8, 就会欢呼
        this->DragonYell(cityNum, nHour, nMinute);
    return attackResult;
}

int Dragon::WarriorAttack(int nHour, int nMinute, Warrior * uApwarrior, int cityNum)
{
    return Warrior::WarriorAttack(nHour, nMinute, uApwarrior, cityNum);
}
int Ninjia::WarriorAttack(int nHour, int nMinute, Warrior * uApwarrior, int cityNum)
{
    return Warrior::WarriorAttack(nHour, nMinute, uApwarrior, cityNum);
}
int Iceman::WarriorAttack(int nHour, int nMinute, Warrior * uApwarrior, int cityNum)
{
    return Warrior::WarriorAttack(nHour, nMinute, uApwarrior, cityNum);
}
int Lion::WarriorAttack(int nHour, int nMinute, Warrior * uApwarrior, int cityNum)
{
    return Warrior::WarriorAttack(nHour, nMinute, uApwarrior, cityNum);
}
int Wolf::WarriorAttack(int nHour, int nMinute, Warrior * uApwarrior, int cityNum)
{
    return Warrior::WarriorAttack(nHour, nMinute, uApwarrior, cityNum);
}


int Warrior::Hurted(int nPower)
{
    element -= nPower;
    if (element <= 0)
        return -1;
    
    return 1;
}
int Dragon::Hurted(int nPower)
{
    return Warrior::Hurted(nPower);
}
int Ninjia::Hurted(int nPower)
{
    return Warrior::Hurted(nPower);
}
int Iceman::Hurted(int nPower)
{
    return Warrior::Hurted(nPower);
}
int Lion::Hurted(int nPower)
{
    return Warrior::Hurted(nPower);
}
int Wolf::Hurted(int nPower)
{
    return Warrior::Hurted(nPower);
}

void Warrior::PrintWarriorFightBack(Warrior * uFpwarrior, int cityNum, int nHour, int nMinute)
{
    WarriorPrintPre(nHour, nMinute);
    cout << " fought back against ";
    uFpwarrior->WarriorPrintInfo();
    cout << " in city " << cityNum << endl;
}
int Warrior::FightBack(Warrior * uFpwarrior)
{
    return (uFpwarrior->Hurted(warriorBackPotentialHurt()));
}
int Dragon::FightBack(Warrior *uFpwarrior)
{
    return (uFpwarrior->Hurted(warriorBackPotentialHurt()));
}
int Ninjia::FightBack(Warrior *uFpwarrior)
{
    return (uFpwarrior->Hurted(warriorBackPotentialHurt()));
}
int Iceman::FightBack(Warrior *uFpwarrior)
{
    return (uFpwarrior->Hurted(warriorBackPotentialHurt()));
}
int Lion::FightBack(Warrior *uFpwarrior)
{
    return (uFpwarrior->Hurted(warriorBackPotentialHurt()));
}
int Wolf::FightBack(Warrior *uFpwarrior)
{
    return (uFpwarrior->Hurted(warriorBackPotentialHurt()));
}

void Warrior::PrintWarriorDown(int cityNum, int nHour, int nMinute)
{
    WarriorPrintPre(nHour, nMinute);
    cout << " was killed in city " << cityNum << endl;
}

void Warrior::WarriorPrintPre(int nHour, int nMinute)
{
    cout << setfill('0') << setw(3) << nHour << ":" << setw(2) << nMinute << " ";
    cout << pHeadquarter->GetColor() << " " << product_s[kindNo] << " " << no;
}

void Warrior::WarriorPrintInfo()
{
    cout << pHeadquarter->GetColor() << " " << product_s[kindNo] << " " << no;
}

void Warrior::PrintProduce(int nHour, int nMinute)
{
    WarriorPrintPre(nHour, nMinute);
    cout << " born" << endl;
}

void Warrior::PrintExec()
{
    cout << product_s[kindNo] << " " << no;
}

void Dragon::PrintProduce(int nHour, int nMinute)
{
    Warrior::PrintProduce(nHour, nMinute);
    cout << "Its morale is ";
    cout << fixed << setprecision(2) << morale << endl;
}

void Ninjia::PrintProduce(int nHour, int nMinute)
{
    Warrior::PrintProduce(nHour, nMinute);
}

void Iceman::PrintProduce(int nHour, int nMinute)
{
    Warrior::PrintProduce(nHour, nMinute);
}

void Lion::PrintProduce(int nHour, int nMinute)
{
    Warrior::PrintProduce(nHour, nMinute);
    cout << "Its loyalty is " << loyalty << endl;
}

void Wolf::PrintProduce(int nHour, int nMinute)
{
    Warrior::PrintProduce(nHour, nMinute);
}

void Warrior::PrintRunAway(int nHour, int nMinute)
{
    WarriorPrintPre(nHour, nMinute);
    cout << " ran away" << endl;
}

void Warrior::PrintMarch(int nHour, int nMinute)
{
    WarriorPrintPre(nHour, nMinute);
    if (pHeadquarter->getColor() == 0 && addrCity == (City::citytotal + 1))
        cout << " reached blue headquarter with " << element << " elements and force " << force << endl;
    else if (pHeadquarter->getColor() == 1 && addrCity == 0)
        cout << " reached red headquarter with " << element << " elements and force " << force << endl;
    else
        cout << " marched to city " << addrCity << " with " << element << " elements and force " << force << endl;
}

int Warrior::WarriorMarch(int nHour, int nMinute)
{
    int occupationFlag = -1;
    if (pHeadquarter->getColor() == 0 && addrCity != (City::citytotal + 1))
    {
        addrCity += 1;
        if (addrCity == (City::citytotal + 1) && pHeadquarter->getOccupation() == 1)
            occupationFlag = 0;		// 已有两个红武士到达蓝方司令部
        else if (addrCity == (City::citytotal + 1) && pHeadquarter->getOccupation() == 0)
            occupationFlag = 2;		// 表示第一个红武士到达蓝方司令部
    }
    else if (pHeadquarter->getColor() == 1 && addrCity != 0)
    {
        addrCity -= 1;
        if (addrCity == 0 && pHeadquarter->getOccupation() == 1)
            occupationFlag = 1;		// 已有两个蓝武士到达红方司令部
        else if (addrCity == 0 && pHeadquarter->getOccupation() == 0)
            occupationFlag = 3;		// 表示第一个蓝武士到达红方司令部
    }
    addrForward += 1;										// 走过的步数加1
    if (addrForward % 2 == 0 && kindNo == 2)				// 如果是Iceman并且每前行两步, 那么执行Iceman特有属性
        IcemanDec();
    PrintMarch(nHour, nMinute);
    return occupationFlag;
}

void Warrior::EarnForHead(int EarnLife_)
{
    pHeadquarter->AddLife(EarnLife_);
}

void Warrior::PrintEarnForHead(int EarnLife_, int nHour, int nMinute)
{
    WarriorPrintPre(nHour, nMinute);
    cout << " earned " << EarnLife_ << " elements for his headquarter" << endl;
}

int Warrior::WarriorGetAward()
{
    int enough = 1;
    if (pHeadquarter->getTotalLifeValue() >= 8)
    {
        pHeadquarter->setTotalLifeValue(8);
        this->setElement(8);
    }
    if (pHeadquarter->getTotalLifeValue() < 8)
        enough = -1;
    return enough;
}

int Warrior::warriorHasArrow()
{
    for (int i = 0; i < weaponCount; i++)
    {
        if (weapon[i]->getWeaponUseful() && weapon[i]->getWeaponNo() == 2)
            return i;
    }
    return -1;
}

int Warrior::warriorArrowAttack(Warrior * uAAwarrior, int weaponnum, int nHour, int nMinute)
{
    int attackResult = uAAwarrior->Hurted(Arrow::arrowPower);
    updateWeapon(2);
    PrintArrowAttack(uAAwarrior, attackResult, nHour, nMinute);
    return attackResult;
}

void Warrior::PrintArrowAttack(Warrior * uAAwarrior, int attackResult, int nHour, int nMinute)
{
    WarriorPrintPre(nHour, nMinute);
    cout << " shot";
    if (attackResult == -1)		//  被攻击者死亡
        cout << " and killed " << (uAAwarrior->pHeadquarter)->GetColor() << " " << product_s[uAAwarrior->kindNo] << " " << uAAwarrior->no;
    cout << endl;
}

int Warrior::warriorHasBomb()
{
    for (int i = 0; i < weaponCount; i++)
    {
        if (weapon[i]->getWeaponUseful() && weapon[i]->getWeaponNo() == 1)
            return i;
    }
    return -1;
}

void Warrior::warriorBombAttack(Warrior * uBAwarrior, int weaponnum, int nHour, int nMinute)
{
    updateWeapon(1);
    this->element -= this->element;
    uBAwarrior->element -= this->element;
    PrintBombAttack(uBAwarrior, nHour, nMinute);
}

void Warrior::PrintBombAttack(Warrior * uBAwarrior, int nHour, int nMinute)
{
    WarriorPrintPre(nHour, nMinute);
    cout << " used a bomb and killed " << (uBAwarrior->pHeadquarter)->GetColor();
    cout << " " << product_s[uBAwarrior->kindNo] << " " << uBAwarrior->no << endl;
}

int Warrior::warriorHasSword()
{
    for (int i = 0; i < weaponCount; i++)
    {
        if (weapon[i]->getWeaponUseful() && weapon[i]->getWeaponNo() == 0)
            return i;
    }
    return -1;
}

void Headquarter::Init(int color_, int lifevalue_)
{
    Color_C = color_;
    totalLifeValue = lifevalue_;
    totalWarriorNum = 0;
    stopped = false;
    curMakingSeqIdx = 0;
    occupation = 0;
    for (int i = 0; i < WARRIOR_NUM; i++)
        warriorNum[i] = 0;
}

Headquarter::~Headquarter()
{
    for (int i = 0; i < totalWarriorNum; i++)
        delete pWarriors[i];
}

int Headquarter::Produce(int nHour, int nMinute)
{
    int kindNo = makingSeq[Color_C][curMakingSeqIdx];
    
    if (Warrior::initialLifeValue[kindNo] > totalLifeValue)
        return 0;
    //制作士兵：
    totalLifeValue -= Warrior::initialLifeValue[kindNo];
    curMakingSeqIdx = (curMakingSeqIdx + 1) % WARRIOR_NUM;
    
    if (kindNo == 0)
        pWarriors[totalWarriorNum] = new Dragon(this, totalWarriorNum + 1, kindNo, (double)totalLifeValue / Warrior::initialLifeValue[kindNo]);
    else if (kindNo == 1)
        pWarriors[totalWarriorNum] = new Ninjia(this, totalWarriorNum + 1, kindNo);
    else if (kindNo == 2)
        pWarriors[totalWarriorNum] = new Iceman(this, totalWarriorNum + 1, kindNo);
    else if (kindNo == 3)
        pWarriors[totalWarriorNum] = new Lion(this, totalWarriorNum + 1, kindNo, totalLifeValue);
    else if (kindNo == 4)
        pWarriors[totalWarriorNum] = new Wolf(this, totalWarriorNum + 1, kindNo);
    
    if (Color_C == 0) Headquarter::cityN[0]->setredWarrior(pWarriors[totalWarriorNum]);
    else if (Color_C == 1) Headquarter::cityN[City::citytotal + 1]->setblueWarrior(pWarriors[totalWarriorNum]);
    
    warriorNum[kindNo]++;
    pWarriors[totalWarriorNum]->PrintProduce(nHour, nMinute);
    totalWarriorNum++;
    
    return 1;
}

void Headquarter::UpdateCityWarrior()								// 每一次有删除武士或逃跑武士或行进, 清空武士之后对武士所在city进行更新
{
    for (int i = 0; i < totalWarriorNum; i++)
    {
        if (pWarriors[i] == NULL)
            continue;
        else if (pWarriors[i]->getAddrCity() < 0 || pWarriors[i]->getAddrCity() > (City::citytotal + 1))
        {
            pWarriors[i] = NULL;
            continue;
        }
        if (getColor() == 0 && pWarriors[i]->getAddrCity() <= City::citytotal)
            cityN[pWarriors[i]->getAddrCity()]->setredWarrior(pWarriors[i]);
        else if (getColor() == 1 && pWarriors[i]->getAddrCity() >= 1)
            cityN[pWarriors[i]->getAddrCity()]->setblueWarrior(pWarriors[i]);
        else if (getColor() == 0 && pWarriors[i]->getAddrCity() == (City::citytotal + 1) && pWarriors[i]->getNotReached())
        {
            occupation += 1;
            pWarriors[i]->setNotReached(false);
        }
        else if (getColor() == 1 && pWarriors[i]->getAddrCity() == 0 && pWarriors[i]->getNotReached())
        {
            occupation += 1;
            pWarriors[i]->setNotReached(false);
        }
    }
}

void Headquarter::PrintLifeValue(int nHour, int nMinute)
{
    cout << setfill('0') << setw(3) << nHour << ":" << setw(2) << nMinute << " ";
    cout << getTotalLifeValue() << " elements in " << GetColor() << " headquarter" << endl;
}

char * Headquarter::GetColor(void)
{
    return color[Color_C];
}

char * Weapon::weapon_list[WEAPON_NUM] = { (char *)"sword", (char *)"bomb", (char *)"arrow" };
char * Warrior::product_s[] = { (char *)"dragon", (char *)"ninja", (char *)"iceman", (char *)"lion", (char *)"wolf" };
int Warrior::initialLifeValue[WARRIOR_NUM];
int Warrior::initialForce[WARRIOR_NUM];
int Lion::decreaseLoyalty;
int City::citytotal;
City * Headquarter::cityN[CITY_NUM + 2];
int Headquarter::citiesN[CITY_NUM] = { 0 };
int Arrow::arrowPower;
int Headquarter::makingSeq[2][WARRIOR_NUM] = { { 2, 3, 4, 1, 0 },{ 3, 0, 1, 2, 4 } }; //两个司令部武士的制作顺序序列
char * Headquarter::color[] = { (char *)"red", (char *)"blue" };

inline void Test_Print()
{
    for (int i = 0; i <= (City::citytotal + 1); i++)
        Headquarter::cityN[i]->PrintEachCityAfterExec();
    cout << endl;
}

int main()
{
    int t, M, N, nTime;
    int casecount = 1;
    Headquarter RedHead, BlueHead;
    
    cin >> t;
    //t = 1;
    
    while (t--)
    {
        cout << "Case " << casecount << ":" << endl;
        casecount++;
        
        cin >> M >> N >> Arrow::arrowPower >> Lion::decreaseLoyalty >> nTime;
        /*M = 1000; N = 2; Arrow::arrowPower = 10; Lion::decreaseLoyalty = 2100; nTime = 5000;*/
        /*Warrior::initialLifeValue[0] = 100; Warrior::initialLifeValue[1] = 100; Warrior::initialLifeValue[2] = 100;
         Warrior::initialLifeValue[3] = 100; Warrior::initialLifeValue[4] = 100;
         Warrior::initialForce[0] = 5; Warrior::initialForce[1] = 5; Warrior::initialForce[2] = 5; Warrior::initialForce[3] = 5;
         Warrior::initialForce[4] = 5;*/
        for (int i = 0; i < WARRIOR_NUM; i++)
            cin >> Warrior::initialLifeValue[i];
        for (int i = 0; i < WARRIOR_NUM; i++)
            cin >> Warrior::initialForce[i];
        
        RedHead.Init(0, M);
        BlueHead.Init(1, M);
        City::citytotal = N;
        for (int i = 0; i < (N + 2); i++)
            Headquarter::cityN[i] = new City(0, i);
        
        int nHour = 0;
        int nMinute = 0;
        int test = 0;
        bool end = true;
        
        /*cout << "一开始:" << endl;
         Test_Print();
         cout << endl;*/
        
        while (end && nTime >= 0)
        {
            if (nMinute == 0)													// (1) 武士降生
            {
                RedHead.Produce(nHour, nMinute);
                BlueHead.Produce(nHour, nMinute);
            }
            else if (nMinute == 5)												// (2) lion逃跑
            {
                for (int i = 0; i <= N + 1; i++)
                    Headquarter::cityN[i]->CityRunAway(nHour, nMinute);
                
                RedHead.UpdateCityWarrior();
                BlueHead.UpdateCityWarrior();
            }
            else if (nMinute == 10)	// (3) 武士前进到某一城市; (12) 武士抵达敌军司令部; (13) 司令部被占领
            {
                int occupationFlag = -1;
                for (int i = 0; i <= N; i++)
                {
                    occupationFlag = Headquarter::cityN[i]->CityMarch(Headquarter::cityN[i + 1], nHour, nMinute);
                    if (occupationFlag == 0 || occupationFlag == 1)
                        end = false;
                }
                RedHead.UpdateCityWarrior();
                BlueHead.UpdateCityWarrior();
            }
            else if (nMinute == 20)												// 每个城市产出10个生命元
            {
                for (int i = 1; i <= N; i++)
                    Headquarter::cityN[i]->CityAddLife();
            }
            else if (nMinute == 30)												// 如果某个城市中只有一个武士,那么该武士取走该城市中的所有生命元,并立即将这些生命元传送到其所属的司令部
            {
                for (int i = 1; i <= N; i++)
                    Headquarter::cityN[i]->EarnLifeForHead(nHour, nMinute);
            }
            else if (nMinute == 35)												// (4) 武士放箭
            {
                for (int i = 1; i < N + 1; i++)
                    Headquarter::cityN[i]->CityArrowAttack(Headquarter::cityN[i - 1], Headquarter::cityN[i + 1], nHour, nMinute);
            }
            else if (nMinute == 38)												// (5) 武士使用bomb
            {
                for (int i = 1; i < N + 1; i++)
                    Headquarter::cityN[i]->CityBombAttack(nHour, nMinute);
            }
            else if (nMinute == 40)				// (6) 武士主动进攻; (7) 武士反击; (8) 武士战死; (9) 武士欢呼; (10) 武士获取生命元; (11) 旗帜升起
            {
                for (int i = 0; i < N + 1; i++)
                    Headquarter::cityN[i]->CityBattle(nHour, nMinute); // 判断战斗结果, = 0: 红武士胜; = 1: 蓝武士胜; = -1: 没有武士死亡或者没有交战; = 2: 红武士战前已经被射死, 蓝武士相当于胜利; = 3: 蓝武士战前已经被射死, 红武士相当于胜利; = 4: 红武士和蓝武士战前均被射死或炸死
                RedHead.UpdateCityWarrior();
                BlueHead.UpdateCityWarrior();
                int redAwardResult = 1;
                int blueAwardResult = 1;
                for (int i = 1; i <= N && blueAwardResult == 1; i++)	// 实质性的奖励获胜的武士, 蓝方先奖励city号小即离红方近的武士; 红方先奖励city号大即离蓝方近的武士
                    blueAwardResult = Headquarter::cityN[i]->CityAwardWarrior(1);		// 参数 = 0: 奖励红武士; = 1: 奖励蓝武士
                for (int i = N; i >= 1 && redAwardResult == 1; i--)
                    redAwardResult = Headquarter::cityN[i]->CityAwardWarrior(0);
                for (int i = 1; i <= N; i++)	// 实质性为Headquarter赢取生命元
                    Headquarter::cityN[i]->EarnLifeForHead(nHour, nMinute, 1);
            }
            else if (nMinute == 50)												// (14) 司令部报告生命元数量
            {
                RedHead.PrintLifeValue(nHour, nMinute);
                BlueHead.PrintLifeValue(nHour, nMinute);
            }
            else if (nMinute == 55)												// (15) 武士报告武器情况
            {
                for (int i = 0; i < N + 2; i++)
                    Headquarter::cityN[i]->CityReportWeapon(nHour, nMinute, 0);
                for (int i = 0; i < N + 2; i++)
                    Headquarter::cityN[i]->CityReportWeapon(nHour, nMinute, 1);
            }
            
            nMinute += 1;
            nTime -= 1;
            test += 1;
            if (nMinute == 60)
            {
                nMinute = 0;
                nHour += 1;
            }
        }
    }
    
    return 0;
}
