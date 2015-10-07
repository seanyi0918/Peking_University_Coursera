//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 
 描述
 
 在一个m×n的山地上，已知每个地块的平均高程，请求出所有山顶所在的地块（所谓山顶，就是其地块平均高程不比其上下左右相邻的四个地块每个地块的平均高程小的地方)。
 
 输入
 
 第一行是两个整数，表示山地的长m（5≤m≤20）和宽n（5≤n≤20）。
 
 其后m行为一个m×n的整数矩阵，表示每个地块的平均高程。每行的整数间用一个空格分隔。
 
 输出
 
 输出所有上顶所在地块的位置。每行一个。按先m值从小到大，再n值从小到大的顺序输出。
 
 样例输入
 
 10 5
 0 76 81 34 66
 1 13 58 4 40
 5 24 17 6 65
 13 13 76 3 20
 8 36 12 60 37
 42 53 87 10 65
 42 25 47 41 33
 71 69 94 24 12
 92 11 71 3 82
 91 90 20 95 44
 样例输出
 
 0 2
 0 4
 2 1
 2 4
 3 0
 3 2
 4 3
 5 2
 5 4
 7 2
 8 0
 8 4
 9 3
 
 */

#include <iostream>
using namespace std;

int main(void)
{
    int m, n;   // 山地的长为m, 宽为n, 5≤m≤20, 5≤n≤20;
    cin >> m >> n;
    
    int *matrix = new int[m*n]; // 用来存放输入矩阵
    int *flag = new int[m*n];   // 用来表示每个山地是否为山顶
    
    for ( int i = 0; i < m; i++ )
    {
        for ( int j = 0; j < n; j++ )
        {
            cin >> *(matrix + n*i + j);
            *(flag + n*i + j) = 1;       // 先假设所有的山地均为山顶
        }
    }
    
    for ( int i = 0; i < m; i++ )
    {
        for ( int j = 0; j < n; j++ )
        {
            if ( *(flag + n*i +j) == 0 )    // 已经遍历过或不为该区域最大值, 即已被证明不可能为山顶, 略过
                continue;
            else
            {
                if ( j > 0 && *(matrix + n*i + j-1) > *(matrix + n*i + j) ) // 遍历左边值大于当前值则略过并设当前山flag=0
                    *(flag + n*i + j) = 0;
                else if ( j > 0 && *(matrix + n*i + j-1) < *(matrix + n*i + j) )
                    *(flag + n*i + j-1) = 0;
                
                if ( i > 0 && *(matrix + (i-1)*n + j) > *(matrix + n*i + j) )   // 上边
                    *(flag + n*i + j) = 0;
                else if ( i > 0 && *(matrix + (i-1)*n + j) < *(matrix + n*i + j) )   // 上边
                    *(flag + n*(i-1) + j) = 0;
                
                if ( j < (n-1) && *(matrix + i*n + j+1) > *(matrix + n*i + j) ) // 右边
                    *(flag + n*i + j) = 0;
                else if ( j < (n-1) && *(matrix + i*n + j+1) > *(matrix + n*i + j) ) // 右边
                    *(flag + n*i + j+1) = 0;
                
                if ( i < (m-1) && *(matrix + (i+1)*n + j) > *(matrix + n*i + j) )   // 下边
                    *(flag + n*i + j) = 0;
                else if ( i < (m-1) && *(matrix + (i+1)*n + j) > *(matrix + n*i + j) )   // 下边
                    *(flag + n*(i+1) + j) = 0;
                // 上下左右遍历完为最大, 可以不做任何处理, 因为初始化时默认为山顶
            }
        }
    }
    
    for ( int i = 0; i < m; i++ )
    {
        for ( int j = 0; j < n; j++ )
        {
            if ( *(flag + n*i +j) == 1 )
                cout << i << " " << j << endl;
        }
    }
    
    return 0;
}