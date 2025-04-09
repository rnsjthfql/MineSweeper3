#include "MineControl.h"

void MineControl::ShowMenu()
{
	cout << "===== �޴� =====" << endl;
	cout << "1. ĭ����" << endl;
	cout << "2. ����ǥ��" << endl;
	cout << "3. �������" << endl;
	cout << "4. ��������" << endl;
	cout << "================" << endl;
}

void MineControl::OpenBox(Map1& map1, Map2& map2)
{
	int row;
	int col;

	while (1) {
		cout << "�� �Է�: ";
		cin >> row;
		if (row <= map1.GetRow())
			break;
		else {
			cout << "���� �ٽ� �Է��ϼ���." << endl;
		}
	}

	while (1) {
		cout << "�� �Է�: ";
		cin >> col;
		if (col <= map1.GetCol())
			break;
		else {
			cout << "���� �ٽ� �Է��ϼ���." << endl;
		}
	}
	
	row -= 1;
	col -= 1;

	if (map1[row][col] == 9 && map2[row][col] == 0) {		//���� ����� ���
		ShowLose(row,col,map1);
		exit(1);
	}
	else if (map2[row][col] == 1) {
		cout << "�̹� �����ִ� ĭ�Դϴ�." << endl;
	}
	else if (map2[row][col] == 2) {
		cout << "����ǥ�ð� �Ǿ��ִ� ĭ�Դϴ�." << endl;
	}
	else {
		cout << "ĭ�� ���ϴ�" << endl;
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
		cout << "�� �Է�: ";
		cin >> row;
		if (row <= map1.GetRow())
			break;
		else {
			cout << "���� �ٽ� �Է��ϼ���." << endl;
		}
	}

	while (1) {
		cout << "�� �Է�: ";
		cin >> col;
		if (col <= map1.GetCol())
			break;
		else {
			cout << "���� �ٽ� �Է��ϼ���." << endl;
		}
	}

	row -= 1;
	col -= 1;

	if (map2[row][col] == 1) {
		cout << "�̹� �����ִ� ĭ�Դϴ�." << endl;
	}
	else {
		cout << "���ڸ� ǥ���մϴ�." << endl;
		map2[row][col] = 2;		//����ǥ��
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
		cout << "�� �Է�: ";
		cin >> row;
		if (row <= map1.GetRow())
			break;
		else {
			cout << "���� �ٽ� �Է��ϼ���." << endl;
		}
	}

	while (1) {
		cout << "�� �Է�: ";
		cin >> col;
		if (col <= map1.GetCol())
			break;
		else {
			cout << "���� �ٽ� �Է��ϼ���." << endl;
		}
	}

	row -= 1;
	col -= 1;

	if (map2[row][col] == 2) {
		cout << "����ǥ�ø� ����մϴ�." << endl;
		map2[row][col] = 0;
		if (map1[row][col] == 9) {
			mNum += 1;
		}
	}
	else {
		cout << "����ǥ�ð� �Ǿ����� �ʽ��ϴ�." << endl;
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
	cout << "���ڸ� ��ҽ��ϴ�!!!" << endl;
	for (int i = 0; i < map1.GetRow(); i++) {
		for (int j = 0; j < map1.GetCol(); j++) {
			if (i == row && j == col && map1[i][j] == 9) {
				cout << "�� ";
			}
			else if (map1[i][j] == 9) {
				cout << "�� ";
			}
			else {
				cout << "�� ";
			}
		}
		cout << endl;
	}
}

void MineControl::ShowWIN()
{
	cout << "================================" << endl;
	cout << "��  �ڡ�  ��  ��  �ڡ�   �� " << endl;
	cout << " �ڡ�  �ڡ�   ��  �� ��  �� " << endl;
	cout << "  ��    ��    ��  ��  �� �� " << endl;
	cout << "  ��    ��    ��  ��   �ڡ� " << endl;
	cout << "================================" << endl;
}


