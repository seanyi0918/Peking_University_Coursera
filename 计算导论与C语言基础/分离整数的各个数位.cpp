//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 
 描述
 
 从键盘输入一个任意的三位整数，要求正确地分离出它的百位、十位和个位数，并分别在屏幕上输出，输出采用每行输出一个数的方式，不带其它符号。
 
 输入
 
 一个任意的三位整数
 
 输出
 
 一个任意的三位整数
 
 */
#include <iostream>
using namespace std;


int main(int argc, const char * argv[])
{
    int i, N, n;
    i = 0;
    N = 100;
    int a[3];
    
    cin >> n;
    
    if ( n >= 100 && n < 1000 )
    {
        while ( n > 0 && N > 0 && i < 3 )
        {
            a[i] = n / N;
            n = n % N;
            N = N / 10;
            i++;
        }
    }
    
    for ( int j = 0; j < 3; j++ )
        cout << a[j] << endl;
    
    return 0;
}
