#include <chrono>
#include <thread>
#include <time.h>
#include "Arr.h"
#include "Insert.h"
#include "RND.h"

int Arr::insert(int lenght){
	Uni_Input<int> inp('0', '9');
	return inp.input();
}

void Arr::insert_N(){
	bool check = false;
	while (!check) {
		std::cout << "\n Введите количество элементов массива, не более 100 которое делится без остатка: ";
		_N = insert(100);
		if (_N < 2 || _N > 100) {
			std::cout << "\n Значение за пределами диапазона!\n";
			pause();
			system("cls");
			continue;
		}
		for (int i = _N - 1; i != 1; i--) {
			if (_N % i == 0) {
				check = true;
				break;
			}
		}
		if (check == false) {
			std::cout << "\n у числа нет деления без остатка!\n";
			pause();
			system("cls");
			continue;
		}
	}
}

void Arr::insert_M(){
	bool check = false;
	while (!check) {
		std::cout << "\n Выберите количество потоков:\n ->";
		for (int i = _N - 1; i > 2; i--) {
			if (_N % i == 0) std::cout << " |" << i;
			if (i == 3) std::cout << "| \n -> ";
		}

		_M = insert(_N);
		if (_M < 2 || _M >= _N) {
			std::cout << "\n Значение за пределами диапазона!\n";
			pause();
			system("cls");
			continue;
		}
		else if (_N % _M != 0) {
			std::cout << "\n количество элементов не делится на количество потоков без остатка\n";
			pause();
			system("cls");
		}
		else{
			check = true;
		}
	}
}

void Arr::init_arr(){
	RND rnd(beg, end);
	for (int i = 0; i < _N; i++) {
		_arr.push_back(rnd.rnd());
	}
}

void Arr::init_arr_mass(){
	std::vector<int> temp;
	int interval = _N/_M;
	int count = 1;
	for (int i = 0; i != _arr.size(); i++) {
		temp.push_back(_arr[i]);
		if (count == interval) {
			_arr_mass.push_back(temp);
			temp.clear();
			count = 0;
		}
		count++;
	}
}

void Arr::show_arr(){
	int interval = _N / _M;
	int counter = 0;
	std::cout << std::endl << " ";
	for (int i = 0; i != _N; i++) {
		if (counter == interval) {
			std::cout << std::endl << " ";
			counter = 0;
		}
		std::cout << "| " << _arr[i] << " |";
		counter++;
	}
	std::cout << "\n ----------------------------------- " << std::endl;
}

void Arr::show_arr_mass(){
	std::cout << std::endl << " ";
	for (int i = 0; i != _arr_mass.size(); i++) {
		for (int j = 0; j != _arr_mass[i].size(); j++) {
			std::cout << "| " << _arr_mass[i][j] << " |";
		}
		std::cout << std::endl << " ";
	}
	std::cout << "\n ----------------------------------- " << std::endl;
}

void Arr::one_flow(){
	clock_t start, end;
	double time = 0;
	start = clock();
	int sum = 0;
	for (int i = 0; i != _arr.size(); i++) {
		sum += _arr[i];
	}
	std::cout << "\n Сумма всех членов составляет - " << sum << std::endl << " ";
	end = clock();
	time = ((double)end - (double)start) / ((double) CLOCKS_PER_SEC);
	std::cout << "\n Время выполнения в одном потоке: " << time << std::endl;
}

int Arr::flow(std::vector<int> arr)
{
	int sum = 0;
	for (int i = 0; i != arr.size(); i++) {
		sum += arr[i];
	}
	
	return sum;
}

void Arr::multi_flow(){
	clock_t start, end;
	double time = 0;
	start = clock();

	int sum = 0;
	std::vector<std::thread> threads;
	std::vector<int> results(_M); // Вектор для хранения результатов

	for (int i = 0; i != _M; i++) {
		// Используем лямбда-функцию для передачи аргументов в поток
		threads.push_back(std::thread([this, i, &results]() {
			results[i] = flow(_arr_mass[i]);
			}));
	}

	for (auto& thread : threads) {
		thread.join();
	}
	// Суммируем результаты
	for (int i = 0; i != _M; i++) {
		sum += results[i];
	}


	end = clock();
	time = ((double)end - (double)start) / ((double)CLOCKS_PER_SEC);
	std::cout << "\n Сумма всех членов составляет - " << sum << std::endl << " ";
	std::cout << "\n Время выполнения в " << _M <<" потоке: " << time << std::endl;
}

void Arr::pause(){
	std::this_thread::sleep_for(std::chrono::seconds(2));
}
