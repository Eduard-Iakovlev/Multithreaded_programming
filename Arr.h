#pragma once
#include <vector>


class Arr {
public:
	Arr() = default;
	
	int insert(int length);
	void insert_N();
	void insert_M();
	void init_arr();
	void init_arr_mass();
	void show_arr();
	void show_arr_mass();

	void pause();

private:
	std::vector<int> _arr;
	std::vector<std::vector<int>> _arr_mass;
	int _N { 0 };
	int _M { 0 };
	int _resONE{ 0 };
	int _resM{ 0 };
	float timeONE{ 0 };
	float timeM{ 0 };
	const char beg = 1;
	const char end = 99;
};
