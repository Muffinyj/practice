#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
pair<ll, ll> post[100001];

int main() {
	int n;
	long long standard = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> post[i].first >> post[i].second;
		standard += post[i].second;
	}

	sort(post + 1, post + 1 + n);

	long long cur = 0;
	for (int j = 1; j <= n; j++) {
		cur += post[j].second;
		if (cur >= (standard+1)/2) {
			cout << post[j].first;
			return 0;
		}
	}

	return 0;
}