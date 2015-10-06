//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 描述
 从键盘输入一指定金额（以元为单位，如345），然后输出支付该金额的各种面额的人民币数量，
 显示100元，50元，20元，10元，5元，1元各多少张，要求尽量使用大面额的钞票。
 
 输入
 一个小于1000的正整数。
 
 输出
 输出分行，每行显示一个整数，从上到下分别表示100元，50元，20元，10元，5元，1元人民币的张数
 
 样例输入
 735
 
 样例输出
 7
 0
 1
 1
 1
 0
 */

#include <iostream>
using namespace std;

int main()
{
    int n;
    int a[6] = {100, 50, 20, 10, 5, 1};
    int b[6] = {0};
    int i = 0;
    
    cin >> n;
    
    while ( n > 0 )
    {
        b[i] = n / a[i];
        n = n % a[i];
        i++;
    }
    
    for ( int j = 0; j < 6; j++ )
        cout << b[j] << endl;
    
    return 0;
}
