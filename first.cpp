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
	for (Iter_1 = mySet_1.begin(); Iter_1 != mySet_1.end(); Iter_1++){
		cout << *Iter_1 << endl;
	}
	
	//����������� ���������, ���������� ��������:
	set <int> temp_set;
	set <int>::iterator Temp_Iter;
	for (Iter_1 = mySet_1.begin(); Iter_1 != mySet_1.end(); Iter_1++){
		if (*Iter_1 % 2 == 0){
			cout << "lfdjslfjds: " << *Iter_1 << endl;
			temp_set.insert(*Iter_1);
		}
	}
	
	//�������� ���������, ���������� ��������:
	for (Temp_Iter = temp_set.begin(); Temp_Iter != temp_set.end(); Temp_Iter++){
		mySet_1.erase(*Temp_Iter);
	}
	
	//�������� ���������:
	cout << "ulalalalala" << endl;
	for (Iter_1 = mySet_1.begin(); Iter_1 != mySet_1.end(); Iter_1++){
		cout << *Iter_1 << endl;
	}
	
	//������� �������� ��������:
	return 0;
}
