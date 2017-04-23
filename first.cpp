//Контейнеры:
#include <algorithm>
#include <set>
#include <stack>

//Ввод-вывод:
#include <iostream>

//Генерация случайных чисел:
#include <ctime>
#include <cstdlib>

//Пространство имён:
using namespace std;

//Макросы:
#define MAX_VALUE_RAND 100 + 1
#define NEW_MAX_VALUE_RAND 200 + 1
#define COUNT_ELEMENTS 100

class Set{
	
	private:
		
		//Объявление множеств:
		set <int> my_set, temp_set;
		set <int> :: iterator iter;
		
	public:
		
		//Получение множества:
		set <int> get_set (){
			return my_set;
		}
		
		//Заполнение множества элементами заданного множества:
		void copy_elements (set <int> temp_set){
			my_set = temp_set;
		}
		
		//Заполнение множества случайными целыми числами:
		void create_elements (){
			srand(time(NULL));
			for (int i = 0; i < COUNT_ELEMENTS; i++){
				my_set.insert(rand() % MAX_VALUE_RAND);
			}
		}
		
		//Просмотр множества:
		void show_set (){
			for (iter = my_set.begin(); iter != my_set.end(); iter++){
				cout << *iter << "   ";
			}
			cout << endl << endl;
		}
		
		//Удаление чётных элементов:
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
		
		//Определение простоты числа:
		bool is_prime_num (int x){
			for (int i = 2; i <= x/2; i++){
				if (x % i == 0){
					return false;
				}
			}
			return true;
		}
		
		//Замена непростых чисел произвольными простыми:
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
		
