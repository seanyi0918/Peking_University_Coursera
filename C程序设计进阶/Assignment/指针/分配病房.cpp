//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 
 描述
 
 某个科室的病房分为重症和普通，只有当病人的疾病严重程度超过了入住重症病房的最低严重值，才可以安排入住重症病房。
 
 现在要求设计一个程序，给病人安排好病房。疾病的严重程度用0到10来表示，0表示小毛病，10表示非常严重。
 
 输入
 
 第一行输入病人的个数m(m < 50)，以及安排住入重症病房的最低严重值a
 
 紧接着m行，每行表示病人编号（三个位，用0补齐）及其疾病的严重程度（浮点数，1位小数）。
 
 每个病人的疾病严重程度都不一样。
 
 输出
 
 要求按照病人的严重程度输出住在重症病房里的病人的编号
 
 注意：
 
 如果当前所有病人的严重程度并不满足住在重症病房里，则输出“None.”（不包括引号）
 
 样例输入
 
 10 7.55
 006 6.5
 005 8.0
 004 3.5
 009 8.5
 011 7.0
 043 9.5
 003 5.0
 103 6.0
 112 4.0
 118 9.0
 样例输出
 
 043 9.5
 118 9.0
 009 8.5
 005 8.0
 
 */

#include <iostream>
#include <iomanip>
using namespace std;

void change_id(char *patient_id1, char *patient_id2, int n);  // 换行, 将病人严重程度高的编号相换的函数

int main(void)
{
    int m, flag = 0;
    float a;
    
    cin >> m >> a;
    
    char (*patient)[4] = new char[m+1][4];  // 保存每个病人的编号
    float *illness = new float[m+1];        // 保存每个病人的疾病严重程度
    
    for ( int i = 0; i < m; i++ )
    {
        cin >> patient[i] >> illness[i];
    }
    
    for ( int i = 0; i < m; i++ )
    {
        if ( illness[i] < a )
            continue;
        else
        {
            flag = 1;
            for ( int j = i; j < m; j++ )
            {
                if ( illness[j] < a )
                    continue;
                else if ( illness[i] < illness[j] )
                {
                    float tmp = illness[i];
                    illness[i] = illness[j];
                    illness[j] = tmp;
                    
                    change_id(patient[i], patient[j], 4);
                }
            }
        }
    }
    
    for ( int i = 0; i < m; i++ )
    {
        if ( illness[i] >= a )
        {
            cout << patient[i] << " " << fixed << setprecision(1) << illness[i] << endl;
        }
    }
    
    if ( flag == 0 )
        cout << "None." << endl;
    
    return 0;
}

void change_id(char *patient1, char *patient2, int n)
{
    for ( int i = 0; patient1[i] != '\0'; i++ )
    {
        char patientmp = patient1[i];
        patient1[i] = patient2[i];
        patient2[i] = patientmp;
    }
}