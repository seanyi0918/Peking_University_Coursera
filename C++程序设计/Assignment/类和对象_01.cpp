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
 class A {
 public:
 int val;
 // 在此处补充你的代码
 };
 main() {
 A a;
 cout << a.val << endl;
 a.GetObj() = 5;
 cout << a.val << endl;
 }
 
 样例输入
 无
 
 样例输出
 0
 5
 
 */

// 注意要将"在此补充你的代码"补充代码之外的部分都注释掉POJ上才能顺利通过, 很奇怪的感觉哈

//#include <iostream>
//using namespace std;
//class A
//{
//public:
//    int val;
// 在此处补充你的代码
    A(int a = 0) { this->val = a; }
    A & GetObj(void) { return *this;}
//};
//
//int main()
//{
//    A a;
//    cout << a.val << endl;
//    a.GetObj() = 5;
//    cout << a.val << endl;
//    
//    return 0;
//}