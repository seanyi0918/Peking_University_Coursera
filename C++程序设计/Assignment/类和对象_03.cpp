//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 
 描述
 
 请填空：
 
 #include <iostream>
 using namespace std;
 class Base {
 public:
 int k;
 Base(int n):k(n) { }
 };
 class Big {
 public:
 int v; Base b;
 // 在此处补充你的代码
 };
 int main() {
 Big a1(5); Big a2 = a1;
 cout << a1.v << "," << a1.b.k << endl;
 cout << a2.v << "," << a2.b.k << endl;
 return 0;
 }
 
 样例输入
 无
 
 样例输出
 5,5
 5,5
 
 */

//#include <iostream>
//using namespace std;
//class Base {
//public:
//    int k;
//    Base(int n):k(n) { }
//};
//class Big  {
//public:
//    int v; Base b;
    // 在此处补充你的代码
    Big(int n): v(n), b(n) {}
    Big(Big & big): v(big.v), b(big.v) {}
//};
//int main()  {
//    Big a1(5);    Big a2 = a1;
//    cout << a1.v << "," << a1.b.k << endl;
//    cout << a2.v << "," << a2.b.k << endl;
//    return 0;
//}