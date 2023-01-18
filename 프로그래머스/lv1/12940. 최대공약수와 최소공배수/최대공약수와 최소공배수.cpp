#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int gcd, lcm;
    
    if(n > m){
        int tmp = n;
        n = m;
        m = tmp;
    }
    
    int x(m), y(n), t;
    while (1) {
        t = x % y;
        if (t == 0) {
            gcd = y;
            answer.push_back(gcd);
            break;
        }
        else {
            t = x;
            x = y;
            y = t % y;
        }
    }
    
    lcm = n*m/gcd;
    answer.push_back(lcm);
    
    return answer;
}