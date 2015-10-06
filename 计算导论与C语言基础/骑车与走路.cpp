//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 描述
 
 在北大校园里,没有自行车,上课办事会很不方便.但实际上,并非去办任何事情都是骑车快,因为骑车总要找车、开锁、停车、锁车等,
 这要耽误一些时间.假设找到自行车,开锁并车上自行车的时间为27秒;停车锁车的时间为23秒;步行每秒行走1.2米,骑车每秒行走3.0米.
 请判断走不同的距离去办事,是骑车快还是走路快.
 
 输入
 
 第一行为待处理的数据的数量n
 
 其后每一行整数为一次办事要行走的距离,单位为米.
 
 输出
 
 对应每个整数,如果骑车快,输出一行"Bike";如果走路快,输出一行"Walk";如果一样快,输出一行"All".
 
 样例输入
 
 4
 50
 90
 120
 180
 样例输出
 
 Walk
 Walk
 Bike
 Bike
 提示
 
 注意数据类型，应当使用浮点数来保存结果
 */

#include <iostream>
using namespace std;

int main()
{
    int n, temp;
    double walk, bike;
    int result[3] = {0};
    
    cin >> n;
    
    for ( int i = 0; i < n; i++ )
    {
        cin >> temp;
        
        walk = (double)temp / 1.2;
        bike = (double)temp / 3.0 + 50.0;
        
        if ( walk > bike )
            result[i] = 0;
        else if ( bike > walk )
            result[i] = 1;
        else
            result[i] = 2;
    }
    
    for ( int i = 0; i < n; i++ )
    {
        if ( result[i] == 0 )
            cout << "Bike" << endl;
        else if ( result[i] == 1 )
            cout << "Walk" << endl;
        else
            cout << "All" << endl;
    }
    
    return 0;
}
