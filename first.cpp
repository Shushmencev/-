//����������:
#include <algorithm>
#include <set>

//����-�����:
#include <iostream>

//��������� ��������� �����:
#include <ctime>
#include <cstdlib>

//������������ ���:
using namespace std;

//�������:
#define MAX_VALUE_RAND 100 + 1
#define COUNT_ELEMENTS 100

int main (){
	
	//���������� ���������:
	set <int> mySet_1, mySet_2;
	set <int>::iterator Iter_1, Iter_2;
	
	//���������� ��������� ���������� ������ �������:
	srand(time(NULL));
	for (int i = 0; i < COUNT_ELEMENTS; i++){
		mySet_1.insert(rand() % MAX_VALUE_RAND);
	}
	
	//�������� ���������:
	int val;
	for (Iter_1 = mySet_1.begin(); Iter_1 != mySet_1.end(); Iter_1++){
		cout << *Iter_1 << endl;
	}
	
	//������� �������� ��������:
	return 0;
}
