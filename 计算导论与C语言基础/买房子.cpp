//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 描述
 
 某程序员开始工作，年薪N万，他希望在中关村公馆买一套60平米的房子，现在价格是200万，假设房子价格以每年百分之K增长，
 并且该程序员未来年薪不变，且不吃不喝，不用交税，每年所得N万全都积攒起来，问第几年能够买下这套房子（第一年房价200万，收入N万）。程序员每年先拿工资，再尝试买房，然后房子才涨价。
 
 输入
 
 有多行，每行两个整数N（10 <= N <= 50）, K（1 <= K <= 20）
 
 输出
 
 针对每组数据，如果在第20年或者之前就能买下这套房子，则输出一个整数M，表示最早需要在第M年能买下，否则输出Impossible，输出需要换行
 
 样例输入
 
 50 10
 40 10
 40 8
 样例输出
 
 8
 Impossible
 10
 提示
 
 注意数据类型，应当使用浮点数来保存结果
 
 C++里多行输入（在不知道一共有多少行的情况下）可以使用下面的语句，每输入一组数据就可以输出其结果，不用等待所有数据都输入完毕。
 
 while(cin>>N>>K){
 //do your magic
 }
 */

#include <iostream>
using namespace std;

int main()
{
    int N, K, payout, year;
    double yearly_inc, total;
    
    while ( cin >> N >> K )
    {
        payout = N;
        year = 1;
        total = 200.0;
        yearly_inc = (double)K / 100.0;
        
        while ( payout < total && year <= 20 )
        {
            payout = payout + N;
            total = total * (1.0 + yearly_inc);
            year++;
        }
        
        if ( year <= 20 )
            cout << year << endl;
        else
            cout << "Impossible" << endl;
    }
    
    return 0;
}
