#include <iostream>
#include <cstdlib>
#include <cmath>
#define MAX 500000

using namespace std;

int main() {
	int goalChannel, NumFailureButton, curChannel(100), clickNum(0), cnt(0), min(0);
	cin >> goalChannel;
	cin >> NumFailureButton;

	bool FailureButton[11] = { false, };
	for (int i = 0; i < NumFailureButton; i++) {
		int Failure;
		cin >> Failure;
		FailureButton[Failure] = true;
	}

	int channel = goalChannel;
	if (NumFailureButton == 10) {
		clickNum = abs(goalChannel - curChannel);
	}
	else if (abs(goalChannel - 100) < 3) {
		clickNum = abs(goalChannel - curChannel);
	}
	else {
		min = 500000;
		bool flag = true;
		for (int i = 0; i < 2*MAX; i++) {
			flag = true;
			int tmp = i;

			cnt = log10(i);
			if (i == 0) {
				cnt = 1;
			}
			for (int j = cnt; j >= 0; j--) {
				int n = tmp / pow(10, j) ;
				tmp = tmp % (int)pow(10, j);
				if (FailureButton[n]) {
					flag = false;
					break;
				}
			}
			if (flag && min > abs(goalChannel - i)) {
				min = abs(goalChannel - i);
				curChannel = i;
			}
		}
		if (curChannel == 0) {
			if (min > 100) {
				clickNum = min - 100;
			}
			else {
				clickNum = min + 1;
			}
		}
		else {
			clickNum = min + log10(curChannel) + 1;
			if(abs(goalChannel - 100) < clickNum){
				clickNum = abs(goalChannel - 100);
			}
		}
	}

	cout << clickNum;

	return 0;
}