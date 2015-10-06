//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 描述
 
 输入一个句子（一行），将句子中的每一个单词翻转后输出。
 
 输入
 
 只有一行，为一个字符串，不超过500个字符。单词之间以空格隔开。
 
 输出
 
 翻转每一个单词后的字符串，单词之间的空格需与原文一致。
 
 样例输入
 
 hello world
 样例输出
 
 olleh dlrow
 */

#include<iostream>
using namespace std;

int main()
{
    int i = 0, j , k;
    char s[501], temp;
    cin.getline(s, 501);
    
    while(s[i])
    {
        while (s[i] == ' ') i++;
        if(!s[i]) break;
        j = i;
        while(s[j] != ' '&&s[j]) j++;
        for (k = i; k < (i + j) / 2; k++)
        {
            temp = s[k];
            s[k] = s[j-1+i-k];
            s[j-1+i-k] = temp;
        }
        i = j;
    }
    
    cout << s;
    
    return 0;
}