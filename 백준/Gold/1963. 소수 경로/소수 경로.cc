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
			//각 자리별로 0을 만들어준다.
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

			//각 자리마다 숫자를 바꿔 소수인지 확인하고 push
			for (int j = 0; j < 10; j++) {
				int tmp2 = tmp + j * (int)pow(10, i);
				//첫째자리가 0일 수도 있고 10을 넘어갈 수 있기 때문에 제한을 먼저 둔다.
				if (tmp2 >= 1000 && tmp2 <= 9999) {
					//visit을 사용하지 않으면 시간초과가 발생한다!
					//이미 방문한 수를 빼줘야 원활하게 통과
					if (!visit[tmp2]) {
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

	//미리 prime data를 만들어두어 매번 prime을 구하지 않도록 한다.
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
		//visit을 초기화해주지 않으면 다음 test case때 영향을 준다.
		memset(visit, false, sizeof(bool) * MAX);
	}

	return 0;
}
