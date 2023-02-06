#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int city[17][17];
int dp[17][1 << 17];

int TSP(int visited, int curCity, int n) {
    visited = visited | (1 << curCity);

    if (visited == (1 << n) - 1) {
        if (city[curCity][0] > 0) {
            return city[curCity][0];
        }
        return 1000000 * n + 1;
    }

    int& r = dp[curCity][visited];

    if (r > 0) {
        return r;
    }
    else {
        r = 1000000 * n + 1;
        for (int i = 0; i < n; i++) {
            if (i != curCity && (visited & (1 << i)) == 0 && city[curCity][i] > 0) {
                int tmp = TSP(visited, i, n) + city[curCity][i];
                if (r > tmp) {
                    r = tmp;
                }
            }
        }
    }

    return r;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
        }
    }

    int answer = TSP(0, 0, n);

    if (answer == 1000000 * n + 1) {
        cout << -1;
    }
    else {
        cout << answer;
    }

    return 0;
}