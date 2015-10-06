//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 
 描述
 
 输入一个0--100的分数，判断分数代表什么等级。
 
 95<=分数<=100, 输出1
 
 90<=分数<95,输出2
 
 85<=分数<90,输出3
 
 80<=分数<85,输出4
 
 70<=分数<80,输出5
 
 60<=分数<70输出6
 
 分数 < 60;输出7.
 
 输入
 n
 
 输出
 m
 
 样例输入
 87
 
 样例输出
 3
 */

#include <iostream>
using namespace std;

int main()
{
    int n, level;
    
    cin >> n;
    
    if ( n >= 95 && n <= 100 )
        level = 1;
    else if ( n >= 90 && n < 95 )
        level = 2;
    else if ( n >= 85 && n < 90 )
        level = 3;
    else if ( n >= 80 && n < 85 )
        level = 4;
    else if ( n >= 70 && n < 80 )
        level = 5;
    else if ( n >= 60 && n < 70 )
        level = 6;
    else if ( n < 60 )
        level = 7;
    
    cout << level << endl;
    
    return 0;
}
