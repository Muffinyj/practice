#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;
    
    for(int i = 0;i < commands.size();i++){
        int start = commands[i][0];
        int end = commands[i][1];
        
        for(int j = start;j <= end;j++){
            tmp.push_back(array[j - 1]);
        }
        
        sort(tmp.begin(), tmp.end());
        
        answer.push_back(tmp[commands[i][2] - 1]);
        
        tmp.clear();
    }
    
    
    return answer;
}