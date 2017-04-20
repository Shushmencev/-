//Контейнеры:
#include <set>

//Ввод-вывод:
#include <iostream>

//Генерация случайных чисел:
#include <ctime>
#include <cstdlib>

//Пространство имён:
using namespace std;

int main (){
	
	set <int> mySet;
	
	srand(time(NULL));
	for (int i = 0; i < 10; i++){
		cout << rand() % 101 << endl;
	}
	
	return 0;
}
