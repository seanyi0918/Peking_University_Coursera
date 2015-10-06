//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 
 描述
 
 约瑟夫问题：有ｎ只猴子，按顺时针方向围成一圈选大王（编号从１到ｎ），从第１号开始报数，一直数到ｍ，数到ｍ的猴子退出圈外，
 剩下的猴子再接着从1开始报数。就这样，直到圈内只剩下一只猴子时，这个猴子就是猴王，编程求输入ｎ，ｍ后，输出最后猴王的编号。
 
 输入
 
 每行是用空格分开的两个整数，第一个是 n, 第二个是 m ( 0 < m,n <=300)。最后一行是：
 
 0 0
 
 输出
 
 对于每行输入数据（最后一行除外)，输出数据也是一行，即最后猴王的编号
 
 */

#include <iostream>
using namespace std;

// 一共最多有300只猴子
int succedent[300]; // 这个数组用于保存一个猴子的后一位是谁
// 比如"next[5]的值是7"就是说5号猴子的下一位是7号猴子, 6号猴子已经在之前退出了
int precedent[300];  // 这个数组用于保存一个猴子前一位是谁, 用法和上面类似


int main(int argc, const char * argv[])
{
    int n, m, current, pre, suc;
    
    while ( true )
    {
        cin >> n >> m;
        
        if ( n == 0 && m == 0 )
        {
            break;
        }
        
        pre = 0;
        
        current = 0;
        
        suc = n;
        
        // 初始化猴子群
        // 第n号猴子的下一位是第1号, 第1号猴子的前一位是第n号
        succedent[n - 1] = 0;
        precedent[0] = n - 1;
        for ( int i = 0; i < n - 1; i++ )
        {
            succedent[i] = i + 1;
            precedent[i + 1] = i;
        }
        
        // 开始计数
        while ( pre != suc )
        {
            for ( int i = 0; i < m - 1; i++ )
            {
                current = succedent[current];
            }
            
            // 让当前选中位退出
            suc = succedent[current];
            pre = precedent[current];
            // 当前位的前一位的next改成当前位的后一位
            precedent[suc] = pre;
            // 当前位的后一位的pre改成当前位的前一位
            succedent[pre] = suc;
            
            current = suc;
        }
        
        cout << pre + 1 << endl;
    }
    
    return 0;
}
