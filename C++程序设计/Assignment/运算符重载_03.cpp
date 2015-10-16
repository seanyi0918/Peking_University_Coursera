//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*

描述

写一个二维数组类 Array2,使得下面程序的输出结果是：

0,1,2,3,

4,5,6,7,

8,9,10,11,

next

0,1,2,3,

4,5,6,7,

8,9,10,11,

程序：

#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
int main() {
Array2 a(3,4);
int i,j;
for( i = 0;i < 3; ++i )
for( j = 0; j < 4; j ++ )
a[i][j] = i * 4 + j;
for( i = 0;i < 3; ++i ) {
for( j = 0; j < 4; j ++ ) {
cout << a(i,j) << ",";
}
cout << endl;
}
cout << "next" << endl;
Array2 b; b = a;
for( i = 0;i < 3; ++i ) {
for( j = 0; j < 4; j ++ ) {
cout << b[i][j] << ",";
}
cout << endl;
}
return 0;
}
输入

无

输出

0,1,2,3,

4,5,6,7,

8,9,10,11,

next

0,1,2,3,

4,5,6,7,

8,9,10,11,

样例输入

无
样例输出

0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,

*/

//#include <iostream>
//#include <cstring>
//using namespace std;
// 在此处补充你的代码

class Array2
{
 private:
	int width;										// 数组的行数
	int height;										// 数组的列数
	int *ptr;										// 指向动态分配的数组
 public:
	 Array2() {}									// 无参构造函数
	 Array2(int width_, int height_)				// 有参构造函数
	 {
		 width = width_;
		 height = height_;

		 if (width == 0 || height == 0)
			 ptr = NULL;
		 else
			 ptr = new int[width * height];
	 }

	 int * operator[](int i)
	 {
		 int * pTmp = ptr;
		 for (int count = 0; count < i * height; count++)
			 pTmp++;

		 return pTmp;
	 }

	 int & operator()(int width_, int height_)
	 {
		/* if (width_ < width && width >= 0 && height_ < height && height_ >= 0)
		 {*/
			 return ptr[width_ * height + height_];
		 //}
	 }

	 Array2 & operator =(const Array2 & arr)
	 {
		 if (ptr == arr.ptr)							// 防止a = a这样的赋值导致出错
			return *this;

		 if (arr.ptr == NULL)
		 {
			 if (ptr) delete[] ptr;
			 ptr = NULL;
			 width = 0;
			 height = 0;
			 return *this;
		 }
		 
		 if (width * height < arr.width * arr.height)	// 如果原有的数组大小比赋值过来的要小就需要重新分配空间
		 {
			 if (ptr != NULL)
				 delete[] ptr;

			 ptr = new int[arr.width * arr.height];
		 }
		
		 memcpy(ptr, arr.ptr, sizeof(int) * arr.width * arr.height);
		 width = arr.width;
		 height = arr.height;
		 /*for (int i = 0; i < width; i++)
		 {
			 for (int j = 0; j < height; j++)
				 ptr[i * height + j] = arr.ptr[i * height + j];
		 }*/

		 return *this;
	 }
};
//
//int main() {
//	Array2 a(3, 4);
//	int i, j;
//	for (i = 0;i < 3; ++i)
//		for (j = 0; j < 4; j++)
//			a[i][j] = i * 4 + j;
//	for (i = 0;i < 3; ++i) {
//		for (j = 0; j < 4; j++) {
//			cout << a(i, j) << ",";
//		}
//		cout << endl;
//	}
//	cout << "next" << endl;
//	Array2 b;     b = a;
//	for (i = 0;i < 3; ++i) {
//		for (j = 0; j < 4; j++) {
//			cout << b[i][j] << ",";
//		}
//		cout << endl;
//	}
//	return 0;
//}