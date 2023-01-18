#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int harshad = 0;
    int cnt = 0;
    int tmp = x;
    
    while(tmp != 0){
        harshad += tmp%10;
        tmp /= 10;
        cnt++;
    }
    
    if(x%harshad != 0){
        answer = false;
    }
    
    return answer;
}