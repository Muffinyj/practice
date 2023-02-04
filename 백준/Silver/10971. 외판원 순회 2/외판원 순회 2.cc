#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

//int** city;
//int** m;
int city[11][11];
int m[1 << 11][11];

void setting(int n) {
    int** city = new int* [n];
    int** m = new int* [n];

    for (int i = 0; i < n; i++) {
        city[i] = new int[n];
        m[i] = new int[1 << n];
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
        }
    }

    return;
}

int TSP(int v, int c, int size) {
    //v -> 이미 방문한 도시
    //c -> 현재 도시
    v = v | (1 << c);

    if (v == (1 << size) - 1) {
        if (city[c][0] > 0) {
            return city[c][0];
        }
        return 1000000 * size + 1;
    }

    int& r = m[v][c];

    //이미 경로가 저장되어 있으면 그 값을 return
    if (r > 0) {
        return r;
    }
    //0 -> 길이 없음을 뜻함
    r = 1000000 * size + 1;
    for (int i = 0; i < size; i++) {
        //i는 도시의 개수만큼 도는데 i != c -> 현재 도시를 제외
        //v & (1 << i) == 0 -> 이미 방문한 도시면 넘김
        //city[c][i] > 0 -> 0이 아닌경우(지나갈 수 있을 경우)
        if (i != c && (v & (1 << i)) == 0 && city[c][i] > 0) {
            int tmp = TSP(v, i, size) + city[c][i];
            if (r > tmp) {
                r = tmp;
            }
        }
    }

    return r;
}

int main() {
    int n;
    cin >> n;
    //setting(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
        }
    }

    int r = TSP(0, 0, n);
    if (r == (1000000 * n) + 1) {
        cout << -1;
    }
    else {
        cout << r;
    }

    return 0;
}