#pragma once
#include <iostream>
#include <random>
using namespace std;

class Map1
{
private:
	int** map1;
	int x;
	int y;
	int num = 0;
	int mineNum;
public:
	Map1(int level);
	void SettingMine();
	void ShowMineMap();
	void CountMap();
	int GetMineNum();
	int GetRow();
	int GetCol();
	~Map1();

	int*& operator[](const int& idx) {
		return map1[idx];
	}
};

