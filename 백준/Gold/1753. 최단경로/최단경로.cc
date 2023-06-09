#include <iostream>
#include <queue>

const int INF = 2147483647;
using namespace std;
vector<pair<int, int>> q[20001];
int d[20001];

void Dijkstra(int s) {
	d[s] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, s));

	while (!pq.empty()) {
		int cur = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();

		if (d[cur] < dist) continue;
		for (int i = 0; i < q[cur].size(); i++) {
			int next = q[cur][i].second;
			int nextDist = dist + q[cur][i].first;

			if (nextDist < d[next]) {
				d[next] = nextDist;
				pq.push(make_pair(-nextDist, next));
			}
		}
	}
}

int main() {
	int n, v, start;
	cin >> n >> v;
	cin >> start;

	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}

	for (int i = 0; i < v; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		q[u].push_back(make_pair(w, v));
	}

	Dijkstra(start);

	for (int i = 1; i <= n; i++) {
		if (d[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << d[i] << "\n";
		}
	}

	return 0;
}