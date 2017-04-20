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

class Set{
	private:
		//���������� ���������:
		set <int> my_set;
		set <int>::iterator iter;
		
	public:
		//���������� ��������� ���������� ������ �������:
		set <int> create_set (){
			srand(time(NULL));
			for (int i = 0; i < COUNT_ELEMENTS; i++){
				my_set.insert(rand() % MAX_VALUE_RAND);
			}
			return my_set;
		}
		
		//�������� ���������:
		void show_set (){
			for (iter = my_set.begin(); iter != my_set.end(); iter++){
				cout << *iter << endl;
			}
		}
		
		//����������� ���������, ���������� ��������:
		void del_even_num (){
			set <int> temp_set;
			
			for (iter = my_set.begin(); iter != my_set.end(); iter++){
				if (*iter % 2 == 0){
					temp_set.insert(*iter);
				}
			}
			
			for (iter = temp_set.begin(); iter != temp_set.end(); iter++){
				if (*iter % 2 == 0){
					my_set.erase(*iter);
				}
			}
		}
};

int main (){
	Set my_set_1, my_set_2;
	my_set_1.create_set();
	my_set_1.show_set();
	my_set_1.del_even_num();
	my_set_1.show_set();
	
	//������� �������� ��������:
	return 0;
}
