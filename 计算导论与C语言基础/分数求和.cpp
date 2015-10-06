//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 
 描述
 
 输入n个分数并对他们求和，用约分之后的最简形式表示。
 
 比如：
 
 q/p = x1/y1 + x2/y2 +....+ xn/yn，
 
 q/p要求是归约之后的形式。
 
 如：5/6已经是最简形式，3/6需要规约为1/2, 3/1需要规约成3，10/3就是最简形式。
 
 PS:分子和分母都没有为0的情况，也没有出现负数的情况
 
 输入
 
 第一行的输入n,代表一共有几个分数需要求和
 
 接下来的n行是分数
 
 输出
 
 输出只有一行，即归约后的结果
 
 */

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sumn = 0, sumd = 1;//储存结果，sumn/sumd
    
    while (n--)
    {
        int num, deno;
        char slash;//专门用来吃掉/的
        cin >> num >> slash >> deno;
        //先相加 a/b + c/d = (a*d+c*b)/(b*d)
        sumn = sumn*deno + num*sumd;
        sumd = sumd*deno;
    }
    //后约分
    //先求最大公约数gcd，这里用的是欧几里得法
    int a = sumd, b = sumn, c;
    while (a != 0)
    {
        c = a; a = b%a; b = c;
    }
    int gcd = b;
    //分子分母同时除以gcd就可以完成约分
    sumd /= gcd;
    sumn /= gcd;
    if (sumd > 1)
        cout << sumn << '/' << sumd << endl;
    else
        cout << sumn << endl;
    return 0;
}
