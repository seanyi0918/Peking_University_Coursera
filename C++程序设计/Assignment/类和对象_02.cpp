//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 
 描述
 
 下面程序的输出是：
 
 10
 
 请补足Sample类的成员函数。不能增加成员变量。
 
 #include <iostream>
 using namespace std;
 class Sample{
 public:
 int v;
 Sample(int n):v(n) { }
 // 在此处补充你的代码
 };
 int main() {
 Sample a(5);
 Sample b = a;
 cout << b.v;
 return 0;
 }
 
 样例输入
 
 无
 样例输出
 
 10
 
 */

// 注意要将"在此补充你的代码"补充代码之外的部分都注释掉POJ上才能顺利通过, 很奇怪的感觉哈

//#include <iostream>
//using namespace std;
//class Sample{
//public:
//    int v;
//    Sample(int n):v(n) { }
    // 在此处补充你的代码
    Sample(Sample & sample) {v = sample.v * 2;}
//};
//int main() {
//    Sample a(5);
//    Sample b = a;
//    cout << b.v;
//    return 0;
//}