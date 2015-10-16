//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*

描述

下面的MyInt类只有一个成员变量。MyInt类内部的部分代码被隐藏了。假设下面的程序能编译通过，且输出结果是:

4,1

请写出被隐藏的部分。（您写的内容必须是能全部放进 MyInt类内部的，MyInt的成员函数里不允许使用静态变量）。

#include <iostream>
using namespace std;
class MyInt {
int nVal;
public:
MyInt(int n) { nVal = n; }
int ReturnVal() { return nVal; }
// 在此处补充你的代码
};
int main () {
MyInt objInt(10);
objInt-2-1-3;
cout << objInt.ReturnVal();
cout <<",";
objInt-2-1;
cout << objInt.ReturnVal();
return 0;
}
输入

无

输出

4,1

样例输入

无
样例输出

4,1

*/

//#include <iostream>
//using namespace std;
//
//class MyInt {
//	int nVal;
// public:
//	MyInt(int n) { nVal = n; }
//	int ReturnVal() { return nVal; }
//	// 在此处补充你的代码
	MyInt & operator -(int i)
	{
		nVal -= i;

		return * this;
	}
//};
//
//int main() {
//	MyInt objInt(10);
//	objInt - 2 - 1 - 3;
//	cout << objInt.ReturnVal();
//	cout << ",";
//	objInt - 2 - 1;
//	cout << objInt.ReturnVal();
//	return 0;
//}