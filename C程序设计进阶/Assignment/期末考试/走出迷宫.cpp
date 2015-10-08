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

#include<iostream>
using namespace std;

int n, m;
bool ago[100][100];
char ma[100][100];
int ans[100][100];

void f(int x, int y, int s)
{
    if ( ma[x][y] != '#' )
    {
        cout << ans[x][y] << " " << s << " ";
        if ( ans[x][y] == 0 || ans[x][y] > (s + 1) )
        {
            ans[x][y] = s + 1;
            cout << "(" << x << "," << y << ")" << ans[x][y] << endl;
            if( x+1 < n && ago[x+1][y] == false )
            {
                ago[x+1][y] = true;
                f(x+1, y, ans[x][y]);
                ago[x+1][y] = false;
            }
            if( x-1 >= 0 && ago[x-1][y] == false )
            {
                ago[x-1][y] = true;
                f(x-1, y, ans[x][y]);
                ago[x-1][y] = false;
            }
            if( y+1 < m && ago[x][y+1] == false )
            {
                ago[x][y+1] = true;
                f(x, y+1, ans[x][y]);
                ago[x][y+1] = false;
            }
            if( y-1 >= 0 && ago[x][y-1] == false )
            {
                ago[x][y-1] = true;
                f(x, y-1, ans[x][y]);
                ago[x][y-1] = false;
            }
        }
    }
}

int main(void)
{
    cin >> n >> m;
    
    int sx, sy, ex, ey;
    
    for ( int i = 0; i < n; i++ )
    {
        for(int j = 0; j < m; j++)
        {
            cin >> ma[i][j];
            if ( ma[i][j] == 'S' )
            {
                sx = i;
                sy = j;
            }
            if( ma[i][j] == 'T' )
            {
                ex = i;
                ey = j;
            }
            
            ago[i][j] = false;
            ans[i][j] = 0;
        }
    }
    
    ago[sx][sy] = true;
    
    int s = 0;
    
    f(sx, sy, s);
    
    cout << (ans[ex][ey] - 1) << endl;
    
    return 0;
}
