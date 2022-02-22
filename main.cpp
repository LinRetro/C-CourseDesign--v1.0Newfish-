#include<HugeInt.h>
#include <iostream>
using namespace std;

HugeInt arr[1000];
int num;	//num用于记录已经录入的数据的个数

int main()
{
	char m[100];
	cin >> m;
	arr[0].ctoi(m);
	arr[0].Print();
}
