#ifndef _HugeInt_
#define _HugeInt_
#include <iostream>

using namespace std;

//创建一个双向链表,用于保存超长整数
//每一个结构体最多存储三位数,方便算数运算的实现,同时减少空间占用
struct List
{
	List* prior = nullptr;
	int num = 0;
	List* next = nullptr;
};

class HugeInt
{
private:
	List head;
	int sign;
	int length;

public:
	HugeInt() :sign(1), length(0) {}
	HugeInt hugeInt(int n = 0, int s = 1, int l = 0) {
		head.num = n;
		sign = s;
		length = l;
	}
	void Print();

	//将传入的字符型转换为整型
	void ctoi(char* num);
	void insert(List *ptr);

	//算数运算符重载
	HugeInt operator+(HugeInt const& rhs);
	HugeInt operator-(HugeInt const& rhs);
	HugeInt operator*(HugeInt const& rhs);
	HugeInt operator/(HugeInt const& rhs);
	HugeInt operator%(HugeInt const& rhs);

	//关系运算符重载

	//增量/减量运算重载
	//前置递增
	HugeInt& operator++()
	{
		//此处是末尾数++
		return *this;
	}

	//后置递增
	HugeInt operator++(int)
	{
		HugeInt temp = *this;
		//末位数++;
		return temp;
	}
	
};
void HugeInt::Print() {
	List* ptr = & head;
	int l = 0;
	while (l < length) {
		if (ptr == &head)
			cout<< head.num * sign;
		else
		cout << ptr->num;
		ptr = ptr->next;
		l++;
	}
}


void HugeInt::insert(List *ptr) {
	if (head.next != nullptr) {
		ptr->prior = head.prior;
		head.prior = ptr;
		ptr->next = ptr->prior->next;
		ptr->prior->next = ptr;
	}
	else
	{
		head.next = ptr;
		head.prior = ptr;
		ptr->next = &head;
		ptr->prior = &head;
	}
}

void HugeInt::ctoi(char* num) {
	for (int i = 0;*num !='\0'; i++)
	{
		//开始建立链表
		List* temp;
		if (i == 0)
			temp = &head;
		else {
			temp = new List;
			insert(temp);
		}
		//判断符号
		if (i == 0 && *num == '-') {
			sign = -1;
			num++;
		}
		temp->num = *num - '0';
		length++;
		num++;
	}
	//head.num = head.num * sign;
	cout << length << endl;
}

#endif