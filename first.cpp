//Контейнеры:
#include <algorithm>
#include <set>

//Ввод-вывод:
#include <iostream>

//Генерация случайных чисел:
#include <ctime>
#include <cstdlib>

//Пространство имён:
using namespace std;

//Макросы:
#define MAX_VALUE_RAND 100 + 1
#define COUNT_ELEMENTS 100

int main (){
	
	//Объявление множества:
	set <int> mySet_1, mySet_2;
	set <int>::iterator Iter_1, Iter_2;
	
	//Заполнение множества случайными целыми числами:
	srand(time(NULL));
	for (int i = 0; i < COUNT_ELEMENTS; i++){
		mySet_1.insert(rand() % MAX_VALUE_RAND);
	}
	
	//Просмотр множества:
	for (Iter_1 = mySet_1.begin(); Iter_1 != mySet_1.end(); Iter_1++){
		cout << *Iter_1 << endl;
	}
	
	//Определение элементов, подлежащих удалению:
	set <int> temp_set;
	set <int>::iterator Temp_Iter;
	for (Iter_1 = mySet_1.begin(); Iter_1 != mySet_1.end(); Iter_1++){
		if (*Iter_1 % 2 == 0){
			cout << "lfdjslfjds: " << *Iter_1 << endl;
			temp_set.insert(*Iter_1);
		}
	}
	
	//Удаление элементов, подлежащих удалению:
	for (Temp_Iter = temp_set.begin(); Temp_Iter != temp_set.end(); Temp_Iter++){
		mySet_1.erase(*Temp_Iter);
	}
	
	//Просмотр множества:
	cout << "ulalalalala" << endl;
	for (Iter_1 = mySet_1.begin(); Iter_1 != mySet_1.end(); Iter_1++){
		cout << *Iter_1 << endl;
	}
	
	//Возврат нулевого значения:
	return 0;
}
