#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long tmp = n;
    int a[10] = { 0, };
    int cnt = 0;

    while (tmp != 0) {
        tmp /= 10;
        cnt++;
    }

    tmp = n;
    for (int i = 0; i < cnt; i++) {
        long long num = pow(10, cnt - i - 1);
        a[i] = tmp / num;
        tmp = tmp % num;
    }
    sort(a, a + 10, greater<int>());

    for (int i = 0; i < cnt; i++) {
        answer += a[i] * (long long)pow(10, cnt - i - 1);
    }

    return answer;
}