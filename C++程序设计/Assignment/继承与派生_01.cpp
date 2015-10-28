//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
描述

写一个MyString 类，使得下面程序的输出结果是：

1. abcd-efgh-abcd-

2. abcd-

3.

4. abcd-efgh-

5. efgh-

6. c

7. abcd-

8. ijAl-

9. ijAl-mnop

10. qrst-abcd-

11. abcd-qrst-abcd- uvw xyz

about

big

me

take

abcd

qrst-abcd-

要求：MyString类必须是从C++的标准类string类派生而来。提示1：如果将程序中所有 "MyString" 用"string" 替换，那么题目的程序中除了最后两条语句编译无法通过外，其他语句都没有问题，而且输出和前面给的结果吻合。也就是说，MyString类对 string类的功能扩充只体现在最后两条语句上面。提示2: string类有一个成员函数 string substr(int start,int length); 能够求从 start位置开始，长度为length的子串
输入

无

输出

1. abcd-efgh-abcd-

2. abcd-

3.

4. abcd-efgh-

5. efgh-

6. c

7. abcd-

8. ijAl-

9. ijAl-mnop

10. qrst-abcd-

11. abcd-qrst-abcd- uvw xyz

about

big

me

take

abcd

qrst-abcd-

*/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
// 在此处补充你的代码

class MyString:public string
{
 private:
	char * str;
	int len;
 public:
	 MyString(): str(NULL), len(0) {};												// 无参构造函数
	 MyString(const char * str_);													// 有参构造函数
	 MyString(const MyString & mystring);											// 复制构造函数
	 MyString & operator =(const MyString & mystring);								// 等号的重载
	 MyString operator +(const MyString & mystring);								// 加号的重载
	 char & operator[](int i);														// 下标运算符的重载
	 MyString & operator +=(const MyString & mystring);								// +=运算符的重载
	 friend ostream & operator <<(ostream & out, const MyString & oth);				// 输出运算符重载
	 friend MyString operator +(const char * str_, const MyString & mystring);		// 重载以字符串作为被加数的加号运算符
	 MyString operator +(const char * str_);										// 以字符串作为加数的加号运算符重载
	 bool operator ==(const MyString & mystring);									// 等值运算符重载	
	 bool operator <(const MyString & mystring);									// 小于运算符重载	
	 bool operator >(const MyString & mystring);									// 大于运算符重载	
	 MyString operator ()(int startIndex, int length);								// 数组下标运算符的重载
};

ostream & operator <<(ostream & out, const MyString & oth)
{
	if (oth.str)
		out << oth.str;
	return out;
}

MyString::MyString(const char * str_)
{
	int length = strlen(str_);
	if (str == str_)
		return;
	if (str_ == NULL)
	{
		str = NULL;
		len = 0;
		return;
	}

	len = length;
	str = new char[length + 1];
	memcpy(str, str_, sizeof(char)*(length + 1));
}

MyString::MyString(const MyString & mystring)
{
	if (mystring.str == NULL)
	{
		str = NULL;
		return;
	}

	len = mystring.len;
	str = new char[len + 1];
	memcpy(str, mystring.str, sizeof(char)*(len + 1));
}

MyString & MyString::operator =(const MyString & mystring)								// 等号的重载
{
	if (str == mystring.str)
		return *this;
	if (mystring.str == NULL)
	{
		if (str != NULL)
			delete[] str;
		str = NULL;
		return *this;
	}

	if (len < mystring.len)																// 如果本身不够大就要重新分配
	{
		if (str != NULL)
			delete[] str;
		str = new char[mystring.len + 1];
	}

	memcpy(str, mystring.str, sizeof(char)*(mystring.len + 1));
	len = mystring.len;
	
	return *this;
}

MyString MyString::operator+(const MyString & mystring)									// 加号的重载
{
	MyString afterAdd;
	afterAdd.len = this->len + mystring.len;

	afterAdd.str = new char[afterAdd.len + 1];
	int lc = 0;
	for (int i = 0; i < this->len; i++, lc++)
		afterAdd.str[lc] = this->str[i];

	for (int i = 0; i < mystring.len; i++, lc++)
		afterAdd.str[lc] = mystring.str[i];
	afterAdd.str[lc] = '\0';

	return afterAdd;
}

char & MyString::operator[](int i)														// 下标运算符的重载
{
	return str[i];
}

