//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 
 描述
 
 输入二个正整数m 和 k，其中1 < m < 100000，1 < k <5 ，判断m 能否被19整除，且恰好含有k个3，如果满足条件，则输出YES，否则，输出NO。
 
 例如，输入：
 
 43833 3
 
 满足条件，输出YES
 
 如果输入
 
 39331 3
 
 尽管有3个3，但不能被19整除，也不满足条件，应输出NO
 
 输入
 
 m 和 k 的值，空格间隔
 
 输出
 
 满足条件时输出 YES，不满足时输出 NO
 
 样例输入
 
 43833 3
 样例输出
 
 YES
 
 */

#include <iostream>
using namespace std;

bool n_k(int num, int k);

int main(void)
{
    int m, k;   // 1 < m < 100000, 1 < k < 5
    cin >> m >> k;
    
    if ( (m % 19 == 0) && n_k(m, k) )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}

bool n_k(int num, int k)
{
    int nk = 0;
    
    while ( num / 10 > 0 )
    {
        if ( (num % 10) == 3 )
            nk++;
        num /= 10;
    }
    
    if ( num == 3 )
        nk++;
    
    return (nk == k);
}