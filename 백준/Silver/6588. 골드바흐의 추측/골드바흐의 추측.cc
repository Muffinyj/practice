#include <iostream>
#include <vector>
#include <cmath>
#define MAX 1000000

using namespace std;

bool prime[MAX + 1];

void getPrime() {
	for (int i = 2; i <= sqrt(MAX); i++) {
		for (int j = i * i; j <= MAX; j+=i) {
			if (!prime[j]) {
				prime[j] = true;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	getPrime();
	int num;

	while (1) {
		cin >> num;
		if (num == 0) {
			break;
		}
		for (int i = 2; i <= MAX / 2; i++) {
			if (!prime[i] && !prime[num - i]) {
				cout << num << " = " << i << " + " << num - i << "\n";
				break;
			}
		}
	}

	return 0;
}