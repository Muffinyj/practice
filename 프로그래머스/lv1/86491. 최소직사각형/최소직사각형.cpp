#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int wh[2] = { 0,0 };

    for (int i = 0; i < 2;i++) {
        for (int j = 0; j < sizes.size(); j++) {
            if (wh[i] < sizes[j][i]) {
                wh[i] = sizes[j][i];
            }
        }
    }

    int n(0), tmp(0);
    if (wh[1] > wh[0]) {
        n = 1;
    }

    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][n] < sizes[i][!n]) {
            int t = sizes[i][n];
            sizes[i][n] = sizes[i][!n];
            sizes[i][!n] = t;
        }
        if (tmp < sizes[i][!n]) {
            tmp = sizes[i][!n];
        }
    }

    answer = tmp * wh[n];

    return answer;
}