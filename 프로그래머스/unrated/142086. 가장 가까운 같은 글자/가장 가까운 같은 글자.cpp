#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    for (int i = 0; i < s.size(); i++) {
        int location = 1;
        bool isExist = false;
        for (int j = i - 1; j >= 0; j--) {
            if (s[j] == s[i]) {
                isExist = true;
                break;
            }
            location++;
        }
        if (isExist) {
            answer.push_back(location);
        }
        else {
            answer.push_back(-1);
        }
    }
    return answer;
}