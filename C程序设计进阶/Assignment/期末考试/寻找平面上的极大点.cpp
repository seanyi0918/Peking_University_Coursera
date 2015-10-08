//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 
 描述
 
 在一个平面上，如果有两个点(x,y),(a,b),如果说(x,y)支配了(a,b)，这是指x>=a,y>=b;
 
 用图形来看就是(a,b)坐落在以(x,y)为右上角的一个无限的区域内。
 
 给定n个点的集合，一定存在若干个点，它们不会被集合中的任何一点所支配，这些点叫做极大值点。
 
 编程找出所有的极大点，按照x坐标由小到大，输出极大点的坐标。
 
 本题规定：n不超过100，并且不考虑点的坐标为负数的情况。
 
 输入
 
 输入包括两行，第一行是正整数n，表示是点数，第二行包含n个点的坐标，坐标值都是整数，坐标范围从0到100，输入数据中不存在坐标相同的点。
 
 输出
 
 按x轴坐标最小到大的顺序输出所有极大点。
 
 输出格式为:(x1,y1),(x2,y2),...(xk,yk)
 6
 注意：输出的每个点之间有","分隔,最后一个点之后没有",",少输出和多输出都会被判错
 
 样例输入
 
 5
 1 2 2 2 3 1 2 3 1 4
 样例输出
 
 (1,4),(2,3),(3,1)
 
 */

#include <iostream>
using namespace std;

struct Node
{
    int x;                                          // x坐标
    int y;                                          // y坐标
    int flag;                                       // 用来标示极大值点
};

bool dominate(Node a, Node b);
int findpeak(Node * nodes, int n);                  // 找到所有的极大值点, 返回值为极大值点总数
void printpeak(Node * nodes, int peaks, int n);     // 按x坐标大小输出极大值点坐标

int main(void)
{
    int N;          // 输入点数
    cin >> N;
    
    Node *nodes = new Node[N];
    int peaks = 0;
    
    for ( int i = 0; i < N; i++ )                   // 输入每个点的横坐标和纵坐标
    {
        cin >> nodes[i].x >> nodes[i].y;
        nodes[i].flag = 0;                          // 初始化=0, 表示不是, 1表示是极大值点
    }
    
    if ( N > 1 )
    {
        peaks = findpeak(nodes, N);
        printpeak(nodes, peaks, N);
    }
    else
        cout << '(' << nodes[0].x << ',' << nodes[0].y << ')';
    
    cout << endl;
    
    return 0;
}

bool dominate(Node a, Node b)
{
    if ( a.x >= b.x && a.y >= b.y )
        return true;
    
    return false;
}

int findpeak(Node * nodes, int n)
{
    int sum = 0;
    
    for ( int i = 0; i < n; i++ )
    {
        int findp = 1;
        
        for ( int j = 0; j < 5; j++ )
        {
            if ( j == i )                               // 点一定是能被自己支配的, 所以略过;
                continue;
            
            if ( dominate(nodes[j], nodes[i]) )
            {
                findp = 0;
                break;
            }
        }
        
        if ( findp == 1 )                               // 遍历到最后一点, 说明没有任何点能够支配i点, i点为极大值点
        {
            nodes[i].flag = 1;
            sum += 1;
        }
    }
    
    return sum;
}

void printpeak(Node * nodes, int peaks, int n)
{
    while ( peaks > 0 )                             // 还有极大值点
    {
        peaks--;
        int min_id = 0, min = 101;
        for ( int i = 0; i < n; i++ )
        {
            if ( nodes[i].flag == 1 )               // 为极大值点
            {
                if ( nodes[i].x < min )
                {
                    min_id = i;
                    min = nodes[i].x;
                }
            }
        }
        
        nodes[min_id].flag = 0;              // 把极大值点中x坐标最小点标记为非极大值点, 下次循环不遍历它
        
        cout << '(' << nodes[min_id].x << ',' << nodes[min_id].y << ')';
        
        if ( peaks > 0 )
            cout << ',';
        else
            cout << endl;
    }
}
