#include "JRBCH.h"

int main(int argc, char** argv) {
	int OriginalSeat[GROUP][GROUP_STUDENT] = { 0 }; // 원래 자리
	int RandomizedSeat[GROUP][GROUP_STUDENT] = { 0 }; // 랜덤화될 자리
	bool CheckExistNum[STUDENT] = { false }; // 중복 확인 배열

	char input; // 아무 키나 누르십시오 입력
	int randomize_count = 0; // 랜덤 횟수

	srand((unsigned)time(NULL)); // 랜덤 상수 초기화

	cout << "자리배치 프로그램" << endl;
	cout << "입력/출력 예시 : \n┌─┬─┐\n│ 1│ 2│\n├─┼─┤\n│ 3│ 4│\n└─┴─┘" << endl;
	cout << "<-> 1 2 3 4\n" << endl;
	cout << "모둠 모양 : \nA   B\nC D E\n" << endl;

	for (;;) {

		cout << "원래 자리를 입력하여 주십시오. (A모둠부터 E모둠까지 학생의 번호) " << endl;

		for (int i = 0; i < GROUP; i++) { // GROUP 수만큼 반복

			switch (i) { // 입력 확인
			case 0:
				cout << "A모둠 입력 : " << endl;
				break;
			case 1:
				cout << "B모둠 입력 : " << endl;
				break;
			case 2:
				cout << "C모둠 입력 : " << endl;
				break;
			case 3:
				cout << "D모둠 입력 : " << endl;
				break;
			case 4:
				cout << "E모둠 입력 : " << endl;
				break;
			}

			for (int j = 0; j < GROUP_STUDENT; j++) { // 모둠의 학생 수만큼 입력

				cin >> OriginalSeat[i][j];

			}

		}

		cout << "이 자리가 맞는지 확인하고 맞다면 y(Y)를, 아니면 이외의 문자를 입력하십시오.\n" << endl;

		cout << "┌─┬─┐          ┌─┬─┐" << endl;
		cout << "│" << ((OriginalSeat[0][0] / 10 != 0) ? "" : " ") << OriginalSeat[0][0] << "│" << ((OriginalSeat[0][1] / 10 != 0) ? "" : " ") << OriginalSeat[0][1] << "│" << "          │" << ((OriginalSeat[1][0] / 10 != 0) ? "" : " ") << OriginalSeat[1][0] << "│" << ((OriginalSeat[1][1] / 10 != 0) ? "" : " ") << OriginalSeat[1][1] << "│" << endl;
		cout << "├─┼─┤          ├─┼─┤" << endl;
		cout << "│" << ((OriginalSeat[0][2] / 10 != 0) ? "" : " ") << OriginalSeat[0][2] << "│" << ((OriginalSeat[0][3] / 10 != 0) ? "" : " ") << OriginalSeat[0][3] << "│" << "          │" << ((OriginalSeat[1][2] / 10 != 0) ? "" : " ") << OriginalSeat[1][2] << "│" << ((OriginalSeat[1][3] / 10 != 0) ? "" : " ") << OriginalSeat[1][3] << "│" << endl;
		cout << "└─┴─┘          └─┴─┘" << endl;
		cout << "┌─┬─┐┌─┬─┐┌─┬─┐" << endl;
		cout << "│" << ((OriginalSeat[2][0] / 10 != 0) ? "" : " ") << OriginalSeat[2][0] << "│" << ((OriginalSeat[2][1] / 10 != 0) ? "" : " ") << OriginalSeat[2][1] << "││" << ((OriginalSeat[3][0] / 10 != 0) ? "" : " ") << OriginalSeat[3][0] << "│" << ((OriginalSeat[3][1] / 10 != 0) ? "" : " ") << OriginalSeat[3][1] << "││" << ((OriginalSeat[4][0] / 10 != 0) ? "" : " ") << OriginalSeat[4][0] << "│" << ((OriginalSeat[4][1] / 10 != 0) ? "" : " ") << OriginalSeat[4][1] << "│" << endl;
		cout << "├─┼─┤├─┼─┤├─┼─┤" << endl;
		cout << "│" << ((OriginalSeat[2][2] / 10 != 0) ? "" : " ") << OriginalSeat[2][2] << "│" << ((OriginalSeat[2][3] / 10 != 0) ? "" : " ") << OriginalSeat[2][3] << "││" << ((OriginalSeat[3][2] / 10 != 0) ? "" : " ") << OriginalSeat[3][2] << "│" << ((OriginalSeat[3][1] / 10 != 0) ? "" : " ") << OriginalSeat[3][3] << "││" << ((OriginalSeat[4][2] / 10 != 0) ? "" : " ") << OriginalSeat[4][2] << "│" << ((OriginalSeat[4][3] / 10 != 0) ? "" : " ") << OriginalSeat[4][3] << "│" << endl;
		cout << "└─┴─┘└─┴─┘└─┴─┘" << endl;

		cin >> input;

		if (input == 'y' || input == 'Y') goto INPUT_EXIT; // 입력 확인
		else {
			cout << "자리를 재입력하십시오." << endl;
			continue;
		}
	}
	
INPUT_EXIT:

	fflush(stdin);
	cout << "새로운 자리배치를 시작합니다. 아무 키나 누르십시오.\n" << endl;
	input = getch();

	// 자리배치 시작

RERANDOMIZE:

	for (int i = 0; i < GROUP; i++) {
		for (int j = 0; j < GROUP_STUDENT; ) {
			int tempNum = randomize();
			if(CheckExistNum[tempNum] == false) { // 난수가 중복되지 않게 함
				CheckExistNum[tempNum] = true;
				RandomizedSeat[i][j] = tempNum+1;
				++j;
			}
		}
	} // 자리 랜덤화 완료, 예전 자리와 같은 조인지 확인

	for (int i = 0; i < GROUP; i++) {
		for (int j = 0; j < GROUP_STUDENT; j++) {
			if (RandomizedSeat[i][j] == OriginalSeat[i][0] ||
				RandomizedSeat[i][j] == OriginalSeat[i][1] ||
				RandomizedSeat[i][j] == OriginalSeat[i][2] ||
				RandomizedSeat[i][j] == OriginalSeat[i][3]) // 랜덤화 자리가 예전 자리와 같은 모둠일 때
			{
				for (int k = 0; k < STUDENT; k++) {
					CheckExistNum[k] = false;
				}
				++randomize_count;
				goto RERANDOMIZE; // 재랜덤화
			}
		}
	}
	
	// 자리배치 완료, 출력

	fflush(stdin);
	cout << "자리배치가 완료되었습니다. 아무 키나 누르십시오." << endl;
	input = getch();

	cout << "┌─┬─┐          ┌─┬─┐" << endl;
	cout << "│" << ((RandomizedSeat[0][0] / 10 != 0) ? "" : " ") << RandomizedSeat[0][0] << "│" << ((RandomizedSeat[0][1] / 10 != 0) ? "" : " ") << RandomizedSeat[0][1] << "│" << "          │" << ((RandomizedSeat[1][0] / 10 != 0) ? "" : " ") << RandomizedSeat[1][0] << "│" << ((RandomizedSeat[1][1] / 10 != 0) ? "" : " ") << RandomizedSeat[1][1] << "│" << endl;
	cout << "├─┼─┤          ├─┼─┤" << endl;
	cout << "│" << ((RandomizedSeat[0][2] / 10 != 0) ? "" : " ") << RandomizedSeat[0][2] << "│" << ((RandomizedSeat[0][3] / 10 != 0) ? "" : " ") << RandomizedSeat[0][3] << "│" << "          │" << ((RandomizedSeat[1][2] / 10 != 0) ? "" : " ") << RandomizedSeat[1][2] << "│" << ((RandomizedSeat[1][3] / 10 != 0) ? "" : " ") << RandomizedSeat[1][3] << "│" << endl;
	cout << "└─┴─┘          └─┴─┘" << endl;
	cout << "┌─┬─┐┌─┬─┐┌─┬─┐" << endl;
	cout << "│" << ((RandomizedSeat[2][0] / 10 != 0) ? "" : " ") << RandomizedSeat[2][0] << "│" << ((RandomizedSeat[2][1] / 10 != 0) ? "" : " ") << RandomizedSeat[2][1] << "││" << ((RandomizedSeat[3][0] / 10 != 0) ? "" : " ") << RandomizedSeat[3][0] << "│" << ((RandomizedSeat[3][1] / 10 != 0) ? "" : " ") << RandomizedSeat[3][1] << "││" << ((RandomizedSeat[4][0] / 10 != 0) ? "" : " ") << RandomizedSeat[4][0] << "│" << ((RandomizedSeat[4][1] / 10 != 0) ? "" : " ") << RandomizedSeat[4][1] << "│" << endl;
	cout << "├─┼─┤├─┼─┤├─┼─┤" << endl;
	cout << "│" << ((RandomizedSeat[2][2] / 10 != 0) ? "" : " ") << RandomizedSeat[2][2] << "│" << ((RandomizedSeat[2][3] / 10 != 0) ? "" : " ") << RandomizedSeat[2][3] << "││" << ((RandomizedSeat[3][2] / 10 != 0) ? "" : " ") << RandomizedSeat[3][2] << "│" << ((RandomizedSeat[3][3] / 10 != 0) ? "" : " ") << RandomizedSeat[3][3] << "││" << ((RandomizedSeat[4][2] / 10 != 0) ? "" : " ") << RandomizedSeat[4][2] << "│" << ((RandomizedSeat[4][3] / 10 != 0) ? "" : " ") << RandomizedSeat[4][3] << "│" << endl;
	cout << "└─┴─┘└─┴─┘└─┴─┘" << endl;

	cout << "자리/조 중복을 피하기 위한 RERANDOMIZE 횟수 : " << randomize_count << "회" << endl << endl << "자리배치 프로그램을 종료합니다. 아무 키나 누르십시오." << endl;
	input = getch();
	return 0;
}

int randomize(void) {
	return (rand() % 20); // 랜덤 함수
}