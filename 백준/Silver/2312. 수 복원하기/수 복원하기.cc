#include <iostream>
#include <vector>
#include <cstring>
#define MAX 100000

using namespace std;

vector<int> prime;
bool check[MAX + 1] = { false, };
int res[MAX + 1] = { 0, };

void take_prime() {
	for (int i = 2; i < MAX; i++) {
		if (!check[i]) {
			prime.push_back(i);
			int tmp = 1;
			for (int j = i; tmp*j < MAX; tmp++) {
				if (!check[tmp*j]) {
					check[tmp * j] = true;
				}
			}
		}
	}
}

int main() {
	int n;
	cin >> n;

	take_prime();

	for (int i = 0; i < n; i++) {
		memset(res, 0, (MAX+1) * sizeof(int));
		int data;
		cin >> data;

		int tmp = 0;
		while (data != 1) {
			if (data % prime[tmp] == 0) {
				res[prime[tmp]]++;
				data /= prime[tmp];
			}
			else {
				tmp++;
			}
		}

		for (int j = 0; j < MAX + 1; j++) {
			if (res[j]) {
				cout << j << " " << res[j] << "\n";
			}
		}
	}

	return 0;
}