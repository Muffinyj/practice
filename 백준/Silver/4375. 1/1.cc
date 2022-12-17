#include <iostream>
#define MAX 100000

using namespace std;

int main() {
	int n;

	while (cin >> n) {
		int modNum = 1;
		int cnt = 1;

		while (modNum % n != 0) {
			modNum = (modNum % n) * 10 + 1;
			cnt++;
		}
		cout << cnt << '\n';
	}

	return 0;
}