//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 
 描述
 
 给定一个row行col列的整数数组array，要求从array[0][0]元素开始，按从左上到右下的对角线顺序遍历整个数组。
 
 输入
 
 输入的第一行上有两个整数，依次为row和col。
 
 余下有row行，每行包含col个整数，构成一个二维整数数组。
 
 （注：输入的row和col保证0 < row < 100, 0 < col < 100）
 
 输出
 
 按遍历顺序输出每个整数。每个整数占一行。
 
 样例输入
 
 3 4
 1 2 4 7
 3 5 8 10
 6 9 11 12
 样例输出
 
 1
 2
 3
 4
 5
 6
 7
 8
 9
 10
 11
 12
 
 */

#include <iostream>
using namespace std;
const int maxn = 100;
int matrix[maxn][maxn];         // 用来保存输入值
int matrix_x[maxn * maxn][2];   // 缓冲区buffer, 用来保存等待遍历的元素
int matrix_y[maxn][maxn];       // 用来保存是否已经输出
int scount = 1;                 // 用来保存缓冲区的当前指针
int tcount = 0;                 // 用来保存当前在缓冲区内已经被遍历的元素指针

void run_through(int i, int j, int m, int n);

int main(void)
{
    int m, n;
    
    cin >> m >> n;
    
    for ( int i = 0; i < m; i++ )
    {
        for ( int j = 0; j < n; j++ )
        {
            cin >> matrix[i][j];
            matrix_y[i][j] = 1;
        }
    }
    
    //    matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 4; matrix[0][3] = 7;
    //    matrix[1][0] = 3; matrix[1][1] = 5; matrix[1][2] = 8; matrix[1][3] = 10;
    //    matrix[2][0] = 6; matrix[2][1] = 9; matrix[2][2] = 11; matrix[2][3] = 12;
    //    matrix_y[0][0] = 1; matrix_y[0][1] = 1; matrix_y[0][2] = 1; matrix_y[0][3] = 1;
    //    matrix_y[1][0] = 1; matrix_y[1][1] = 1; matrix_y[1][2] = 1; matrix_y[1][3] = 1;
    //    matrix_y[2][0] = 1; matrix_y[2][1] = 1; matrix_y[2][2] = 1; matrix_y[2][3] = 1;
    //    for ( int i = 0; i < 3; i++ )
    //    {
    //        for ( int j = 0; j < 4; j++ )
    //        {
    //            cout << matrix[i][j] << " ";
    //        }
    //        cout << endl;
    //    }
    
    run_through(0, 0, m, n);
    
    //    cout << scount << " " <<  tcount << endl;
    
    return 0;
}

void run_through(int i, int j, int m, int n)
{
    //    cout << "i = " << i << "; j = " << j << "; matrix_y[i][j] = " << matrix_y[i][j] << "; tcount = " << tcount << "scount = " << scount << endl;
    if ( tcount == scount )
        return;
    
    int flag = 1;
    
    if ( matrix_y[i][j] == 1 )
    {
        cout << matrix[i][j] << endl;
        //        cout << "这是输出结果:" << matrix[i][j] << endl;
        matrix_y[i][j] = 0;
    }
    
    
    if ( j < (n - 1) && matrix_y[i][j+1] == 1 )
    {
        //                cout << "进入右" << endl;
        //                cout << "此时i = " << i << "; j = " << j << "; scount = " << scount << endl;
        //cout << matrix[i][j+1] << endl;
        for ( int h = tcount; h < scount; h++ )
        {
            if ( matrix_x[h][0] == i && matrix_x[h][1] == (j+1) )
            {
                flag = 0;
                break;
            }
        }
        if ( flag == 1 )
        {
            matrix_x[scount][0] = i;
            matrix_x[scount][1] = j + 1;
            scount++;
        }
        
        flag = 1;
        
        //        cout << "matrix_x[1][0] = " << matrix_x[scount][0] << endl;
        //        cout << "matrix_x[1][1] = " << matrix_x[scount][1] << endl;
        //        cout << scount << " " << tcount << "sss" << endl;
    }
    
    if ( i > 0 && matrix_y[i-1][j] == 1 )
    {
        //                cout << "进入上" << endl;
        //                cout << "此时i = " << i << "; j = " << j << "; scount = " << scount << endl;
        //cout << matrix[i-1][j];
        for ( int h = tcount; h < scount; h++ )
        {
            if ( matrix_x[h][0] == (i-1) && matrix_x[h][1] == j )
            {
                flag = 0;
                break;
            }
        }
        if ( flag == 1 )
        {
            matrix_x[scount][0] = i - 1;
            matrix_x[scount][1] = j;
            //        cout << scount << " " << tcount << "sss" << endl;
            scount++;
        }
        flag = 1;
    }
    
    
    if ( j > 0 && matrix_y[i][j-1] == 1 )
    {
        //                cout << "进入左" << endl;
        //                cout << "此时i = " << i << "; j = " << j << "; scount = " << scount << endl;
        //cout << matrix[i][j-1] << endl;
        for ( int h = tcount; h < scount; h++ )
        {
            if ( matrix_x[h][0] == i && matrix_x[h][1] == (j-1) )
            {
                flag = 0;
                break;
            }
        }
        if ( flag == 1 )
        {
            matrix_x[scount][0] = i;
            matrix_x[scount][1] = j - 1;
            //        cout << scount << " " << tcount << "sss" << endl;
            scount++;
        }
        flag = 1;
    }
    
    
    if ( i < (m - 1) && matrix_y[i+1][j] == 1 )
    {
        //                cout << "进入下" << endl;
        //                cout << "此时i = " << i << "; j = " << j << "; scount = " << scount << endl;
        //cout << matrix[i+1][j] << endl;
        for ( int h = tcount; h < scount; h++ )
        {
            if ( matrix_x[h][0] == (i+1) && matrix_x[h][1] == j )
            {
                flag = 0;
                break;
            }
        }
        if ( flag == 1 )
        {
            matrix_x[scount][0] = i + 1;
            matrix_x[scount][1] = j;
            //        cout << scount << " " << tcount << "sss" << endl;
            scount++;
        }
        flag = 1;
    }
    
    tcount++;
    //        cout << scount << " " << tcount << "ssls" << endl;
    run_through(matrix_x[tcount][0], matrix_x[tcount][1], m, n);
}