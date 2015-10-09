//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 
 描述
 在一个学生信息处理程序中，要求实现一个代表学生的类，并且所有成员变量都应该是私有的。
 
 （注：评测系统无法自动判断变量是否私有。我们会在结束之后统一对作业进行检查，请同学们严格按照题目要求完成，否则可能会影响作业成绩。）
 
 输入
 姓名，年龄，学号，第一学年平均成绩，第二学年平均成绩，第三学年平均成绩，第四学年平均成绩。
 其中姓名、学号为字符串，不含空格和逗号；年龄为正整数；成绩为非负整数。
 各部分内容之间均用单个英文逗号","隔开，无多余空格。
 
 输出
 一行，按顺序输出：姓名，年龄，学号，四年平均成绩（向下取整）。
 各部分内容之间均用单个英文逗号","隔开，无多余空格。
 
 样例输入
 Tom,18,7817,80,80,90,70
 
 样例输出
 Tom,18,7817,80
 
 */

#include<iostream>
#include <cstdlib>
using namespace std;

class student
{
private:
    char * name;
    int age;
    char * id;
    int score;
    
public:
    void Init(char * str);
    void setscore(int * score_, int count);
    int getscore(void);
    char * getname(void);
    int getage(void);
    char * getid(void);
};

int main(void)
{
    char * str = new char[255];
    
    cin >> str;
    
    student Tom;
    
    Tom.Init(str);
    
    cout << Tom.getname() << "," << Tom.getage() << "," << Tom.getid() << "," << Tom.getscore() << endl;
    
    return 0;
}

void student::Init(char * str)
{
    int i = 0;                                              // 计数器
    int si = 0;                                             // score计数器
    int * score_ = new int[4];                              // 用来保存每学年成绩
    
    int j = i;                                              // 获取学生姓名
    while ( str[i] != ',' )
        i++;
    char *newname = new char[i - j];
    for ( int ic = 0; ic < i; ic++ )
        newname[ic] = str[ic];
    newname[i] = '\0';
    name = newname;
    //delete[] newname;
    
    j = i;                                              // 获取学生年龄
    i++;
    while ( str[i] != ',' )
        i++;
    char *newage = new char[i - j];
    for ( int ic = 0; ic < (i - j - 1); ic++ )
        newage[ic] = str[ic + j + 1];
    newage[i - j - 1] = '\0';
    age = atoi(newage);
    delete[] newage;
    
    j = i;                                              // 获取学生学号
    i++;
    while ( str[i] != ',' )
        i++;
    char *newid = new char[i - j];
    for ( int ic = 0; ic < (i - j - 1); ic++ )
        newid[ic] = str[ic + j + 1];
    newid[i - j - 1] = '\0';
    id = newid;
    
    j = i;
    i++;
    while ( str[i] != ',' )
        i++;
    char *newscore = new char[i - j];
    for ( int ic = 0; ic < (i - j - 1); ic++ )
        newscore[ic] = str[ic + j + 1];
    newscore[i - j - 1] = '\0';
    score_[si++] = atoi(newscore);
    delete[] newscore;
    
    j = i;
    i++;
    while ( str[i] != ',' )
        i++;
    newscore = new char[i - j];
    for ( int ic = 0; ic < (i - j - 1); ic++ )
        newscore[ic] = str[ic + j + 1];
    newscore[i - j - 1] = '\0';
    score_[si++] = atoi(newscore);
    delete[] newscore;
    
    j = i;
    i++;
    while ( str[i] != ',' )
        i++;
    newscore = new char[i - j];
    for ( int ic = 0; ic < (i - j - 1); ic++ )
        newscore[ic] = str[ic + j + 1];
    newscore[i - j - 1] = '\0';
    score_[si++] = atoi(newscore);
    delete[] newscore;
    
    j = i;
    i++;
    while ( str[i] != '\0' )
        i++;
    newscore = new char[i - j];
    for ( int ic = 0; ic < (i - j - 1); ic++ )
        newscore[ic] = str[ic + j + 1];
    newscore[i - j - 1] = '\0';
    score_[si++] = atoi(newscore);
    delete[] newscore;
    
    setscore(score_, 4);
}

void student::setscore(int *score_, int count_)
{
    int sum = 0;
    for ( int count = 0; count < count_; count++ )
        sum += score_[count];
    
    score = sum / count_;
}

int student::getscore(void)
{
    return score;
}

char * student::getname(void)
{
    return name;
}

int student::getage(void)
{
    return age;
}

char * student::getid(void)
{
    return id;
}