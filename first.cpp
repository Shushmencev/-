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
				cout << *iter << " ";
			}
		}
		
		//�������� ������ ���������:
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
			set <int> temp_set;
			
			for (iter = my_set.begin(); iter != my_set.end(); iter++){
				if (not is_prime_num(*iter)){
					my_set.erase(*iter);
					srand(time(NULL));
					int x;
					do{
						x = rand() % MAX_VALUE_RAND;
					}
					while (not is_prime_num(x));
					my_set.insert(x);
				}
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
	
	my_set_1.
	
	cout << my_set_1.is_prime_num(1);
	cout << my_set_1.is_prime_num(5);
	cout << my_set_1.is_prime_num(10);
	
	//������� �������� ��������:
	return 0;
}
