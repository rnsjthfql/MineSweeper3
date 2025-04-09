#include "Map2.h"

Map2::Map2(Map1& map1)
{
	x2 = map1.GetRow();
	y2 = map1.GetCol();
	map2 = new int*[x2];
	for (int i = 0; i < x2; i++) {
		map2[i] = new int[y2];
	}
}

void Map2::FirstMap2()
{
	for (int i = 0; i < x2; i++) {
		for (int j = 0; j < y2; j++) {
			map2[i][j] = 0;
		}
	}
}


void Map2::ShowMap(Map1& map1)
{
	for (int i = 0; i < x2; i++) {
		for (int j = 0; j < y2; j++) {
			if (map2[i][j] == 1) {		//Ä­¿­¸²
				cout << map1[i][j] << " ";
			}
			else if (map2[i][j] == 2) {		//Áö·ÚÇ¥½Ã
				cout << "¡Ú ";
			}
			else {
				cout << "¡à ";
			}
		}
		cout << endl;
	}
}



int Map2::GetRow()
{
	return x2;
}

int Map2::GetCol()
{
	return y2;
}


Map2::~Map2()
{
	for (int i = 0; i < x2; i++) {
		delete[] map2[i];
	}
	delete[] map2;
}


