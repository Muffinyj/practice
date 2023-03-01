#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    //0101
    string days[7] = { "FRI","SAT","SUN","MON","TUE","WED","THU" };
    string answer = "FRI";
    int cnt = 0;

    for (int i = 1; i < a; i++) {
        if (i % 2 == 1) {
            if(i <= 7){
                cnt = (cnt + 3) % 7;
            }
            else{
                cnt = (cnt + 2) % 7;
            }
        }
        else if (i != 2) {
            if(i <= 7){
                cnt = (cnt + 2) % 7;
            }
            else{
                cnt = (cnt + 3) % 7;
            }
        }
        else {
            cnt++;
        }
    }

    cnt = (cnt + b - 1) % 7;

    answer = days[cnt];
    
    return answer;
}