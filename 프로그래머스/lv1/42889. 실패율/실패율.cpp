#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int compare(const pair<double, int>& a, const pair<double, int>& b) {
    if (a.first > b.first) {
        return 1;
    }
    else if (a.first == b.first) {
        if (a.second > b.second) {
            return 0;
        }
        else {
            return 1;
        }
    }
    return 0;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double,int>> fail;

    for (int i = 1; i <= N; i++) {
        int num = 0;
        int cnt = 0;
        for (int j = 0; j < stages.size(); j++) {
            if (stages[j] >= i) {
                num++;
                if (stages[j] > i) {
                    cnt++;
                }
            }
        }
        cnt = num - cnt;
        if (cnt == 0) {
            fail.push_back(make_pair(0, i));
        }
        else {
            fail.push_back(make_pair((double)cnt / (double)num,i));
        }
    }

    sort(fail.begin(), fail.end(), compare);
    
    for(int i = 0;i < N;i++){
        answer.push_back(fail[i].second);
    }
    
    return answer;
}