		//Удаление n элементов после заданного:
		void del_after_x (){
			
			int x, n;
			
			//Ввод значения x:
			do{
				cout << "Введите x: ";
				cin >> x;
			}
			while (my_set.count(x) == 0);
			
			
			//Ввод значения n:
			cout << "Введите n: ";
			cin >> n;
			cout << endl;
	
			//Удаление n элементов после x:
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

class Stack{
	
	private:
		
		//Объявление стека:
		stack <int> my_stack;
		
	public:
		
		//Получение стека:
		stack <int> get_stack (){
			
			return my_stack;
		}
		
		//Просмотр элементов стека:
		void show_stack (){
			
			stack <int> temp_stack = my_stack;
			
			while (not temp_stack.empty()){
				cout << temp_stack.top() << "\t";
				temp_stack.pop();
			}
			
			cout << endl << endl;
		}
		
		//Заполнение стека произвольными элементами:
		void create_elements (int n, int max_value){
			
			srand(time(NULL));
			for (int i = 0; i < n; i++){
				my_stack.push(rand() % (max_value + 1));
			}
		}
		
		//Сортировка стека по убыванию элементов:
		void sort_stack_top_max (){
			
			stack <int> temp_stack = my_stack;
			multiset <int> temp_multiset;
			multiset <int>::iterator iter;
			
			while (not temp_stack.empty()){
				temp_multiset.insert(temp_stack.top());
				temp_stack.pop();
			}
			
			for (iter = temp_multiset.begin(); iter != temp_multiset.end(); iter++){
				temp_stack.push(*iter);
			}
			
			my_stack = temp_stack;
		}
		
		//Сортировка стека по возрастанию элементов:
		void sort_stack_top_min (){
			
			stack <int> temp_stack = my_stack;
			multiset <int> temp_multiset;
			multiset <int>::iterator iter;
			
			while (not temp_stack.empty()){
				temp_multiset.insert(temp_stack.top());
				temp_stack.pop();
			}
			
			for (iter = --temp_multiset.end(); iter != --temp_multiset.begin(); iter--){
				temp_stack.push(*iter);
			}
			
			my_stack = temp_stack;
		}
		
		//Определение простоты числа:
		bool is_prime_num (int x){
			for (int i = 2; i <= x/2; i++){
				if (x % i == 0){
					return false;
				}
			}
			return true;
		}
		
		//Поиск простого числа в стеке:
		int find_prime_num (){
			stack <int> temp_stack = my_stack;
			
			while (not temp_stack.empty()){
				if (is_prime_num(temp_stack.top())){
					return temp_stack.top();
				}
				else{
					temp_stack.pop();
				}
			}
			
			//1 - Стек не содержит простых чисел
			return 1;

		}
		
		//Создание множества из простых элементов стека:
		set <int> get_set_of_prime_num (){
			set <int> temp_set;
			stack <int> temp_stack = my_stack;
			
			while (not temp_stack.empty()){
				if (is_prime_num(temp_stack.top())){
					temp_set.insert(temp_stack.top());
					temp_stack.pop();
				}
				else{
					temp_stack.pop();
				}
			}
			
			return temp_set;
				
		}
			
};

class Multiset{
	
	private:
		multiset <int> my_multiset;
		multiset <int> :: iterator iter;
		
	public:
		
		//Объединение элементов стека и множества в мультимножество:
		void create_elements (stack <int> temp_stack, set <int> temp_set){
			
			//Добавляем в мультимножество элементы стека:
			while (not temp_stack.empty()){
				my_multiset.insert(temp_stack.top());
				temp_stack.pop();
			}	
			
			//Добавляем в мультимножество элементы множества:
			for (iter = temp_set.begin(); iter != temp_set.end(); iter++){
				my_multiset.insert(*iter);
			}
			
		}
		
		void show (){
			for (iter = my_multiset.begin(); iter != my_multiset.end(); iter++){
				cout << *iter << "\t";
			}
		}
		
};

int main (){
	
	//Поддержка русского языка:
	setlocale(LC_ALL, "Russian");
	
	//Создание экземпляров класса Set:
	Set my_set_1, my_set_2;
	
	//Задания 1.1, 1.2:
	my_set_1.create_elements();
	cout << "Множество 1:" << endl << endl;
	my_set_1.show_set();
	
	//Задания 1.3, 1.4:
	//Удаление определённых элементов:
	my_set_1.del_even_num();
	cout << "Множество 1 после удаления чётных элементов:" << endl << endl;
	my_set_1.show_set();
	
	//Замена определённых элементов:
	my_set_1.replace_not_prime_num();
	cout << "Множество 1 после замены непростых чисел простыми:" << endl << endl;
	my_set_1.show_set();
	
	//Задание 1.5:
	//Создание элементов множества 2:
	my_set_2.create_elements();
	cout << "Множество 2:" << endl << endl;
	my_set_2.show_set();
	
	//Задание 1.6:
	//Удаление n элементов после заданного:
	my_set_1.del_after_x();
	cout << "Множество 1 после удаления требуемых чисел:" << endl << endl;
	my_set_1.show_set();
	
	//Добавление к множеству 1 элементов множества 2:
	my_set_1.combine_sets(my_set_2.get_set());
	cout << "Множество 1 объединения с множеством 2:" << endl << endl;
	my_set_1.show_set();
	cout << "Множество 2:" << endl << endl;
	my_set_2.show_set();
	
	//Создание экземпляров класса Stack:
	Stack my_stack_1, my_stack_2;
	
	//Задание 2.1:
	my_stack_1.create_elements(5, 100);
	cout << "Стек 1:" << endl << endl;
	my_stack_1.show_stack();
	
	//Задания 2.2, 2.3:
	my_stack_1.sort_stack_top_max();
	cout << "Стек 1 после сортировки по убыванию:" << endl << endl;
	my_stack_1.show_stack();
	
	//Задание 2.4:
	int x = my_stack_1.find_prime_num();
	if (x == 1){
		cout << "Стек не содержит простых чисел" << endl << endl;
	}
	else{
		cout << "Первое простое число из стека: " << x << endl << endl;
	}
	
	//Задания 2.5, 2.6:
	Set my_set_3;
	my_set_3.copy_elements(my_stack_1.get_set_of_prime_num());
	cout << "Множество 3:" << endl << endl;
	my_set_3.show_set();
	
	//Задание 2.7, 2.8:
	my_stack_1.sort_stack_top_min();
	cout << "Стек 1 после сортировки по возрастанию:" << endl << endl;
	my_stack_1.show_stack();
	
	//Задания 2.9, 2.10:
	Multiset my_multiset_1;
	my_multiset_1.create_elements(my_stack_1.get_stack(), my_set_3.get_set());
	cout << "Новый контейнер, полученный из элементов стека и множества:" << endl << endl;
	my_multiset_1.show();
		
	
	//Возврат нулевого значения:
	return 0;
}
