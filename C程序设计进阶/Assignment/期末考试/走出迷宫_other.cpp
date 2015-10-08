//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 
 描述
 当你站在一个迷宫里的时候，往往会被错综复杂的道路弄得失去方向感，如果你能得到迷宫地图，事情就会变得非常简单。
 假设你已经得到了一个n*m的迷宫的图纸，请你找出从起点到出口的最短路。
 
 输入
 第一行是两个整数n和m(1 <= n,m <= 100)，表示迷宫的行数和列数。
 接下来n行，每行一个长为m的字符串，表示整个迷宫的布局。字符'.'表示空地，'#'表示墙，'S'表示起点,'T'表示出口。
 
 输出
 输出从起点到出口最少需要走的步数。(你不能起出迷宫外)
 
 样例输入
 3 3
 S#T
 .#.
 ...
 
 样例输出
 6
 
 
 */

#include <iostream>
#include<stack>
#include<queue>
using std::stack;

using namespace std;
#define  MAX 1000
struct Node
{
    int x, y;
}tmp, s, t, order[MAX];

char Graph[MAX][MAX];

int IsFind(int x, int y)
{
    if (x==t.x && y==t.y)
        return 1;
    return 0;
}

int Judge(stack<Node> &sta) //判断是否到达t
{
    if (IsFind(tmp.x+1, tmp.y))
    {
        tmp.x = tmp.x + 1;
        sta.push(tmp);
        return 1;
    }
    else if (IsFind(tmp.x-1, tmp.y))
    {
        tmp.x = tmp.x - 1;
        sta.push(tmp);
        return 1;
    }
    else if (IsFind(tmp.x, tmp.y+1))
    {
        tmp.y = tmp.y + 1;
        sta.push(tmp);
        return 1;
    }
    else if (IsFind(tmp.x, tmp.y-1))
    {
        tmp.y = tmp.y - 1;
        sta.push(tmp);
        return 1;
    }
    return 0;
}
void Advance(stack<Node> &sta)
{
    if (Graph[tmp.x+1][tmp.y] == '.')
    {
        Graph[tmp.x][tmp.y] = '#';
        tmp.x = tmp.x + 1;
        sta.push(tmp);
    }
    else if (Graph[tmp.x-1][tmp.y] == '.')
    {
        Graph[tmp.x][tmp.y] = '#';
        tmp.x = tmp.x - 1;
        sta.push(tmp);
    }
    else if (Graph[tmp.x][tmp.y+1] == '.')
    {
        Graph[tmp.x][tmp.y] = '#';
        tmp.y = tmp.y + 1;
        sta.push(tmp);
    }
    else if (Graph[tmp.x][tmp.y-1] == '.')
    {
        Graph[tmp.x][tmp.y] = '#';
        tmp.y = tmp.y - 1;
        sta.push(tmp);
    }
    else
    {
        tmp = sta.top();
        Graph[tmp.x][tmp.y] = '#';
        sta.pop();
    }
}

int main()
{
    int n, m, sum = 1;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> Graph[i][j];
            
            if ( Graph[i][j] == 'S' )
            {
                s.x = i, s.y = j;
            }
            else if (Graph[i][j] == 'T' )
            {
                t.x = i, t.y = j;
            }
        }
    }
    
    stack<Node> sta;
    sta.push(s);
    
    while (!sta.empty())
    {
        tmp = sta.top();
        if (Judge(sta))//下一步是否可达
            break;
        Advance(sta);//前进
        sum = sum + 1;
    }
    
    if (!sta.empty())
        cout << sum << endl;
    
    return 0;
}
