//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 描述
 有两个字符串str和substr，str的字符个数不超过10，substr的字符个数为3。（字符个数不包括字符串结尾处的'\0'。）将substr插入到str中ASCII码最大的那个字符后面，若有多个最大则只考虑第一个。
 
 输入
 输入包括若干行，每一行为一组测试数据，格式为
 
 str substr
 输出
 
 对于每一组测试数据，输出插入之后的字符串。
 
 样例输入
 abcab eee
 12343 555
 样例输出
 
 abceeeab
 12345553
 */

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <math.h>
using namespace std;

int main()
{
    char str[10];
    char strst[15];
    char substr[4];
    
    while ( cin >> str >> substr)
    {
        char max = 0;
        int max_i = 0;
        
        for ( int i = 0; str[i] != '\0' && i < 11; i++ )
        {
            if ( str[i] > max )
            {
                max = str[i];
                max_i = i + 1;
            }
        }
        
        int i = 0;
        
        for ( ; i < max_i; i++ )
            strst[i] = str[i];
        for ( int j = 0; substr[j] != '\0' && j < 4; j++)
            strst[i++] = substr[j];
        
        for ( int j = max_i; str[j] != '\0' && j < 11; j++)
            strst[i++] = str[j];
        
        cout << strst << endl;
        
        for ( int i = 0; i < 11; i++ )
            str[i] = '\0';
        for ( int i = 0; i < 4; i++ )
            substr[i] = '\0';
        for ( int i = 0; i < 15; i++ )
            strst[i] = '\0';
    }
    
    return 0;
}
//
//# include<stdio.h>
//# include<string.h>
//
//int main(void)
//{
//    char s1[11], s2[4];
//    int i;
//    while(scanf("%s%s", s1, s2)!=EOF)
//    {
//        int max=0;
//        int len=strlen(s1);
//        for(i=0; i<len; i++)
//        {
//            if(s1[i]>s1[max])
//            {
//                max=i;
//            }
//        }
//        for(i=0; i<=max; i++)
//            printf("%c", s1[i]);
//        printf("%s", s2);
//        for(i=max+1; i<len; i++)
//            printf("%c", s1[i]);
//        printf("\n");
//    }
//
//    return 0;
//}