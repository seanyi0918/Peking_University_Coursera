//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 描述
 
 对一个整数n,如果其各个位数的数字相加得到的数m能整除n,则称n为自整除数.例如21,21%(2+1)==0,
 所以21是自整除数.现求出从10到n(n < 100)之间的所有自整除数.
 
 输入
 
 有一行,整数n,(10 <= n < 100)
 
 输出
 
 有多行.按从小到大的顺序输出所有大于等于10,小于等于n的自整除数,每行一个自整除数.
 
 样例输入
 
 47
 样例输出
 
 10
 12
 18
 20
 21
 24
 27
 30
 36
 40
 42
 45
 */

#include <iostream>
using namespace std;

int main()
{
    int n, shiwei = 1, gewei = 0;
    
    cin >> n;
    
    for ( int i = 10; i <= n; i++ )
    {
        shiwei = i / 10;
        gewei = i % 10;
        
        if ( i % (shiwei + gewei) == 0 )
            cout << i << endl;
    }
    
    return 0;
}
