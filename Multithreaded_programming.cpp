#include <iostream>
#include "Windows.h"
#include "Arr.h"

int main(){
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	Arr arr;
	system("cls");
	arr.insert_N();
	arr.insert_M();
	arr.init_arr();
	arr.init_arr_mass();
	arr.show_arr();
	arr.show_arr_mass();
	arr.one_flow();

	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo);

	int numCPU = sysinfo.dwNumberOfProcessors;
	std::cout << "\n Количество ядер процессора " << numCPU << std::endl;
}
