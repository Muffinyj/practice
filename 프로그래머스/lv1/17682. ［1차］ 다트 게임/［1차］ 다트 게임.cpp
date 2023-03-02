#include <string>
#include <cmath>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int i = 0, num = 0;
    vector<int> res;

    while (i < dartResult.size()) {
        int j = i;
        int l = i;
        bool check = false;
        int sum = 0;
        while (isdigit(dartResult[j])) {
            j++;
            l++;
        }
        for (int k = i; k < j; k++) {
            sum += (dartResult[k] - '0') * pow(10, j - i - 1);
        }
        if (sum == 10) {
            check = true;
        }

        while (!isdigit(dartResult[j]) && j < dartResult.size()) {
            j++;
        }

        if (dartResult[l] == 'S') {
            sum = pow(sum, 1);
        }
        else if (dartResult[l] == 'D') {
            sum = pow(sum, 2);
        }
        else {
            sum = pow(sum, 3);
        }

        if (j - i == 3) {
            if (dartResult[i + 2] == '*') {
                if (i != 2) {
                    sum = sum * 2;
                    if (num != 0) {
                        res[num - 1] = res[num - 1] * 2;
                    }
                }
                else {
                    sum = sum * 2;
                    res[num - 1] = res[num - 1] * 2;
                }
                i += 3;
            }
            else if (dartResult[i + 2] == '#') {
                sum = (-1) * sum;
                i += 3;
            }
            else {
                if (check) {
                    i += 3;
                }
                else {
                    i += 2;
                }
            }
        }
        else {
            if (check) {
                i += 3;
            }
            else {
                i += 2;
            }
        }
        res.push_back(sum);
        num++;
    }

    for (int i = 0; i < res.size(); i++) {
        answer += res[i];
    }

    return answer;
}