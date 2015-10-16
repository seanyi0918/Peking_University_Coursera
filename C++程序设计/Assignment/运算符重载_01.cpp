//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*

描述

下面程序的输出是：

3+4i

5+6i

请补足Complex类的成员函数。不能加成员变量。

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
double r,i;
public:
void Print() {
cout << r << "+" << i << "i" << endl;
}
// 在此处补充你的代码
};
int main() {
Complex a;
a = "3+4i"; a.Print();
a = "5+6i"; a.Print();
return 0;
}
输入

无

输出

3+4i

5+6i

样例输入

无
样例输出

3+4i
5+6i

*/

//#include <iostream>
//#include <cstring>
//#include <cstdlib>
//using namespace std;
//class Complex {
//private:
//	double r, i;
//public:
//	void Print() {
//		cout << r << "+" << i << "i" << endl;
//	}
//	// 在此处补充你的代码
	void operator =(string s)
	{
		int pos = s.find("+", 0);
		string sTmp = s.substr(0, pos);					// 分离出实部
		r = atof(sTmp.c_str());
		sTmp = s.substr(pos + 1, s.length() - pos - 2);	// 分离出虚部
		i = atof(sTmp.c_str());
	}
//};
//int main() {
//	Complex a;
//	a = "3+4i"; a.Print();
//	a = "5+6i"; a.Print();
//	return 0;
//}