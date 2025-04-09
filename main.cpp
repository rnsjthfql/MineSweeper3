#include "MineControl.h"
#include "Map1.h"
#include <Windows.h>


int main() {
	int level;
	int menu;
	int mine;

	cout << "지뢰찾기 게임" << endl;

	while (1) {
		cout << "레벨을 선택하세요: ";
		cin >> level;

		if (level == 1 || level == 2 || level == 3) {
			Map1* map = new Map1(level);
			map->SettingMine();
			map->CountMap();
			Map2* map2 = new Map2(*map);
			map2->FirstMap2();
			mine = map->GetMineNum();

			MineControl mc(*map);

			while (1) {
				system("cls");
				map2->ShowMap(*map);
				mc.ShowMenu();
				cout << "메뉴를 선택하세요: ";
				cin >> menu;

				if (menu == 1) {		//칸 열기
					mc.OpenBox(*map, *map2);
					if (mc.GetMine() == 0) {
						mc.ShowWIN();
						return 0;
					}
					Sleep(1000);
					continue;
				}
				else if (menu == 2) {		//지뢰표시
					if (mine == 0) {
						cout << "표시가능한 지뢰개수가 없습니다." << endl;
						continue;
					}
					mc.SetMine(*map, *map2);
					mine -= 1;
					cout << "표시가능한 지뢰갯수: " << mine << "개" << endl;
					Sleep(1000);
					continue;
				}
				else if (menu == 3) {		//지뢰취소
					mc.CancelMine(*map, *map2);
					mine += 1;
					cout << "표시가능한 지뢰갯수: " << mine << "개" << endl;
					Sleep(1000);
					continue;
				}
				else if (menu == 4) {
					cout << "게임을 종료합니다." << endl;
					return 0;
				}
				else {
					cout << "다시 입력하세요." << endl;
					Sleep(1000);
					continue;
				}
			}

		}
		else {
			cout << "레벨을 다시 입력하세요." << endl;
			continue;
		}
	}
	return 0;
}

