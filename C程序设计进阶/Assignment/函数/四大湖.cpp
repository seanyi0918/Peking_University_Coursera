//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 描述
 
 我国有4大淡水湖。
 
 A说：洞庭湖最大，洪泽湖最小，鄱阳湖第三。
 
 B说：洪泽湖最大，洞庭湖最小，鄱阳湖第二，太湖第三。
 
 C说：洪泽湖最小，洞庭湖第三。
 
 D说：鄱阳湖最大，太湖最小，洪泽湖第二，洞庭湖第三。
 
 已知这4个湖的大小均不相等，4个人每人仅答对一个，
 
 请编程按照鄱阳湖、洞庭湖、太湖、洪泽湖的顺序给出他们的大小排名。
 
 输入
 
 无。
 
 输出
 
 输出为4行，第1行为鄱阳湖的大小名次，从大到小名次分别表示为1、2、3、4；第2、3、4行分别为洞庭湖、太湖、洪泽湖的大小名次。
 
 样例输入
 
 (无)
 样例输出
 
 3
 2
 1
 4
 */

#include <iostream>
using namespace std;

int main()
{
    int a[4];
    int b[4];
    int flag = 0;
    // 0: 鄱阳湖; 1: 洞庭湖; 2: 太湖; 3: 洪泽湖
    
    for ( int i = 1; i <= 4 && flag == 0; i++ )
    {
        a[0] = i;
        for ( int j = 1; j <= 4 && flag == 0; j++ )
        {
            if ( j == i )
                continue;
            a[1] = j;
            for ( int k = 1; k <= 4 && flag == 0; k++ )
            {
                if ( k == i || k == j )
                    continue;
                a[2] = k;
                a[3] = 10 - i - j - k;
                
                b[0] = ( a[1] == 1 ) + ( a[3] == 4 ) + ( a[0] == 3 );
                b[1] = ( a[3] == 1 ) + ( a[1] == 4 ) + ( a[0] == 2 ) + ( a[2] == 3 );
                b[2] = ( a[3] == 4 ) + ( a[1] == 3 );
                b[3] = ( a[0] == 1 ) + ( a[2] == 4 ) + ( a[3] == 2 ) + ( a[1] == 3 );
                
                if ( b[0] == 1 && b[1] == 1 && b[2] == 1 && b[3] == 1 )
                {
                    flag = 1;
                    break;
                }
            }
        }
    }
    
    for ( int i = 0; i < 4; i++ )
        cout << a[i] << endl;
    
    return 0;
}