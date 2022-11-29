#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 51

using namespace std;

int n;
vector<int> f[MAX];
queue<int> q;
queue<int> tmp;
bool check[MAX] = { false, };
int frd[MAX];

void bfs(int d) {
	q.push(d);

	int cnt = 0;
	while (1) {
		int x = q.front();
		check[x] = true;
		q.pop();

		for (int i = 0; i < f[x].size(); i++) {
			if (!check[f[x][i]]) {
				check[f[x][i]] = true;
				tmp.push(f[x][i]);
			}
		}
		if (q.empty()&&!tmp.empty()) {
			q = tmp;
			tmp = queue<int>();
			cnt++;
		}
		else if (q.empty() && tmp.empty()) {
			break;
		}
	}
	frd[d] = cnt;
	q = queue<int>();
	return;
}

int main() {
	cin >> n;
	int u(0), v(0);

	while (1) {
		cin >> u >> v;
		if (u == -1 && v == -1) {
			break;
		}
		f[u].push_back(v);
		f[v].push_back(u);
	}

	int min = n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		bfs(i);
		memset(check, false, sizeof(bool) * MAX);
		if (min > frd[i]) {
			min = frd[i];
			cnt = 1;
		}
		else if (min == frd[i]) {
			cnt++;
		}
	}

	cout << min << " " << cnt << "\n";
	for (int i = 1; i <= n; i++) {
		if (min == frd[i]) {
			cout << i << " ";
		}
	}

	return 0;
}