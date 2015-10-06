//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 描述
 统计单词数目
 */

#include <iostream>
using namespace std;

int main()
{
    char str[1000];
    int flag = 1;
    int count = 0;
    cin.getline(str, 100);
    
    for ( int i = 0; str[i] != '\0'; i++ )
    {
        if ( str[i] != ' ' && str[i] != '\n' )
        {
            if ( flag == 1 )
            {
                count++;
                flag = 0;
            }
        }
        else
            flag = 1;
    }
    
    cout << count << endl;
    
    return 0;
}
