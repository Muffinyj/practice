#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, k;
queue<int> q;
vector<int> s;
int _time[2][100001];
int cur = 0;
int dx[3] = { -1,1,2 };

int bfs(int start) {
	if (start == k) {
		return 0;
	}
	q.push(start);
	_time[0][start] = 0;
	_time[1][start] = -1;

	while (1) {
		int cx = q.front();
		q.pop();

		if (cx == k) {
			cur = cx;
			return _time[0][cx];
		}

		int nx;

		for (int i = 0; i < 3; i++) {
			if (i == 2) {
				nx = cx * dx[i];
				if (nx <= 100000 && nx >= 0) {
					if (_time[0][nx] == -1) {
						q.push(nx);
						_time[0][nx] = _time[0][cx] + 1;
						_time[1][nx] = cx;
					}
				}
			}
			else {
				nx = cx + dx[i];
				if (nx <= 100000 && nx >= 0) {
					if (_time[0][nx] == -1 || _time[0][nx] > _time[0][cx] + 1) {
						q.push(nx);
						_time[0][nx] = _time[0][cx] + 1;
						_time[1][nx] = cx;
					}
				}
			}
		}
	}
}

void search(int data, int t) {
	s.push_back(data);
	int prev = _time[1][data];
	for (int i = 0; i < t; i++) {
		s.push_back(prev);
		prev = _time[1][prev];
	}
}

int main() {
	cin >> n >> k;

	memset(_time, -1, sizeof(int) * 100001);
	int t = bfs(n);
	cout << t << "\n";

	if (t) {
		search(cur, t);

		for (int i = t; i >= 0; i--) {
			cout << s[i] << " ";
		}
	}
	else {
		cout << n;
	}

	return 0;
}