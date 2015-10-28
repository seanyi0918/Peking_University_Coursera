//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 
 描述
 
 下面程序的输出结果是：
 
 destructor B
 
 destructor A
 
 请完整写出 class A。 限制条件：不得为 class A 编写构造函数。
 
 #include <iostream>
 using namespace std;
 class A {
 // 在此处补充你的代码
 };
 class B:public A {
 public:
 ~B() { cout << "destructor B" << endl; }
 };
 int main() {
 A * pa;
 pa = new B;
 delete pa;
 return 0;
 }
 输入
 
 无
 
 输出
 
 destructor B
 
 destructor A
 
 */

//#include <iostream>
//using namespace std;
//class A {
// 在此处补充你的代码
public:
virtual ~A() { cout << "destructor A" << endl; }
//};
//class B:public A {
//public:
//    ~B() { cout << "destructor B" << endl; }
//};
//int main() {
//    A * pa;
//    pa = new B;
//    delete pa;
//    return 0;
//}