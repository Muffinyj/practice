#include <iostream>
#include <algorithm>

using namespace std;

int maxCount = 1;

void checkRowCandy(char** candy,int n) {
	int maxCnt = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (candy[i][j] == candy[i][j + 1]) {
				cnt++;
			}
			else {
				if (maxCnt < cnt) {
					maxCnt = cnt;
				}
				cnt = 1;
			}
		}
		if (maxCnt < cnt) {
			maxCnt = cnt;
		}
	}
	if (maxCnt > maxCount) {
		maxCount = maxCnt;
	}
}

void checkColCandy(char** candy, int n) {
	int maxCnt = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (candy[j][i] == candy[j + 1][i]) {
				cnt++;
			}
			else {
				if (maxCnt < cnt) {
					maxCnt = cnt;
				}
				cnt = 1;
			}
		}
		if (maxCnt < cnt) {
			maxCnt = cnt;
		}
	}
	if (maxCnt > maxCount) {
		maxCount = maxCnt;
	}
}

int main() {
	int n;
	cin >> n;
	char** candy = (char**)calloc(n, sizeof(char*));

	for (int i = 0; i < n; i++) {
		candy[i] = (char*)calloc(n, sizeof(char));
		cin >> candy[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			swap(candy[i][j], candy[i][j + 1]);

			checkRowCandy(candy, n);
			checkColCandy(candy, n);

			swap(candy[i][j + 1], candy[i][j]);

			swap(candy[j][i], candy[j + 1][i]);

			checkRowCandy(candy, n);
			checkColCandy(candy, n);

			swap(candy[j + 1][i], candy[j][i]);
		}
	}

	cout << maxCount;

	return 0;
}