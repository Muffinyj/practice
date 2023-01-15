#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, vector<string>> res;
    map<string, int> reportNum;

    for (int i = 0; i < id_list.size(); i++) {
        reportNum[id_list[i]] = 0;
        answer.push_back(0);
    }

    for (int i = 0; i < report.size(); i++) {
        std::string::size_type n = report[i].find(" ");
        bool check = false;
        string s[2] = { report[i].substr(0, n), report[i].substr(n + 1) };
        for (int i = 0; i < res[s[1]].size(); i++) {
            if (s[0] == res[s[1]][i]) {
                check = true;
                break;
            }
        }
        if (!check) {
            res[s[1]].push_back(s[0]);
            reportNum[s[1]]++;
        }
    }

    for (int i = 0; i < id_list.size(); i++) {
        if (reportNum[id_list[i]] >= k) {
            for (int j = 0; j < res[id_list[i]].size(); j++) {
                for (int l = 0; l < id_list.size(); l++) {
                    if (id_list[l] == res[id_list[i]][j]) {
                        answer[l]++;
                        break;
                    }
                }
            }
        }
    }

    return answer;
}