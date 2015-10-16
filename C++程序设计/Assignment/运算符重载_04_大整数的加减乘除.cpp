#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAXLEN = 100;

class bignum
{
 private:
	int size;
	char * ptr;															// 用来保存大数字
	char sign;															// 用来保存符号位 --> 注意要修改下面的所有函数, 判断符号位

 public:
	 bignum(const char *string = "")
	 {
		 memset(ptr, 0, MAXLEN*sizeof(char));
		 sign = '+';
		 size = strlen(ptr);
		 for (int i = 0; i < size; i++)
			 ptr[i] = string[i];

		 ptr[size] = '\0';
	 }
	 friend int compare(const bignum & big1, const bignum & big2);		// 得到size更大的数
	 friend istream  & operator >>(istream & is, bignum & big_);		// 输入大数字重载
	 friend ostream  & operator <<(ostream & os, bignum & big_);		// 输出大数字重载
	 int getsize() { return size; }
	 bignum & operator =(const bignum & big_)							// 赋值符号重载
	 {
		 /*cout << "进入赋值符号重载" << endl;
		 cout << "big_.size = " << big_.size << endl;*/
		 if (ptr == big_.ptr)
			 return *this;

		 if (big_.ptr == NULL)
		 {
			 if (ptr != NULL)
				 delete[] ptr;
			 ptr = NULL;
			 size = 0;
			 return *this;
		 }

		 if (size < big_.size)
		 {
			 if (ptr != NULL)
				 delete[] ptr;
			 ptr = new char[big_.size + 1];
		 }

		 /*memcpy(ptr, big_.ptr, sizeof(char)*big_.size);*/
		 for (int i = 0; i < big_.size; i++)
			 ptr[i] = big_.ptr[i];

		 ptr[big_.size] = '\0';
		 size = big_.size;
		 sign = big_.sign;
		 return *this;
	 }
	 bool operator ==(const bignum & big_)
	 {
		 if (this == &big_)
			 return true;
		 bool ret = true;
		 if (size != big_.size || sign != big_.sign)
			 ret = false;
		 if (strcmp(ptr, big_.ptr)) ret = false;
		 return ret;
	 }

	 bool operator !=(const bignum & big_)
	 {
		 return !(*this == big_);
	 }

	 bignum operator +(const bignum & big_);							// 实现大数字加法
	 bignum operator -(const bignum & big_);							// 实现大数字减法
	 bignum operator *(const bignum & big_);							// 实现大数字乘法
	 bignum operator /(const bignum & big_);							// 实现大数字除法
};

int compare(const bignum & big1, const bignum & big2)
{
	if (big1.size <= big2.size)
		return 2;
	else
		return 1;
}

istream & operator >>(istream & is, bignum & big_)						// 输入重载
{
	char * str = new char[101];
	is >> str;
	int i = 0, j = 0;
	int tmpsize = 0;

	while (str[i] != '\0')
		i++;

	if (big_.ptr != NULL)
		delete[] big_.ptr;

	if (str[0] == '+' || str[0] == '-')
	{
		big_.sign = str[0];
		tmpsize = i - 1;
		i = 1;
	}
	else
	{
		big_.sign = '+';
		tmpsize = i;
		i = 0;
	}
		
	big_.size = tmpsize;
	big_.ptr = new char[tmpsize];

	for ( ; str[i] != '\0'; i++, j++)
		big_.ptr[j] = str[i];

	big_.ptr[j] = '\0';

	return is;
}

ostream & operator <<(ostream & os, bignum & big_)						// 输出重载
{
	if (big_.sign == '-')
		os << '-';
	os << big_.ptr;
	
	return os;
}

