//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 描述
 甲壳虫的《A day in the life》和《Tomorrow never knows》脍炙人口，
 如果告诉你a day in the life,真的会是tomorrow never knows? 相信学了计概之后这个不会是难题，现在就来实现吧。
 
 读入一个格式为yyyy-mm-dd的日期（即年－月－日），输出这个日期下一天的日期。可以假定输入的日期不早于1600-01-01，也不晚于2999-12-30。
 
 输入
 
 输入仅一行，格式为yyyy-mm-dd的日期。
 
 输出
 
 输出也仅一行，格式为yyyy-mm-dd的日期
 
 样例输入
 
 2010-07-05
 样例输出
 
 2010-07-06
 提示
 
 闰年的标准:
 (1)普通年能被4整除且不能被100整除的为闰年。（如2004年就是闰年,1901年不是闰年）
 
 地球公转示意图
 
 (2)世纪年能被400整除的是闰年。(如2000年是闰年，1100年不是闰年)
 
 输入语句scanf("%d-%d-%d",&y,&m,&d)可以存储年，月，日．输出语句格式类似printf("%d-%02d-%02d\n",year,month,day)．
 */

#include <iostream>
#include <cstdlib>
using namespace std;

int leapyear(int);
int * getY_M_D(char[]);
int * getmonthvalue(int);
char * charvalue(int);
char int_to_char(int);

int main(void)
{
    char date[] = {'2', '0', '0', '0' , '-', '0', '4', '-', '3', '0', '\0'};
    cin >> date;
    
    int * y_m_d = getY_M_D(date); // Year: y_m_d[0]; Month: y_m_d[1]; Day: y_m_d[2];
    int year = y_m_d[0];
    int month = y_m_d[1];
    int day = y_m_d[2];
    
    int leap = leapyear(y_m_d[0]); // leap = 1, leapyear; leap = 0, Not leapyear;
    int * lpmonth = getmonthvalue(leap);  // get month days according to leap year
    
    if ( day == lpmonth[month - 1] ) // if current day is the last day of the month, got to the next month
    {
        day = 1;
        month = month + 1;
        if ( month > 12 )            // if the next month is beyond December, then go to the next year
        {
            month = 1;
            year = year + 1;
        }
    }
    else                             // if not the last day of the month, go to the next day
    {
        day = day + 1;
    }
    
    cout << charvalue(year) << "-" << charvalue(month) << "-" << charvalue(day) << endl;
    
    
    return 0;
}

int leapyear(int year)
{
    int leapyear = 0;
    
    if ( year % 4 == 0 )
    {
        leapyear = 1;
        
        if ( year % 100 == 0 )
            leapyear = 0;
        
        if ( year % 400 == 0 )
            leapyear = 1;
    }
    
    return leapyear;
}

int * getY_M_D(char date[])
{
    int i = 0;
    int * y_m_d = new int[3];
    char Year[5];
    char Month[3];
    char Day[3];
    
    for ( int j = 0; date[i] != '-'; i++, j++ )
        Year[j] = date[i];
    
    i = i + 1;
    for ( int j = 0; date[i] != '-'; i++, j++ )
        Month[j] = date[i];
    
    i = i + 1;
    for ( int j = 0; date[i] != '\0'; i++, j++ )
        Day[j] = date[i];
    
    y_m_d[0] = atoi(Year);
    y_m_d[1] = atoi(Month);
    y_m_d[2] = atoi(Day);
    
    return y_m_d;
}

int * getmonthvalue(int leap)
{
    int * monthvalue = new int[12];
    int pmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int lmonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if ( leap == 0 )
        monthvalue = pmonth;
    else
        monthvalue = lmonth;
    
    return monthvalue;
}

char * charvalue(int num)
{
    char * cha = new char[3];
    if ( num < 10 )
    {
        cha[0] = '0';
        cha[1] = int_to_char(num);
        cha[2] = '\0';
    }
    else if ( num < 32 )
    {
        cha[0] = int_to_char(num / 10);
        cha[1] = int_to_char(num % 10);
        cha[2] = '\0';
    }
    else if ( num > 1599 && num < 3000 )
    {
        cha[0] = int_to_char(num / 1000);
        num = num % 1000;
        cha[1] = int_to_char(num / 100);
        num = num % 100;
        cha[2] = int_to_char(num / 10);
        cha[3] = int_to_char(num % 10);
    }
    
    return cha;
}

char int_to_char(int num)
{
    char a[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    return a[num];
}