#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int w[101];
int v[101];
int dp[101][100001];

int knapsack(int K, int w[], int v[], int n) {
	for (int i = 0; i < K; i++) {
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 0;
		for (int j = 1; j <= K; j++) {
			if (w[i] <= j) {
				if (v[i] + dp[i - 1][j - w[i]] > dp[i - 1][j]) {
					dp[i][j] = v[i] + dp[i - 1][j - w[i]];
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	//가장 큰 거 return
	return dp[n][K];
}

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &w[i], &v[i]);
	}

	int a = knapsack(K, w, v, N);
	printf("%d", a);

	return 0;
}