#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.size();) {
        char c = s[i];
        int cnt = 0;
        int cnt2 = 0;

        do {
            if (c == s[i]) {
                cnt++;
            }
            else {
                cnt2++;
            }
            i++;
            if (i == s.size()) {
                break;
            }
        } while (cnt != cnt2);
        if (i <= s.size()) {
            answer++;
        }

    }

    return answer;
}