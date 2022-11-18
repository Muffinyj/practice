#include <iostream>
#include <stack>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::stack<int> nge;
	std::vector<int> num(n);
	std::vector<int> num1(n);

	nge.push(0); //top == 0, nge[top] = 0

	for (int i = 0; i < n; i++) {
		std::cin >> num[i];
	}

	for (int i = 1; i < n; i++) {
		if (nge.empty()) nge.push(i);
		while (!nge.empty() && num[nge.top()] < num[i]) {
			num1[nge.top()] = num[i];
			nge.pop();
		}
		nge.push(i);
	}

	while (!nge.empty()) {
		num1[nge.top()] = -1;
		nge.pop();
	}

	for (int i = 0; i < n; i++) {
		std::cout << num1[i] << " ";
	}

}