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
		
		//���������� ��������:
		set <int> my_set, temp_set;
		set <int>::iterator iter;
		
	public:
		
		//��������� ���������:
		set <int> get_set (){
			return my_set;
		}
		
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
			cout << endl << endl;
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
		
		//�������� n ��������� ����� ���������:
		void del_after_x (){
			
			int x, n;
			
			//���� �������� x:
			do{
				cout << "������� x: ";
				cin >> x;
			}
			while (my_set.count(x) == 0);
			
			
			//���� �������� n:
			cout << "������� n: ";
			cin >> n;
			cout << endl;
	
			//�������� n ��������� ����� x:
			for (int i = 0; i < n; i++){
					if (my_set.upper_bound(x) != my_set.end()){
						my_set.erase(my_set.upper_bound(x));
					}
			}
		}
		
		
		void combine_sets (set <int> my_set_2){
			for (iter = my_set_2.begin(); iter != my_set_2.end(); iter++){
					my_set.insert(*iter);
				}	
		}
		
		
};

int main (){
	
	//��������� �������� �����:
	setlocale(LC_ALL, "Russian");
	
	//�������� ����������� ������ Set:
	Set my_set_1, my_set_2;
	
	//������� 1.1, 1.2:
	my_set_1.create_set();
	cout << "��������� 1:" << endl << endl;
	my_set_1.show_set();
	
	//������� 1.3, 1.4:
	//�������� ����������� ���������:
	my_set_1.del_even_num();
	cout << "��������� 1 ����� �������� ������ ���������:" << endl << endl;
	my_set_1.show_set();
	
	//������ ����������� ���������:
	my_set_1.replace_not_prime_num();
	cout << "��������� 1 ����� ������ ��������� ����� ��������:" << endl << endl;
	my_set_1.show_set();
	
	//������� 1.5:
	my_set_2.create_set();
	cout << "��������� 2:" << endl << endl;
	my_set_2.show_set();
	
	//������� 1.6:
	//�������� n ��������� ����� ���������:
	my_set_1.del_after_x();
	cout << "��������� 1 ����� �������� ��������� �����:" << endl << endl;
	my_set_1.show_set();
	
	//���������� � ��������� 1 ��������� ��������� 2:
	my_set_1.combine_sets(my_set_2.get_set());
	cout << "��������� 1 ����������� � ���������� 2:" << endl << endl;
	my_set_1.show_set();
	cout << "��������� 2:" << endl << endl;
	my_set_2.show_set();
	
	//������� �������� ��������:
	return 0;
}
