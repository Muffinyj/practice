#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    int n[10] = {0,};
    
    for(int i = 0;i < numbers.size();i++){
        n[numbers[i]]++;
    }
    for(int i = 0;i < 10;i++){
        if(n[i] == 0){
            answer += i;
        }
    }
    
    return answer;
}