#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int* p = new int[n];

	for (int i = 0; i < n; i++) {
		std::cin >> p[i];
	}
	int i = 0;
	int cnt = 0;
	int flag = 0;
	while (i < n) {
		if (p[i] == 1) {
			i++;
			continue;
		}
		for (int j = 2; j < p[i]; j++) {
			if (p[i] % j == 0) {
				flag++;
				break;
			}
		}
		if (flag == 0) {
			i++;
			cnt++;
		}
		else {
			flag = 0;
			i++;
		}
	}
	std::cout << cnt;

}