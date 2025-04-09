#include "MineControl.h"
#include "Map1.h"
#include <Windows.h>


int main() {
	int level;
	int menu;
	int mine;

	cout << "����ã�� ����" << endl;

	while (1) {
		cout << "������ �����ϼ���: ";
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
				cout << "�޴��� �����ϼ���: ";
				cin >> menu;

				if (menu == 1) {		//ĭ ����
					mc.OpenBox(*map, *map2);
					if (mc.GetMine() == 0) {
						mc.ShowWIN();
						return 0;
					}
					Sleep(1000);
					continue;
				}
				else if (menu == 2) {		//����ǥ��
					if (mine == 0) {
						cout << "ǥ�ð����� ���ڰ����� �����ϴ�." << endl;
						continue;
					}
					mc.SetMine(*map, *map2);
					mine -= 1;
					cout << "ǥ�ð����� ���ڰ���: " << mine << "��" << endl;
					Sleep(1000);
					continue;
				}
				else if (menu == 3) {		//�������
					mc.CancelMine(*map, *map2);
					mine += 1;
					cout << "ǥ�ð����� ���ڰ���: " << mine << "��" << endl;
					Sleep(1000);
					continue;
				}
				else if (menu == 4) {
					cout << "������ �����մϴ�." << endl;
					return 0;
				}
				else {
					cout << "�ٽ� �Է��ϼ���." << endl;
					Sleep(1000);
					continue;
				}
			}

		}
		else {
			cout << "������ �ٽ� �Է��ϼ���." << endl;
			continue;
		}
	}
	return 0;
}