bignum bignum::operator +(const bignum & big_)						// 加法重载
{
	int up = 0;
	int down = 0;
	int flag = 0;

	bignum tmp;
	int ttmp;


	const bignum * bigger;
	const bignum * smaller;

	if (this->size <= big_.size)
	{
		bigger = &big_;
		smaller = this;
	}
	else
	{
		bigger = this;
		smaller = &big_;
	}

	tmp.sign = '+';

	up = bigger->size;
	down = smaller->size;

	tmp.ptr = new char[up + 2];

	for (int i = down - 1, j = up - 1, k = 0; i >= 0; i--, j--, k++)
	{
		ttmp = (bigger->ptr[j] - '0') + (smaller->ptr[i] - '0') + flag;
		tmp.ptr[k] = ttmp % 10 + '0';

		//cout << "bigger->ptr[j] = " << (bigger->ptr[j] - '0') << ", smaller->ptr[i] = " << (smaller->ptr[i] - '0') << ", k = " << k << ", bigtmp.ptr[k] = " << tmp.ptr[k] << '\t' << endl;

		if (ttmp >= 10)
			flag = 1;
		else
			flag = 0;
	}

	for (int i = up - down - 1, k = down; i >= 0; i--, k++)
	{
		ttmp = (bigger->ptr[i] - '0') + flag;
		tmp.ptr[k] = ttmp % 10 + '0';

		/*cout << "ptr[i] - '0' = " << (big_.ptr[i] - '0') << ", k = " << k << ", ptr[k] = " << tmp.ptr[k] << '\t' << endl;*/

		if (ttmp >= 10)
			flag = 1;
		else
			flag = 0;
	}

	if (flag == 1)
	{
		tmp.ptr[up] = 1 + '0';
		tmp.ptr[up + 1] = '\0';
		tmp.size = up + 1;
	}
	else
	{
		tmp.ptr[up] = '\0';
		tmp.size = up;
	}

	// 上面获得的tmp.ptr是一个反向字符串, 得倒置过来才是正确的结果
	int sizetmp = 0;
	for (; tmp.ptr[sizetmp] != '\0'; sizetmp++)
		;
	for (int i = 0, j = sizetmp - 1; i < j; i++, j--)
	{
		ttmp = tmp.ptr[i] - '0';
		tmp.ptr[i] = tmp.ptr[j];
		tmp.ptr[j] = ttmp + '0';
	}

	/*cout << tmp.ptr << endl;
	cout << tmp.size << endl;*/

	return tmp;
}

bignum bignum::operator-(const bignum & big_)
{
	bignum bigtmp;
	int up = 0;
	int down = 0;
	int flag = 0;
	int ttmp;

	const bignum * bigger;
	const bignum * smaller;

	if (this->size < big_.size)
	{
		bigger = &big_;
		smaller = this;
		bigtmp.sign = '-';
	}
	else if (this->size > big_.size)
	{
		bigger = this;
		smaller = &big_;
		bigtmp.sign = '+';
	}
	else
	{
		int bigt = strcmp(this->ptr, big_.ptr);
		if (bigt >= 0)
		{
			bigger = this;
			smaller = &big_;
			bigtmp.sign = '+';
		}
		else
		{
			bigger = &big_;
			smaller = this;
			bigtmp.sign = '-';
		}
	}

	up = bigger->size;
	down = smaller->size;

	bigtmp.size = bigger->size;
	bigtmp.ptr = new char[bigger->size + 1];

	for (int i = up - 1, j = down - 1, k = 0; j >= 0; i--, j--, k++)
	{
		ttmp = (bigger->ptr[i] - '0') - (smaller->ptr[j] - '0') - flag;

		if (ttmp < 0)
			flag = 1;
		else
			flag = 0;

		bigtmp.ptr[k] = (ttmp + 10) % 10 + '0';

		//cout << "bigger->ptr[i] = " << (bigger->ptr[i] - '0') << ", smaller->ptr[j] = " << (smaller->ptr[j] - '0') << ", k = " << k << ", bigtmp.ptr[k] = " << bigtmp.ptr[k] << '\t' << endl;
	}

	for (int i = up - down - 1, k = down; i >= 0; i--, k++)
	{
		ttmp = (bigger->ptr[i] - '0') - flag;
		if (ttmp < 0)
			flag = 1;
		else
			flag = 0;

		bigtmp.ptr[k] = (ttmp + 10) % 10 + '0';

		//cout << "bigger->ptr[i] = " << (bigger->ptr[i] - '0') << ", k = " << k << ", bigtmp.ptr[k] = " << bigtmp.ptr[k] << '\t' << endl;
	}

	bigtmp.ptr[up] = '\0';

	for (ttmp = up - 1; ttmp > 0 && bigtmp.ptr[ttmp] == '0'; ttmp--)
		;
	bigtmp.ptr[ttmp + 1] = '\0';

	// 上面获得的tmp.ptr是一个反向字符串, 得倒置过来才是正确的结果
	for (int i = 0, j = ttmp; i < j; i++, j--)
	{
		ttmp = bigtmp.ptr[i] - '0';
		bigtmp.ptr[i] = bigtmp.ptr[j];
		bigtmp.ptr[j] = ttmp + '0';
	}

	return bigtmp;
}

