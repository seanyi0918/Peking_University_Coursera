//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 描述
 
 有一种细菌分为A、B两个亚种，它们的外在特征几乎完全相同，仅仅在繁殖能力上有显著差别，A亚种繁殖能力非常强，B亚种的繁殖能力很弱。在一次为时一个 小时的细菌繁殖实验中，实验员由于疏忽把细菌培养皿搞乱了，请你编写一个程序，根据实验结果，把两个亚种的培养皿重新分成两组。
 
 输入
 
 输入有多行，第一行为整数n（n≤100），表示有n个培养皿。
 
 其余n行，每行有三个整数，分别代表培养皿编号，试验前细菌数量，试验后细菌数量。
 
 输出
 
 输出有多行：
 
 第一行输出A亚种培养皿的数量，其后每行输出A亚种培养皿的编号，按繁殖率升序排列。
 
 然后一行输出B亚种培养皿的数量，其后每行输出B亚种培养皿的编号，也按繁殖率升序排列。
 
 样例输入
 
 5
 1 10 3456
 2 10 5644
 3 10 4566
 4 20 234
 5 20 232
 样例输出
 
 3
 1
 3
 2
 2
 5
 4
 提示
 
 亚种内部，细菌繁殖能力差异远远小于亚种之间细菌繁殖能力的差异。
 
 也就是说，亚种间任何两组细菌的繁殖率之差都比亚种内部两组细菌的繁殖率之差大。
 */

#include <iostream>
using namespace std;

float abs_x(float);

int main(void)
{
    int n;
    float dis_max = 0.0;
    float dis = 0.0;
    int dis_index = 0;
    float a[101];
    int b[101];
    
    cin >> n;
    
    for ( int i = 0; i < n; i++ )
    {
        int num;
        float before, after;
        float rate;
        cin >> num >> before >> after;
        rate = (after - before) / before;
        a[i] = rate;
        b[i] = num;
    }
    
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = i + 1; j < n; j++ )
        {
            if ( a[i] < a[j] )
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }
    }
    
    for ( int i = 0; i < n - 1; i++ )
    {
        dis = abs_x(a[i + 1] - a[i]);
        if ( dis > dis_max )
        {
            dis_max = dis;
            dis_index = i;
        }
    }
    
    cout << (dis_index + 1) << endl;
    for ( int i = dis_index; i >= 0; i-- )
        cout << b[i] << endl;
    
    cout << (n - dis_index - 1) << endl;
    for ( int i = n - 1; i > dis_index; i-- )
        cout << b[i] << endl;
    
    return 0;
}

float abs_x(float dis)
{
    if ( dis < 0 )
        dis = 0 - dis;
    
    return dis;
}