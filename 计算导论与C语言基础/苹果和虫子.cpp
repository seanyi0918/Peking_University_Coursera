//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 描述
 你买了一箱n个苹果，很不幸的是买完时箱子里混进了一条虫子。虫子每x小时能吃掉一个苹果，假设虫子在吃完一个苹果之前不会吃另一个，那么经过y小时你还有多少个完整的苹果？
 
 输入
 
 输入仅一行，包括n，x和y（均为整数）。
 
 输出
 
 输出也仅一行，剩下的苹果个数*/
#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    // n: # of apples; x: rate that worm eats; y: time after
    int n, x, y;
    
    cin >> n >> x >> y;
    
    if ( y % x == 0 )
        n = n - y/x;
    else
        n = n - y/x - 1;
    
    if ( n < 0 )
        n = 0;
    
    cout << n << endl;
    
    return 0;
}
