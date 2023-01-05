#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> seq = { 1,2,3,1 };
    vector<int> hamburger;

    for (int i = 0; i <= ingredient.size(); i++) {
        int tmp = 0;
        if (!hamburger.empty()) {
            if (hamburger.size() >= seq.size()) {
                for (int j = 0; j < seq.size(); j++) {
                    if (seq[j] == hamburger[hamburger.size() - (seq.size() - j)]) {
                        tmp++;
                    }
                    else {
                        break;
                    }
                }
                if (tmp == seq.size()) {
                    for (int i = 0; i < seq.size(); i++) {
                        hamburger.pop_back();
                    }
                    answer++;
                }
                if (i < ingredient.size()) {
                    if (hamburger.empty() && ingredient[i] == 1) {
                        hamburger.push_back(ingredient[i]);
                    }
                    else if (!hamburger.empty()){
                        hamburger.push_back(ingredient[i]);
                    }
                }
            }
            else if(i < ingredient.size()) {
                hamburger.push_back(ingredient[i]);
            }
        }
        else if (hamburger.empty() && ingredient[i] == 1 && i < ingredient.size()) {
            hamburger.push_back(ingredient[i]);
        }
    }

    return answer;
}