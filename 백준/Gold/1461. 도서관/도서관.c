#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int location[10001];

int compare(const int* a, const int* b) {
	int n1 = (int*)*a;
	int n2 = (int*)*b;

	if (n1 < n2) {
		return 1;
	}
	if (n1 > n2) {
		return -1;
	}
	return 0;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &location[i]);
	}

	qsort(location, n + 1, sizeof(int), compare);

	int sum = 0;
	int i = 0;
	int j = n;

	if (abs(location[0]) > abs(location[n])) {
		sum = abs(location[0]);
		i = m;
	}
	else {
		sum = abs(location[n]);
		j = j - m;
	}

	while (location[i] > 0) {
		sum = sum + 2 * abs(location[i]);
		i += m;
	}

	while (location[j] < 0) {
		sum = sum + 2 * abs(location[j]);
		j -= m;
	}

	printf("%d", sum);

	return 0;
}