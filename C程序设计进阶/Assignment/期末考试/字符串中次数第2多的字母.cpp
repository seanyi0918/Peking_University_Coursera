//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 
 描述
 输入一串长度不超过500个符号的字符串，输出在串中出现第2多的英语字母(大小写字母认为相同)和次数（如果串中有其它符号，则忽略不考虑）。如果有多个字母的次数都是第2多，则按串中字母出现的顺序输出第1个。
 
 例 ab&dcAab&c9defgb
 
 这里，a 和 b都出现3次，c和d都出现2次，e、f 和 g 各出现1次，其中的符号&和9均忽略不考虑。因此，出现第2多的应该是 c 和 d，
 但是 d 开始出现的位置在 c 的前面，因此，输出为
 
 D+d:2
 
 (假定在字符串中，次数第2多的字母总存在)
 
 输入
 一个字符串
 
 输出
 大写字母+小写字母:个数
 
 样例输入
 ab&dcAab&c9defgb
 
 样例输出
 D+d:2
 
 */

#include <iostream>
using namespace std;

void change(int * a)
{
    *(a+1) = 1;
}

struct letter
{
    char cha;
    int count;
    int mark;
    int show;
};

int main(void)
{
    char * str = new char[500]; // 定义不超过500个符号的字符串
    //int count[26] = {0};        // 用来统计每个字母出现的次数
    letter counts[26];          // 用来表示每个单词的元素, 出现次数, 排名
    
    for ( int i = 0; i < 26; i++ )
    {
        counts[i].cha = 'a' + i;
        counts[i].count = 0;
        counts[i].mark = 0;
        counts[i].show = 0;
    }
    
    cin.getline(str, 500);
    
    //统计每个字符出现的次数, 不算非英文字母
    for ( int i = 0; str[i] != '\0'; i++ )
    {
        if ( str[i] >= 'a' && str[i] <= 'z' )
        {
            counts[str[i]-'a'].count += 1;
            if ( counts[str[i]-'a'].show == 0 )
                counts[str[i]-'a'].show = (26-i);
        }
        else if ( str[i] >= 'A' && str[i] <= 'Z' )
        {
            counts[str[i]-'A'].count += 1;
            if ( counts[str[i]-'a'].show == 0 )
                counts[str[i]-'a'].show = (26-i);
        }
    }
    
    // 对字母出现次数进行排序, 如果相同则根据出现顺序进行排序
    int mark = 1;
    
    for ( int i = 0; i < 26; i++ )
    {
        for ( int j = i + 1; j < 26; j++ )
        {
            if ( counts[i].count < counts[j].count )
            {
                letter tmp = counts[i];
                counts[i] = counts[j];
                counts[j] = tmp;
            }
        }
        
        if ( i > 0 && (counts[i].count == counts[i-1].count) )
            counts[i].mark = counts[i-1].mark;
        else
        {
            counts[i].mark = mark;
            mark++;
        }
    }
    
    int maxshow = 0;
    int maxshowid = 0;
    
    for ( int markcount = 0; markcount < 26; markcount++ )
    {
        if ( counts[markcount].mark == 2 )
        {
            if ( counts[markcount].show > maxshow )
            {
                maxshow = counts[markcount].show;
                maxshowid = markcount;
            }
        }
    }
    
    char chaupper = 'A' + (counts[maxshowid].cha - 'a');
    
    cout << chaupper << '+' << counts[maxshowid].cha << ":" << counts[maxshowid].count << endl;
    
    return 0;
}