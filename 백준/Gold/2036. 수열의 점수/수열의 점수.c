#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int num[100001];

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
	int n = 100000;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	qsort(num, n, sizeof(int), compare);
	/*
	for (int i = 0; i < n; i++) {
		num[i] = 1000000;
	}
	*/

	long long int sum = 0;

	int i = 0;
	int j = n - 1;

	while (num[i] > 0) {
		if (i < n - 1) {
			if (num[i + 1] > 1) {
				sum = sum + (long long int)num[i] * (long long int)num[i + 1];
				i += 2;
			}
			else {
				sum = sum + num[i];
				i++;
			}
		}
		else {
			sum = sum + num[i];
			i++;
		}
	}
	if (i != n) {
		i--;
		while (num[j] <= 0) {
			if (i + 1 < j) {
				if (num[j - 1] <= 0) {
					sum = sum + (long long int)num[j] * (long long int)num[j - 1];
					j -= 2;
				}
				else {
					sum = sum + num[j];
					j--;
				}
			}
			else {
				sum = sum + num[j];
				j--;
			}
		}
	}

	printf("%lld", sum);

	return 0;
}