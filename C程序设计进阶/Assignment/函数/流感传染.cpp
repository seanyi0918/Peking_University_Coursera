//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 有一批易感人群住在网格状的宿舍区内，宿舍区为n*n的矩阵，每个格点为一个房间，房间里可能住人，也可能空着。在第一天，
 有些房间里的人得了流感，以后每天，得流感的人会使其邻居传染上流感，（已经得病的不变），空房间不会传染。请输出第m天得流感的人数。
 
 输入
 第一行一个数字n，n不超过100，表示有n*n的宿舍房间。
 接下来的n行，每行n个字符，’.’表示第一天该房间住着健康的人，’#’表示该房间空着，’@’表示第一天该房间住着得流感的人。
 接下来的一行是一个整数m，m不超过100.
 
 输出
 输出第m天，得流感的人数
 
 样例输入
 5
 ....#
 .#.@.
 .#@..
 #....
 .....
 4
 
 样例输出
 16
 */

#include <iostream>
using namespace std;

int main(void)
{
    int n, m;
    char a[100][100];
    char * b[100*100];
    int sum = 0;
    int sum_index = 0;
    
    cin >> n;
    
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < n; j++ )
            cin >> a[i][j];
    }
    
    cin >> m;
    
    for ( int k = 0; k < m - 1; k++ )
    {
        sum_index = 0;
        for ( int i = 0; i < n; i++ )
        {
            for ( int j = 0; j < n; j++ )
            {
                if ( a[i][j] == '@' )
                {
                    if ( i > 0 && a[i-1][j] == '.' )
                    {
                        b[sum_index] = &a[i-1][j];
                        sum_index = sum_index + 1;
                    }
                    if ( i < (n - 1) && a[i+1][j] == '.' )
                    {
                        b[sum_index] = &a[i+1][j];
                        sum_index = sum_index + 1;
                    }
                    if ( j > 0 && a[i][j-1] == '.' )
                    {
                        b[sum_index] = &a[i][j-1];
                        sum_index = sum_index + 1;
                    }
                    if ( j < (n - 1) && a[i][j+1] == '.' )
                    {
                        b[sum_index] = &a[i][j+1];
                        sum_index = sum_index + 1;
                    }
                }
            }
            
        }
        
        for ( int i = 0; i < sum_index; i++ )
        {
            if ( *b[i] == '.' )
                *b[i] = '@';
        }
    }
    
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < n; j++ )
        {
            if ( a[i][j] == '@' )
                sum += 1;
        }
    }
    
    cout << sum << endl;
    
    return 0;
}