#pragma once
#include "Map1.h"

class Map2
{
private:
	int x2;
	int y2;
	int** map2;
public:
	Map2(Map1& map1);
	void FirstMap2();
	void ShowMap(Map1& map1);
	int GetRow();
	int GetCol();
	~Map2();

	int*& operator[](const int& idx) {
		return map2[idx];
	}
};

