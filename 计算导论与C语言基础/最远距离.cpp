//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 描述
 给定一组点(x,y)，求距离最远的两个点之间的距离。
 
 输入
 
 第一行是点数n（n大于等于2）
 
 接着每一行代表一个点，由两个浮点数x y组成。
 
 输出
 
 输出一行是最远两点之间的距离。
 
 使用cout << fixed << setprecision(4) << dis << endl;输出距离值并精确到小数点后4位。
 
 fixed和setprecision是在<iomanip>头文件里定义的格式控制操作符，需要#include <iomanip>.
 
 样例输入
 
 6
 34.0 23.0
 28.1 21.6
 14.7 17.1
 17.0 27.2
 34.7 67.1
 29.3 65.1
 样例输出
 
 53.8516
 提示
 
 注意在内部计算时最好使用double类型，但在用scanf读取数据时只能用float类型的变量。
 */

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <math.h>
using namespace std;

int main()
{
    int n; // n >= 2
    float a[1000][2] = {(0.0, 0.0)};
    double max_dis = 0.0;
    
    cin >> n;
    
    for ( int i = 0; i < n; i++ )
    {
        cin >> a[i][0];
        cin >> a[i][1];
    }
    
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = i + 1; j < n; j++ )
        {
            double dis_x = a[j][0] - a[i][0];
            double dis_y = a[j][1] - a[i][1];
            double dis = sqrt(dis_x * dis_x + dis_y * dis_y);
            if ( dis > max_dis )
                max_dis = dis;
        }
    }
    
    cout << fixed << setprecision(4) << max_dis << endl;
    
    return 0;
}