MyString & MyString::operator +=(const MyString & mystring)								// +=运算符的重载
{
	if (mystring.str == NULL)
		return *this;

	int length = this->len + mystring.len;
	char * str_ = new char[length + 1];
	int lc = 0;
	for (int i = 0; i < this->len; i++, lc++)
		str_[lc] = this->str[i];
	for (int i = 0; i < mystring.len; i++, lc++)
		str_[lc] = mystring.str[i];

	this->str = new char[length + 1];
	for (int i = 0; i < length; i++)
		str[i] = str_[i];
	str[length] = '\0';
	len = length;
	
	delete[] str_;
	return *this;
}

MyString operator +(const char * str_, const MyString & mystring)						// 重载以字符串作为被加数的加号运算符
{
	MyString afterAdd;
	afterAdd.len = strlen(str_) + mystring.len;
	afterAdd.str = new char[afterAdd.len + 1];
	int lc = 0;

	for (int i = 0; i < strlen(str_); i++, lc++)
		afterAdd.str[lc] = str_[i];
	for (int i = 0; i < mystring.len; i++, lc++)
		afterAdd.str[lc] = mystring.str[i];
	afterAdd.str[lc] = '\0';

	return afterAdd;
}

MyString MyString::operator+(const char * str_)											// 以字符串作为加数的加号运算符重载
{
	MyString afterAdd;
	afterAdd.len = this->len + strlen(str_);
	afterAdd.str = new char[afterAdd.len + 1];
	int lc = 0;

	for (int i = 0; i < this->len; i++, lc++)
		afterAdd.str[lc] = this->str[i];
	for (int i = 0; i < strlen(str_); i++, lc++)
		afterAdd.str[lc] = str_[i];
	afterAdd.str[lc] = '\0';

	return afterAdd;
}

bool MyString::operator ==(const MyString & mystring)									// 等值运算符重载
{
	if (len != mystring.len)
		return false;
	
	for (int i = 0; i < len; i++)
	{
		if (str[i] != mystring.str[i])
			return false;
	}

	return true;
}

bool MyString::operator <(const MyString & mystring)									// 小于运算符重载	
{
	int searchTimes = 0;
	int minlen = (len < mystring.len) ? len : mystring.len;
	while (str[searchTimes] == mystring.str[searchTimes] && searchTimes < minlen)
		searchTimes++;

	if (searchTimes < minlen)
	{
		if (str[searchTimes] < mystring.str[searchTimes])
			return true;
	}
	else if (len < mystring.len)
		return true;
	
	return false;
}
bool MyString::operator >(const MyString & mystring)									// 大于运算符重载	
{
	int searchTimes = 0;
	int minlen = (len < mystring.len) ? len : mystring.len;
	while (str[searchTimes] == mystring.str[searchTimes] && searchTimes < minlen)
		searchTimes++;

	if (searchTimes < minlen)
	{
		if (str[searchTimes] > mystring.str[searchTimes])
			return true;
	}
	else if (len > mystring.len)
		return true;

	return false;
}

MyString MyString::operator ()(int startIndex, int length)								// 数组下标运算符的重载
{
	MyString mystring;
	int endIndex = startIndex + length - 1;
	mystring.len = length;
	mystring.str = new char[length + 1];

	for (int i = startIndex, lc = 0; i <= endIndex; i++, lc++)
		mystring.str[lc] = this->str[i];
	mystring.str[length] = '\0';

	return mystring;
}

int CompareString(const void * e1, const void * e2)
{
	MyString * s1 = (MyString *)e1;
	MyString * s2 = (MyString *)e2;
	if (*s1 < *s2)     return -1;
	else if (*s1 == *s2) return 0;
	else if (*s1 > *s2) return 1;
}

int main(void)
{
	MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
	MyString SArray[4] = { "big","me","about","take" };
	cout << "1. " << s1 << s2 << s3 << s4 << endl;
	s4 = s3;    s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;    s1 = "ijkl-";
	s1[2] = 'A';
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray, 4, sizeof(MyString), CompareString);
	for (int i = 0;i < 4;++i)
		cout << SArray[i] << endl;
	//输出s1从下标0开始长度为4的子串
	cout << s1(0, 4) << endl;
	//输出s1从下标为5开始长度为10的子串
	cout << s1(5, 10) << endl;
	return 0;
}