//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 描述
 输入一个整数，判断它能否被3，5，7整除，并输出以下信息：
 1、能同时被3，5，7整除（直接输出3 5 7，每个数中间一个空格）；
 2、能被其中两个数整除（输出两个数，小的在前，大的在后。例如：3 5或者 3 7或者5 7,中间用空格分隔）
 3、能被其中一个数整除（输出这个除数）
 4、不能被任何数整除；（输出小写字符'n',不包括单引号)
 
 输入
 一个数字
 
 输出
 一行数字,从小到大排列,包含3,5,7中为该输入的除数的数字,数字中间用空格隔开
 
 样例输入
 
 第一组
 0
 第二组
 5
 第三组
 15
 第四组
 105
 第五组
 1
 样例输出
 
 第一组
 3 5 7
 第二组
 5
 第三组
 3 5
 第四组
 3 5 7
 第五组
 n
 提示
 
 因为有多组测试数据,程序通过下面方式读入n
 
 int n;
 while(cin>>n)
 {
 //你的代码
 }
 
 good luck:)
 */

#include <iostream>
using namespace std;

int main()
{
    int N;
    
    while ( cin >> N )
    {
        int flag = 0;
        
        for ( int i = 3; i < 9; i += 2 )
        {
            if ( N % i == 0 )
            {
                cout << i << " ";
                flag += 1;
            }
        }
        
        if ( flag == 0 )
            cout << 'n' << endl;
        else
            cout << endl;
    }
    
    return 0;
}
