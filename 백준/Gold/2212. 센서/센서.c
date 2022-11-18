#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int vehicle[10000] = { 0, };
int diff[10000] = { 0, };

int compare(const int* a, const int* b) {
	int n1 = *(int*)a;
	int n2 = *(int*)b;
	if (n1 > n2) {
		return 1;
	}
	if (n1 < n2) {
		return -1;
	}
	return 0;
}

int main() {
	int n, k;
	scanf("%d\n%d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &vehicle[i]);
	}

	qsort(vehicle, n, sizeof(int), compare);
	
	for (int i = 0; i < n - 1; i++) {
		diff[i] = vehicle[i + 1] - vehicle[i];
	}

	qsort(diff, n - 1, sizeof(int), compare);

	int sum = 0;
	for (int i = 0; i < n - k; i++) {
		sum = sum + diff[i];
	}

	printf("%d", sum);

	return 0;
}