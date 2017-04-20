//Контейнеры:
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
	set <int> mySet;
	
	//Заполнение множества случайными целыми числами:
	srand(time(NULL));
	for (int i = 0; i < COUNT_ELEMENTS; i++){
		mySet.insert(rand() % MAX_VALUE_RAND);
	}
	
	//Возврат нулевого значения:
	return 0;
}
