//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 
 描述
 
 某医院想统计一下某项疾病的获得与否与年龄是否有关，需要对以前的诊断记录进行整理。
 
 输入
 
 共2行，第一行为过往病人的数目n（0 < n <= 100)，第二行为每个病人患病时的年龄。
 
 输出
 
 每个年龄段（分四段：18以下，19-35，36-60，大于60注意看样例输出的格式）的患病人数占总患病人数的比例，以百分比的形式输出，精确到小数点后两位（double）。关于c++的格式化的输入输出，请参考：http://www.cplusplus.com/reference/iomanip。也可以在网上搜索一下，资料很多的。
 
 样例输入
 
 10
 1 11 21 31 41 51 61 71 81 91
 样例输出
 
 1-18: 20.00%
 19-35: 20.00%
 36-60: 20.00%
 60-: 40.00%
 
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, a[4] = {0}, temp;
    double b[4] = {0.0};
    
    cin >> n;
    
    for ( int i = 0; i < n; i++ )
    {
        cin >> temp;
        
        if ( temp <= 18 )
            a[0]++;
        else if ( temp <= 35 )
            a[1]++;
        else if ( temp <= 60 )
            a[2]++;
        else if ( temp > 60 )
            a[3]++;
    }
    
    for ( int i = 0; i < 4; i++ )
    {
        b[i] = (double)a[i] / (double)n * 100;
    }
    
    cout << "1-18: " << fixed << setprecision(2) << b[0] << "%" << endl;
    cout << "19-35: " << b[1] << "%" << endl;
    cout << "36-60: " << b[2] << "%" << endl;
    cout << "60-: " << b[3] << "%" << endl;
    
    return 0;
}
