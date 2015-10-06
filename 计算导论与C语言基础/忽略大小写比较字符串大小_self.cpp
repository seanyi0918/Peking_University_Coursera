//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 描述
 
 一般我们用strcmp可比较两个字符串的大小，比较方法为对两个字符串从前往后逐个字符相比较（按ASCII码值大小比较），
 直到出现不同的字符或遇到'\0'为止。如果全部字符都相同，则认为相同；如果出现不相同的字符，则以第一个不相同的字符的比较结果为准。
 但在有些时候，我们比较字符串的大小时，希望忽略字母的大小，例如"Hello"和"hello"在忽略字母大小写时是相等的。
 请写一个程序，实现对两个字符串进行忽略字母大小写的大小比较。
 
 输入
 
 输入为两行，每行一个字符串，共两个字符串。（请用cin.getline(s,80)录入每行字符串）（每个字符串长度都小于80）
 
 输出
 
 如果第一个字符串比第二个字符串小，输出一个字符"<"
 
 如果第一个字符串比第二个字符串大，输出一个字符">"
 
 如果两个字符串相等，输出一个字符"="
 
 样例输入
 
 第一组
 Hello
 hello
 第二组
 hello
 HI
 第三组
 hello
 HELL
 样例输出
 
 第一组
 =
 第二组
 <
 第三组
 >
 */

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;

int main()
{
    char a[80], b[80];
    char result = '=';
    
    cin.getline(a, 80);
    cin.getline(b, 80);
    
    for ( int i = 0; a[i] != '\0'; i++ )
    {
        if ( a[i] == b[i] )
        {
            continue;
        }
        
        if ( a[i] >= 'a' )
            a[i] = a[i] - 32;
        if (b[i] > 'a')
            b[i] = b[i] - 32;
        
        if ( a[i] > b[i] )
        {
            result = '>';
            break;
        }
        else if ( a[i] < b[i] )
        {
            result = '<';
            break;
        }
        
        else
            continue;
    }
    
    cout << result << endl;
    
    return 0;
}
