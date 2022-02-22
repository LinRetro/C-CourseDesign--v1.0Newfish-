#ifndef _HugeInt_
#define _HugeInt_
#include <iostream>

using namespace std;

//����һ��˫������,���ڱ��泬������
//ÿһ���ṹ�����洢��λ��,�������������ʵ��,ͬʱ���ٿռ�ռ��
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

	//��������ַ���ת��Ϊ����
	void ctoi(char* num);
	void insert(List *ptr);

	//�������������
	HugeInt operator+(HugeInt const& rhs);
	HugeInt operator-(HugeInt const& rhs);
	HugeInt operator*(HugeInt const& rhs);
	HugeInt operator/(HugeInt const& rhs);
	HugeInt operator%(HugeInt const& rhs);

	//��ϵ���������

	//����/������������
	//ǰ�õ���
	HugeInt& operator++()
	{
		//�˴���ĩβ��++
		return *this;
	}

	//���õ���
	HugeInt operator++(int)
	{
		HugeInt temp = *this;
		//ĩλ��++;
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
		//��ʼ��������
		List* temp;
		if (i == 0)
			temp = &head;
		else {
			temp = new List;
			insert(temp);
		}
		//�жϷ���
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