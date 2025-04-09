#pragma once
#include "Map1.h"
#include "Map2.h"

class MineControl
{
private:
	int mNum;
public:
	MineControl(Map1& map1) {
		mNum = map1.GetMineNum();
	}
	void ShowMenu();
	void OpenBox(Map1& map1, Map2& map2);
	void SetMine(Map1& map1, Map2& map2);
	int GetMine();
	void CancelMine(Map1& map1, Map2& map2);
	void DFSMap(int x, int y, Map1& map1, Map2& map2);
	void ShowLose(int row, int col, Map1& map1);
	void ShowWIN();
};

