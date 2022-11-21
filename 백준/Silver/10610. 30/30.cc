#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

char s[MAX] = { 0, };
vector<int> v;

int main() {
	int flag = 0;
	int sum = 0, tmp;
	cin.getline(s, MAX, '\n');

	for (int i = 0; i < MAX; i++) {
		if (s[i] == 0) break;
		if (s[i] == '0' && !flag) {
			flag = 1;
		}
		tmp = s[i] - '0';
		sum += tmp;
		v.push_back(tmp);
	}

	if (flag && sum % 3 == 0) {
		sort(v.begin(), v.end(), greater<int>());
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
	}
	else {
		cout << -1;
	}

	return 0;
}