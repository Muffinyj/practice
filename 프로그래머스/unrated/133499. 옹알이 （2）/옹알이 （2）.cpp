#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> word = { "aya", "ye", "woo", "ma" };

    for (int i = 0; i < babbling.size(); i++) {
        for (int j = 0; j < word.size(); j++) {
            std::string::size_type n = babbling[i].find(word[j]);
            while (n != std::string::npos) {
                if (n == std::string::npos) {
                    continue;
                }
                else {
                    babbling[i].replace(n, word[j].size(), to_string(j));
                }
                n = babbling[i].find(word[j]);
            }
        }
    }

    answer = babbling.size();
    for (int i = 0; i < babbling.size(); i++) {
        if (isdigit(babbling[i][0])) {
            for (int j = 0; j < babbling[i].size() - 1; j++) {
                if (isdigit(babbling[i][j + 1]) && babbling[i][j] != babbling[i][j + 1]) {
                    continue;
                }
                else {
                    answer--;
                    break;
                }
            }
        }
        else {
            answer--;
        }
    }

    return answer;
}
