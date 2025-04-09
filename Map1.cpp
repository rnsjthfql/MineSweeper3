#include "Map1.h"

Map1::Map1(int level)
{
	switch (level) {
	case 1:
		x = 6;
		y = 6;
		map1 = new int*[x];
		for (int i = 0; i < x; i++) {
			map1[i] = new int[y];
		}
		mineNum = 8;
		break;
	case 2:
		x = 10;
		y = 10;
		map1 = new int*[x];
		for (int i = 0; i < x; i++) {
			map1[i] = new int[y];
		}
		mineNum = 15;
		break;
	case 3:
		x = 15;
		y = 15;
		map1 = new int*[x];
		for (int i = 0; i < x; i++) {
			map1[i] = new int[y];
		}
		mineNum = 30;
		break;
	default:
		cout << "레벨을 다시 입력하세요." << endl;
	}
}

void Map1::SettingMine()
{
	int xpos;
	int ypos;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			map1[i][j] = 0;
		}
	}

	for (int k = 0; k < mineNum; k++) {
		random_device rd;
		mt19937 mt(rd());
		uniform_int_distribution<int> dist(0, x-1);
		auto xpos = dist(mt);
		auto ypos = dist(mt);
		map1[xpos][ypos] = 9;
		num += 1;
	}
}


void Map1::ShowMineMap()
{
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << map1[i][j] << " ";
		}
		cout << endl;
	}
}

void Map1::CountMap()
{
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (map1[i][j] != 9) {
				int mc = 0;
				if (j - 1 != -1 && map1[i][j - 1] == 9) mc++;
				if (j + 1 != y && map1[i][j + 1] == 9) mc++;
				if (i - 1 != -1 && map1[i - 1][j] == 9) mc++;
				if (i + 1 != x && map1[i + 1][j] == 9) mc++;
				map1[i][j] = mc;
			}
		}
	}
}

int Map1::GetMineNum()
{
	return num;
}

int Map1::GetRow()
{
	return x;
}

int Map1::GetCol()
{
	return y;
}


Map1::~Map1()
{
	for (int i = 0; i < x; i++) {
		delete[] map1[i];
	}
	delete[] map1;
}
