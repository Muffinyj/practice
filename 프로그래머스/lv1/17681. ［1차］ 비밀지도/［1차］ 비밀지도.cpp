#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> iAnswer;
    
    for(int i = 0;i < n;i++){
        iAnswer.push_back(arr1[i] | arr2[i]);
    }
    
    for(int i = 0;i < n;i++){
        string tmp = "";
        string res = "";
        int a = iAnswer[i];
        for(int j = 0;j < n;j++){
            if(a%2 == 1){
                tmp += "#";
            }
            else{
                tmp += " ";
            }
            a = a / 2;
        }
        
        
        for(int i = n - 1;i >= 0;i--){
            res += tmp[i];
        }
        
        answer.push_back(res);
    }
    
    return answer;
}