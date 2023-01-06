#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int date[3] = { std::stoi(today.substr(0,4)), std::stoi(today.substr(5,2)), std::stoi(today.substr(8,2)) };
    int j = 0;

    for (int i = 0; i < terms.size(); i++) {
        int t = std::stoi(terms[i].substr(2, 3));
        for (j = 0; j < privacies.size(); j++) {
            std::string::size_type n = privacies[j].find(terms[i][0]);
            if (n != std::string::npos) {
                int pdate[3] = { std::stoi(privacies[j].substr(0, 4)),std::stoi(privacies[j].substr(5, 2)) ,std::stoi(privacies[j].substr(8,2)) };
                
                if ((pdate[1] + t) % 12 != 0) {
                    pdate[0] += (pdate[1] + t) / 12;
                }
                else {
                    pdate[0] += (pdate[1] + t) / 12 - 1;
                }
                pdate[1] = (pdate[1] + t) % 12;

                if (pdate[1] == 0) {
                    pdate[1] = 12;
                }

                for (int k = 0; k < 3; k++) {
                    if (pdate[k] > date[k]) {
                        break;
                    }
                    else {
                        if (pdate[k] < date[k] || (k == 2 && pdate[k] <= date[k])) {
                            answer.push_back(j + 1);
                            break;
                        }
                        else {
                            continue;
                        }
                    }
                }
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}