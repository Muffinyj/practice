#include <iostream>
#include <algorithm>

using namespace std;

//x값을 고정으로 생각하고, x를 M만큼 증가시킨 값을 N으로 나머지 연산을 했을때
//N번 이후로는 같은 나머지 값이 나올 것으로 예상.
//그렇다면, (x + n * M)%N 에서 n이 N번까지 도달했을때 만족하지 않으면 -1 그렇지 않으면 M값을 출력하면 된다.

int CaIn(int M, int N, int x, int y) {
	for (int i = 0; i < N; i++) {
		int tmp = (x + i * M) % N;
		if (tmp == y || tmp + N == y) {
			return x + i * M;
		}
	}
	return -1;
}

int main() {
	int n;
	int M, N, x, y;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> M >> N >> x >> y;

		int res = CaIn(M, N, x, y);
		cout << res << "\n";
	}


	return 0;
}