bignum bignum::operator *(const bignum & big_)
{
	bignum bigtmp;
	int flag = 1;

	char * str = new char[101];
	str[0] = '0'; str[1] = '\0';
	int str_size = 0;
	flag = strcmp(str, big_.ptr) && strcmp(str, this->ptr);

	if (flag == 0)
	{
		bigtmp.size = 1;
		bigtmp.sign = '+';
		bigtmp.ptr = new char[2];
		bigtmp.ptr[0] = '0';
		bigtmp.ptr[1] = '\0';
	}
	else
		bigtmp = *this;

	str[0] = '1';
	if (strcmp(str, big_.ptr) == 0)
		return bigtmp;

	while (flag)
	{
		bigtmp = bigtmp + *this;

		int str_flag = 1;
		for (int i = str_size; i >= 0; i--)
		{
			int tmp = (str[i] - '0') + str_flag;
			if (tmp >= 10)
			{
				tmp = tmp % 10;
				str_flag = 1;
			}
			else
				str_flag = 0;

			str[i] = '0' + tmp;
		}
		if (str_flag == 1)
		{
			for (int i = str_size; i >= 0; i--)
				str[i + 1] = str[i];
			str[0] = '1';
			str[str_size + 2] = '\0';
			str_size += 1;
		}

		flag = strcmp(str, big_.ptr);
	}

	delete[] str;
	return bigtmp;
}

//bignum bignum::operator /(const bignum & big_)
//{
//	bignum bigtmp;
//	int small = 0;
//
//	if (this->size < big_.size)
//		small = 1;
//	else if (this->size == big_.size)
//	{
//		int comsize = strcmp(this->ptr, big_.ptr);
//		if (comsize < 0)
//			small = 1;
//		else if (comsize == 0)
//		{
//			bigtmp.size = 1;
//			bigtmp.sign = '+';
//			bigtmp.ptr = new char[2];
//			bigtmp.ptr[0] = '1';
//			bigtmp.ptr[1] = '\0';
//		}
//	}
//	else
//	{
//		while ( this->sign == '+' && *this != )
//	}
//	
//	if (small == 1)
//	{
//		bigtmp.size = 1;
//		bigtmp.sign = '+';
//		bigtmp.ptr = new char[2];
//		bigtmp.ptr[0] = '0';
//		bigtmp.ptr[1] = '\0';
//	}
//
//	return bigtmp;
//}


int main(void)
{
	bignum big1, big2, bigsum, bigsub, bigmul;
	char oper;

	cin >> big1 >> oper >> big2;

	bigsum = big1 + big2;

	bigsub = big1 - big2;

	bigmul = big1 * big2;

	cout << "bigsum = " << bigsum << endl;

	cout << "bigsub = " << bigsub << endl;

	cout << "bigmul = " << bigmul << endl;

	//cout << big1 << '\t' <<  big2 << endl;

	return 0;
}