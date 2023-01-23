#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i = 0;i < s.size();i++){
        if(isalpha(s[i])){
            for(int j = 0;j < n;j++){
                if(s[i] ==  'z' || s[i] == 'Z'){
                    s[i] = s[i] - ('z' - 'a');
                }
                else{
                    s[i] = s[i] + 1;
                }
            }
        }
    }
    
    answer = s;
    
    return answer;
}