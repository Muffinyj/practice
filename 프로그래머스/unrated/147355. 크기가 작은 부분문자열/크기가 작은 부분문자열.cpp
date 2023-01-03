#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;

    for (int j = 0; j + p.size() <= t.size(); j++) {
        bool flag = true;
        for (int i = 0; i < p.size(); i++) {
            if (t[j + i] > p[i]) {
                flag = !flag;
                break;
            }
            else if (t[j + i] < p[i]) {
                break;
            }
        }
        if (flag) {
            answer++;
        }
    }

    return answer;
}