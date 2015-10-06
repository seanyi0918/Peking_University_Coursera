//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 描述
 一个以'.'结尾的简单英文句子，单词之间用空格分隔，没有缩写形式和其它特殊形式
 
 输入
 一个以'.'结尾的简单英文句子（长度不超过500），单词之间用空格分隔，没有缩写形式和其它特殊形式
 
 输出
 该句子中最长的单词。如果多于一个，则输出第一个
 
 样例输入
 
 第一组
 I am a student of Peking University.
 第二组
 Hello world.
 样例输出
 
 第一组
 University
 第二组
 Hello
 */

#include <iostream>
using namespace std;

int main()
{
    char a[500];
    char word_longest[500];
    char current_word[500];
    int max = 0;
    
    cin.getline(a, 500);
    
    for ( int i = 0, j = 0; a[i] != '\0'; i++ )
    {
        if ( a[i] != ' ' && a[i] != '.')
        {
            current_word[j] = a[i];
            j++;
            continue;
        }
        if ( a[i] == ' ' || a[i] == '.')
        {
            if ( j > max )
            {
                max = j;
                for ( int k = 0; k < j; k++ )
                {
                    word_longest[k] = current_word[k];
                }
            }
            
            j = 0;
        }
    }
    
    for ( int k = 0; k < max; k++ )
        cout << word_longest[k];
    
    cout << endl;
    
    return 0;
}
