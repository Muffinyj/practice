#include <iostream>
#include <cmath>
#define MAX 1000000

using namespace std;

long long int sumFac[MAX + 1];

void getSumFactor() {
	int sum = 0;
	for (int i = 1; i <= MAX; i++) {
		for (int j = 1; i*j <= MAX; j++) {
			sumFac[i*j] += i;
		}
		sumFac[i] += sumFac[i - 1];

	}

	return;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int num, n;
	cin >> num;

	getSumFactor();

	for (int i = 0; i < num; i++) {
		cin >> n;
		cout << sumFac[n] << '\n';
	}

	return 0;
}