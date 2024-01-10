#pragma once
#include <cstdlib>
#include <time.h>

class RND {
public:
	RND(int start, int end) : _start(start), _end(end) {}
	int rnd();
private:
	int _start;
	int _end;
	int _seed = time(NULL);
};
