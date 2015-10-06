//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 
 描述
 
 输入6个正整数，且这6个正整数中至少存在一个奇数和一个偶数。
 
 设这6个正整数中最大的奇数为a，最小的偶数为b，求出|a-b|的值
 
 输入
 
 输入为一行，6个正整数,且6个正整数都小于100
 
 输入保证这6个数中至少存在一个奇数和一个偶数
 
 输出
 
 输出为一行，输出最大的奇数与最小的偶数之差的绝对值
 
 */
#include <iostream>
using namespace std;


int main(int argc, const char * argv[])
{
    int max, min, n, temp;
    n = 6;
    max = 0;
    min = 100;
    
    for ( int i = 0; i < n; i++ )
    {
        cin >> temp;
        if ( temp % 2 == 0 && temp < min)
            min = temp;
        else if ( temp % 2 == 1 && temp > max )
            max = temp;
    }
    
    if ( (max - min) > 0 )
        cout << max - min << endl;
    else
        cout << min - max << endl;
    
    return 0;
}
