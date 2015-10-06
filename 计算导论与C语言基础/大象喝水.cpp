//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 
 描述
 
 一只大象口渴了，要喝20升水才能解渴，但现在只有一个深h厘米，底面半径为r厘米的小圆桶(h和r都是整数)。问大象至少要喝多少桶水才会解渴。
 
 输入
 
 输入有一行：包行两个整数，以一个空格分开，分别表示小圆桶的深h和底面半径r，单位都是厘米。
 
 输出
 
 输出一行，包含一个整数，表示大象至少要喝水的桶数。
 
 */
#include <iostream>
#define PI 3.14159
#define WO 20000
using namespace std;


int main(int argc, const char * argv[])
{
    double h, r, result, volume;
    
    cin >> h >> r;
    
    volume = PI * r * r * h;
    
    result = WO/volume + 1;
    
    cout << int(result) << endl;
    
    return 0;
}
