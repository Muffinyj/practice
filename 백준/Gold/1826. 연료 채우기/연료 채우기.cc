#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, l, p;
pair<int, int> a[10001];
priority_queue<int> pq;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	cin >> l >> p;

	sort(a, a + n);

	int cnt = 0;
	int i = 0;

	while (p < l) {
		while (i < n && p >= a[i].first) {
			pq.push(a[i].second);
			i++;
		}

		if (pq.empty()) {
			cout << -1;
			return 0;
		}

		p = p + pq.top();
		pq.pop();
		cnt++;
	}

	cout << cnt;
	return 0;
}