#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<char> str;

    for (int i = 0; i < s.size(); i++) {
        str.push_back(s[i]);
    }

    sort(str.begin(), str.end(), greater<int>());
    
    for (int i = 0; i < str.size(); i++) {
        answer.push_back(str[i]);
    }

    return answer;
}