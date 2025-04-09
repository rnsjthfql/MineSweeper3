#include "MineControl.h"

void MineControl::ShowMenu()
{
	cout << "===== 메뉴 =====" << endl;
	cout << "1. 칸열기" << endl;
	cout << "2. 지뢰표시" << endl;
	cout << "3. 지뢰취소" << endl;
	cout << "4. 게임종료" << endl;
	cout << "================" << endl;
}

void MineControl::OpenBox(Map1& map1, Map2& map2)
{
	int row;
	int col;

	while (1) {
		cout << "행 입력: ";
		cin >> row;
		if (row <= map1.GetRow())
			break;
		else {
			cout << "행을 다시 입력하세요." << endl;
		}
	}

	while (1) {
		cout << "열 입력: ";
		cin >> col;
		if (col <= map1.GetCol())
			break;
		else {
			cout << "열을 다시 입력하세요." << endl;
		}
	}
	
	row -= 1;
	col -= 1;

	if (map1[row][col] == 9 && map2[row][col] == 0) {		//지뢰 밟았을 경우
		ShowLose(row,col,map1);
		exit(1);
	}
	else if (map2[row][col] == 1) {
		cout << "이미 열려있는 칸입니다." << endl;
	}
	else if (map2[row][col] == 2) {
		cout << "지뢰표시가 되어있는 칸입니다." << endl;
	}
	else {
		cout << "칸을 엽니다" << endl;
		map2[row][col] = 1;
		if(map1[row][col] == 0)
			DFSMap(row, col, map1, map2);
	}
}

void MineControl::SetMine(Map1& map1, Map2& map2)
{
	int row;
	int col;
	
	while (1) {
		cout << "행 입력: ";
		cin >> row;
		if (row <= map1.GetRow())
			break;
		else {
			cout << "행을 다시 입력하세요." << endl;
		}
	}

	while (1) {
		cout << "열 입력: ";
		cin >> col;
		if (col <= map1.GetCol())
			break;
		else {
			cout << "열을 다시 입력하세요." << endl;
		}
	}

	row -= 1;
	col -= 1;

	if (map2[row][col] == 1) {
		cout << "이미 열려있는 칸입니다." << endl;
	}
	else {
		cout << "지뢰를 표시합니다." << endl;
		map2[row][col] = 2;		//지뢰표시
		if (map1[row][col] == 9) {
			mNum -= 1;
		}
	}
}

int MineControl::GetMine()
{
	return mNum;
}


void MineControl::CancelMine(Map1& map1, Map2& map2)
{
	int row;
	int col;
	
	while (1) {
		cout << "행 입력: ";
		cin >> row;
		if (row <= map1.GetRow())
			break;
		else {
			cout << "행을 다시 입력하세요." << endl;
		}
	}

	while (1) {
		cout << "열 입력: ";
		cin >> col;
		if (col <= map1.GetCol())
			break;
		else {
			cout << "열을 다시 입력하세요." << endl;
		}
	}

	row -= 1;
	col -= 1;

	if (map2[row][col] == 2) {
		cout << "지뢰표시를 취소합니다." << endl;
		map2[row][col] = 0;
		if (map1[row][col] == 9) {
			mNum += 1;
		}
	}
	else {
		cout << "지뢰표시가 되어있지 않습니다." << endl;
	}
}

void MineControl::DFSMap(int x, int y, Map1& map1, Map2& map2)
{
	if (x-1 >= 0 && map1[x - 1][y] != 9 && map2[x-1][y] == 0) {
		map2[x - 1][y] = 1;
		DFSMap(x - 1, y, map1, map2);
	}
	if (x+1 <= map1.GetRow()-1 && map1[x + 1][y] != 9 && map2[x+1][y] == 0) {
		map2[x + 1][y] = 1;
		DFSMap(x + 1, y, map1, map2);
	}
	if (y-1 >= 0 && map1[x][y - 1] != 9 && map2[x][y-1] == 0) {
		map2[x][y - 1] = 1;
		DFSMap(x, y - 1, map1, map2);
	}
	if (y+1 <= map1.GetCol()-1 && map1[x][y + 1] != 9 && map2[x][y+1] == 0) {
		map2[x][y + 1] = 1;
		DFSMap(x, y + 1, map1, map2);
	}
}



void MineControl::ShowLose(int row, int col, Map1& map1)
{
	cout << "지뢰를 밟았습니다!!!" << endl;
	for (int i = 0; i < map1.GetRow(); i++) {
		for (int j = 0; j < map1.GetCol(); j++) {
			if (i == row && j == col && map1[i][j] == 9) {
				cout << "★ ";
			}
			else if (map1[i][j] == 9) {
				cout << "☆ ";
			}
			else {
				cout << "■ ";
			}
		}
		cout << endl;
	}
}

void MineControl::ShowWIN()
{
	cout << "================================" << endl;
	cout << "★  ★★  ★  ★  ★★   ★ " << endl;
	cout << " ★★  ★★   ★  ★ ★  ★ " << endl;
	cout << "  ★    ★    ★  ★  ★ ★ " << endl;
	cout << "  ★    ★    ★  ★   ★★ " << endl;
	cout << "================================" << endl;
}


