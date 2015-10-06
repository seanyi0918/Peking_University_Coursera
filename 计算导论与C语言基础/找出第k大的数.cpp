//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 描述
 
 用户输入N和K，然后接着输入N个正整数（无序的），程序在不对N个整数排序的情况下，找出第K大的数。
 注意，第K大的数意味着从大到小排在第K位的数。
 
 输入
 N
 K
 a1 a2 a3 a4 ..... aN
 输出
 b
 
 样例输入
 5
 2
 32 3 12 5 89
 
 样例输出
 32
 */

#include <iostream>
using namespace std;

int main()
{
    int n, k, a[1000], temp;
    
    cin >> n >> k;
    
    for ( int i = 0; i < n; i++ )
        cin >> a[i];
    
    for ( int i = 0 ; i < k; i++ )
    {
        for ( int j = i; j < n; j++ )
        {
            if ( a[j] > a[i] )
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
    
    cout << a[k - 1] << endl;
    
    return 0;
}
