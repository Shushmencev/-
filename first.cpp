//����������:
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
	set <int> mySet;
	
	//���������� ��������� ���������� ������ �������:
	srand(time(NULL));
	for (int i = 0; i < COUNT_ELEMENTS; i++){
		mySet.insert(rand() % MAX_VALUE_RAND);
	}
	
	//������� �������� ��������:
	return 0;
}
