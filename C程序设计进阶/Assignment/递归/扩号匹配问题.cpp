//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 
 描述
 在某个字符串（长度不超过100）中有左括号、右括号和大小写字母；规定（与常见的算数式子一样）任何一个左括号都从内到外与在它右边且距离最近的右括号匹配。写一个程序，找到无法匹配的左括号和右括号，输出原来字符串，并在下一行标出不能匹配的括号。不能匹配的左括号用"$"标注,不能匹配的右括号用"?"标注.
 
 输入
 输入包括多组数据，每组数据一行，包含一个字符串，只包含左右括号和大小写字母，字符串长度不超过100
 
 注意：cin.getline(str,100)最多只能输入99个字符！
 
 输出
 对每组输出数据，输出两行，第一行包含原始输入字符，第二行由"$","?"和空格组成，"$"和"?"表示与之对应的左括号和右括号不能匹配。
 
 样例输入
 
 ((ABCD(x)()()()()()
 )(rttyy())sss)(
 样例输出
 
 ((ABCD(x)
 $$
 )(rttyy())sss)(
 ?            ?$
 
 */

#include <iostream>
using namespace std;

void match(char * str, char * str_x,  int);

int main(void)
{
    char str[100];
    char str_x[100];
    
    while(cin.getline(str, 101))
    {
        for ( int i = 0; i < 101; i++ )
            str_x[i] = str[i];
        
        cout << str << endl;
        match(str, str_x, 0);
        
        for ( int i = 0; str_x[i] != '\0'; i++ )
        {
            if ( str_x[i] == '(' )
                cout << '$';
            else if ( str_x[i] == ')' )
                cout << '?';
            else
                cout << str_x[i];
        }
        
        cout << endl;
    }
    
    return 0;
}

void match(char * str, char * str_x, int i)
{
    while ( str[i] != ')' && str[i] != '\0')
    {
        if ( str[i] != '(' )
        {
            str_x[i] = ' ';
        }
        i++;
    }
    
    if ( str[i] == ')' )
    {
        for ( int j = i; j >= 0; j-- )
        {
            if ( str_x[j] == '(' )
            {
                str_x[i] = ' ';
                str_x[j] = ' ';
                break;
            }
        }
        i = i + 1;
        match(str, str_x, i);
    }
}