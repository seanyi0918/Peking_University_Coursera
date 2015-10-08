//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 
 描述
 
 两个整数 a 和 b 运算后得到结果 c。表示为：a ? b = c，其中，？可能是加法 +，减法 -，乘法 *，整除 / 或 取余 %。请根据输入的 a,b,c 的值，确定运算符。如果某种运算成立，则输出相应的运算符，如果任何运算都不成立，则输出 error.
 
 例如：
 
 输入：
 
 3,4,5
 
 输出：
 
 error
 
 若输入：
 
 3,4,3
 
 则输出：
 
 %
 
 输入
 
 a b和 c 的值在意行内输入，以逗号间隔
 
 输出
 
 五个运算符之一或 error
 
 样例输入
 
 6,7,13
 样例输出
 
 +
 
 */

#include <iostream>
#include <cstdlib>
using namespace std;

void get_operator(char * str, int *a);     // 获取三个操作符
int resign(int a, int b, int c);    // 判断operation

int main(void)
{
    int result;
    int a[3];           // 保存三个操作数
    char * str = new char[100];
    char sign[5] = {'+', '-', '*', '/', '%'};
    
    cin.getline(str, 100);
    
    get_operator(str, a);
    
    if ( (result = resign(a[0], a[1], a[2])) == -1 )
        cout << "error" << endl;
    else
        cout << sign[result] << endl;
    
    return 0;
}

void get_operator(char * str, int *a)
{
    int i = 0;      // 计数器
    
    while ( str[i] != ',' )
        i++;
    char *a_char = new char[i+1];
    for ( int ic = 0; ic < i; ic++ )
        a_char[ic] = str[ic];
    a_char[i] = '\0';
    *(a + 0) = atoi(a_char);    // 对应操作符的a
    delete[] a_char;
    
    int j = i;      // 保存当前计数
    i++;
    while ( str[i] != ',' )
        i++;
    char *b_char = new char[i - j];
    for ( int ic = 0; ic < (i-j-1); ic++ )
        b_char[ic] = str[ic+j+1];
    b_char[i-j-1] = '\0';
    *(a + 1) = atoi(b_char);     // 对应操作符的b
    delete[] b_char;
    
    j = i;
    i++;
    while ( str[i] != '\0' )
        i++;
    char *c_char = new char[i - j];
    for ( int ic = 0; ic < (i-j-1); ic++ )
        c_char[ic] = str[ic+j+1];
    c_char[i-j-1] = '\0';
    *(a + 2) = atoi(c_char);    // 对应操作符的c
    delete[] c_char;
}

int resign(int a, int b, int c)
{
    int sign = -1;
    
    if ( (a + b) == c )
        sign = 0;
    else if ( (a - b) == c )
        sign = 1;
    else if ( (a * b) == c )
        sign = 2;
    else if ( (a / b) == c )
        sign = 3;
    else if ( (a % b) == c )
        sign = 4;
    
    return sign;
}
