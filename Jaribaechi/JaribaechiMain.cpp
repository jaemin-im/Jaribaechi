/*#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define STUDENT 20

using namespace std;

typedef struct Group {
public:
	int seat[4] = { 0 };
} Group;

void InputSeat(Group* A, Group* B, Group* C, Group* D, Group* E);

void ChangeSeat(Group* A, Group* B, Group* C, Group* D, Group* E);

void GroupSwap(Group* A, Group* B);

enum GroupList
{
	A, B, C, D, E
};

int main(int argc, char** argv) {
	srand(time(NULL));

	Group A, B, C, D, E;

	InputSeat(&A, &B, &C, &D, &E);
	ChangeSeat(&A, &B, &C, &D, &E);

	return 0;
}

void InputSeat(Group* A, Group* B, Group* C, Group* D, Group* E) {
	char input;

	cout << "자리배치 프로그램" << endl;
	cout << "입력/출력 예시 : \n┌─┬─┐\n│ 1│ 2│\n├─┼─┤\n│ 3│ 4│\n└─┴─┘" << endl;
	cout << "<-> 1 2 3 4\n" << endl;
	cout << "모둠 모양 : \nA   B\nC D E\n" << endl;

	for (;;) {

		cout << "원래 자리를 입력하여 주십시오. (A모둠부터 E모둠까지 학생의 번호) " << endl;

		for (int i = GroupList::A; i <= GroupList::E; i++) {

			switch (i) {
			case GroupList::A:
				cout << "A모둠 입력 : " << endl;
				break;
			case GroupList::B:
				cout << "B모둠 입력 : " << endl;
				break;
			case GroupList::C:
				cout << "C모둠 입력 : " << endl;
				break;
			case GroupList::D:
				cout << "D모둠 입력 : " << endl;
				break;
			case GroupList::E:
				cout << "E모둠 입력 : " << endl;
				break;
			}

			for (int j = 0; j < 4; j++) {

				switch (i) {
				case GroupList::A:
					cin >> A->seat[j];
					break;
				case GroupList::B:
					cin >> B->seat[j];
					break;
				case GroupList::C:
					cin >> C->seat[j];
					break;
				case GroupList::D:
					cin >> D->seat[j];
					break;
				case GroupList::E:
					cin >> E->seat[j];
					break;
				}

			}

		}

		cout << "이 자리가 맞는지 확인하고 맞다면 y(Y)를, 아니면 이외의 문자를 입력하십시오.\n" << endl;

		for (int i = GroupList::A; i <= GroupList::E; i++) {

			switch (i) {
			case GroupList::A:
				cout << "A모둠" << endl;
				break;
			case GroupList::B:
				cout << "B모둠" << endl;
				break;
			case GroupList::C:
				cout << "C모둠" << endl;
				break;
			case GroupList::D:
				cout << "D모둠" << endl;
				break;
			case GroupList::E:
				cout << "E모둠" << endl;
				break;
			}

			for (int j = 0; j < 4; j++) {

				switch (i) {
				case GroupList::A:
					cout << A->seat[j] << " ";
					break;
				case GroupList::B:
					cout << B->seat[j] << " ";
					break;
				case GroupList::C:
					cout << C->seat[j] << " ";
					break;
				case GroupList::D:
					cout << D->seat[j] << " ";
					break;
				case GroupList::E:
					cout << E->seat[j] << " ";
					break;
				}

			}

			cout << endl;

		}

		cin >> input;

		if (input == 'Y' || input == 'y') goto INPUT_EXIT;
		else {
			cout << "자리를 재입력하십시오." << endl;
			continue;
		}
	}

INPUT_EXIT:
	cout << "새로운 자리배치를 시작합니다.\n" << endl;
	return;
}

void ChangeSeat(Group* A, Group* B, Group* C, Group* D, Group* E) {
	char GroupPlace[2][3] = { 'A', 'X', 'B', 'C', 'D', 'E' };

	cout << "현재 모둠 위치 : " << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << GroupPlace[i][j] << " ";
		}
		cout << endl;
	}

	cout << "D모둠(가운데 모둠)의 위치를 전환합니다." << endl;
	
	switch ((rand() % 5) + 1) {
	case 1:
		cout << "랜덤 결과 : D모둠과 A모둠의 위치를 전환합니다." << endl;
		GroupSwap(D, A);
		GroupPlace[0][0] = 'D';
		GroupPlace[1][1] = 'A';
		break;
	case 2:
		cout << "랜덤 결과 : D모둠과 B모둠의 위치를 전환합니다." << endl;
		GroupSwap(D, B);
		GroupPlace[0][2] = 'D';
		GroupPlace[1][1] = 'B';
		break;
	case 3:
		cout << "랜덤 결과 : D모둠과 C모둠의 위치를 전환합니다." << endl;
		GroupSwap(D, C);
		GroupPlace[1][0] = 'D';
		GroupPlace[1][1] = 'C';
		break;
	case 4:
		cout << "랜덤 결과 : D모둠의 위치는 전환되지 않습니다." << endl;
		break;
	case 5:
		cout << "D모둠과 E모둠의 위치를 전환합니다." << endl;
		GroupSwap(D, E);
		GroupPlace[1][2] = 'D';
		GroupPlace[1][1] = 'E';
		break;
	}

	cout << "D모둠 위치 전환 결과 : " << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << GroupPlace[i][j] << " ";
		}
		cout << endl;
	}
	
}

void GroupSwap(Group* A, Group* B) {
	Group* temp;
	temp = A;
	A = B;
	B = temp;
	return;
} */