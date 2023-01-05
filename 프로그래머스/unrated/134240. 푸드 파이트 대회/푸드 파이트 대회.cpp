#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for (int i = 1; i < food.size(); i++) {
        for (int j = 0; j < food[i]/2; j++) {
            answer.append(to_string(i));
        }
    }
    answer.append("0");
    for (int i = food.size() - 1; i >= 0; i--) {
        for (int j = 0; j < food[i] / 2; j++) {
            answer.append(to_string(i));
        }
    }
    return answer;
}