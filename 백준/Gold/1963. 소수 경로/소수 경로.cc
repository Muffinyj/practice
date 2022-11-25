#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
#define MAX 9999

using namespace std;

int check[MAX + 1] = { false, };
bool visit[MAX + 1] = { false, };
queue<int> q;
queue<int> temp;

void take_prime() {
	for (int i = 2; i < MAX; i++) {
		if (!check[i]) {
			check[i] = 1;
			int tmp = 1;
			for (int j = i; tmp*j < MAX; tmp++) {
				if (!check[tmp*j]) {
					check[tmp * j] = -1;
				}
			}
		}
	}
}

int bfs(int p1, int p2) {
	q.push(p1);
	visit[p1] = true;
	int cnt = 0;

	while (!q.empty()) {
		int p = q.front();
		visit[p] = true;

		q.pop();
		if (p == p2) {
			q = queue<int>();
			temp = queue<int>();
			return cnt;
		}

		for (int i = 0; i < 4; i++) {
			int tmp = p;
			if (i != 3) {
				int tmp1 = p % (int)pow(10, i + 1);
				for (int j = 0; j < i; j++) {
					tmp1 = tmp1 - tmp1 % (int)pow(10, j + 1);
				}
				tmp -= tmp1;
			}
			else {
				tmp = (int)pow(10, i) + tmp % (int)pow(10, i);
			}

			for (int j = 0; j < 10; j++) {
				int tmp2 = tmp + j * (int)pow(10, i);
				if (tmp2 >= 1000 && tmp2 <= 9999) {
					if (tmp2 != p && !visit[tmp2]) {
						if (check[tmp2] == 1) {
							temp.push(tmp2);
						}
					}
				}
			}
		}

		if (q.empty() && !temp.empty()) {
			q = temp;
			temp = queue<int>();
			cnt++;
		}
	}

	return -1;
}

int main() {
	int n;
	cin >> n;

	take_prime();

	for (int i = 0; i < n; i++) {
		int p1, p2;
		cin >> p1 >> p2;

		int result = bfs(p1, p2);

		if (result != -1) {
			cout << result << "\n";
		}
		else {
			cout << "Impossible\n";
		}
		memset(visit, false, sizeof(bool) * MAX);
	}

	return 0;
}