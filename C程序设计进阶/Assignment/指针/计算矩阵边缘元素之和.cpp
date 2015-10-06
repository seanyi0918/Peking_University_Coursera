//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 描述
 输入一个整数矩阵，计算位于矩阵边缘的元素之和。所谓矩阵边缘的元素，就是第一行和最后一行的元素以及第一列和最后一列的元素。
 
 输入
 
 第一行为整数k，表示有k组数据。
 
 每组数据有多行组成，表示一个矩阵：
 
 第一行分别为矩阵的行数m和列数n（m < 100，n < 100），两者之间以空格分隔。
 
 接下来输入的m行数据中，每行包含n个整数，整数之间以空格作为间隔。
 
 输出
 
 输出对应矩阵的边缘元素和，一个一行。
 
 样例输入
 
 2
 4 4
 1 1 1 1
 0 0 0 0
 1 0 1 0
 0 0 0 0
 3 3
 3 4 1
 3 7 1
 2 0 1
 样例输出
 
 5
 15 */

#include <iostream>
using namespace std;

int calSumEdge(int *, int, int);

int main(void)
{
    int N, m, n;
    
    cin >> N;
    
    for ( int count = 0; count < N; count++ )
    {
        cin >> m >> n;
        int * matrix = new int(m*n);
        
        for ( int i = 0; i < m; i++ )
        {
            for ( int j = 0; j < n; j++ )
            {
                cin >> *(matrix + i * m + j);
            }
        }
        
        cout << calSumEdge(matrix, m, n) << endl;
    }
    
    return 0;
}

int calSumEdge(int * matrix, int m, int n)
{
    int sum = 0;
    
    for ( int i = 0; i < m; i++ )
    {
        for ( int j = 0; j < n; j++ )
        {
            if ( i == 0 || i == (m - 1) || j == 0 || j == (n - 1) )
                sum += *(matrix + m * i + j);
        }
    }
    
    return sum;
}