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
#define NEW_MAX_VALUE_RAND 200 + 1
#define COUNT_ELEMENTS 100

class Set{
	
	private:
		//���������� ���������:
		set <int> my_set, temp_set;
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
				cout << *iter << "   ";
			}
		}
		
		//�������� ������ ���������:
		void del_even_num (){
			temp_set.clear();
			
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
		
		//����������� �������� �����:
		bool is_prime_num (int x){
			for (int i = 2; i <= x/2; i++){
				if (x % i == 0){
					return false;
				}
			}
			return true;
		}
		
		//������ ��������� ����� ������������� ��������:
		void replace_not_prime_num (){
			temp_set.clear();
			
			for (iter = my_set.begin(); iter != my_set.end(); iter++){
				if (not is_prime_num(*iter)){	
					temp_set.insert(*iter);
				}
			}
			
			srand(time(NULL));
			int x = 0;
			for (iter = temp_set.begin(); iter != temp_set.end(); iter++){
				
				my_set.erase(*iter);
				
				do{
					x = rand() % NEW_MAX_VALUE_RAND;
				}
				while (
					(not is_prime_num(x))
					or (my_set.count(x) != 0)
				);
				my_set.insert(x);
			}
		}	
};

int main (){
	
	
	
	Set my_set_1, my_set_2;
	
	my_set_1.create_set();
	my_set_1.show_set();
	cout << endl << endl;
	
	my_set_1.del_even_num();
	my_set_1.show_set();
	cout << endl << endl;
	
	my_set_1.replace_not_prime_num();
	my_set_1.show_set();
	cout << endl << endl;
	
	//������� �������� ��������:
	return 0;
}
