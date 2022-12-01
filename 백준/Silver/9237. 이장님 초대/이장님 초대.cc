#include <iostream>
#include <algorithm>

int compare(int a, int b) {
	return a > b;
}

int main() {
	int n;
	std::cin >> n;

	int* p = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> p[i];
	}
	std::sort(p, p + n, compare);

	int maxDay = 0;
	int term = 2;
	for (int i = 0; i < n; i++) {
		if (maxDay < term + p[i]) {
			maxDay = term + p[i];
		}
		term++;
	}
	std::cout << maxDay;
}