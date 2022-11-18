#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;

    stack<pair<unsigned int, unsigned int>> stk;

    int* height = (int*)calloc(n, sizeof(unsigned int));
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int top = 0, bottom = 0, same = 1;
    long long int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            stk.push(make_pair(height[i], same));
        }
        else {
            same = 1;
            while (!stk.empty() && stk.top().first < height[i]) {
                cnt+=stk.top().second;
                stk.pop();
            }
            if (!stk.empty()) {
                if (stk.top().first > height[i]) {
                    cnt++;
                }
                else {
                    cnt += stk.top().second;
                    same = stk.top().second + 1;
                    if (stk.size() > 1) cnt++;
                    stk.pop();
                }
            }
            stk.push(make_pair(height[i], same));
        }
    }

    cout << cnt;

    return 0;
}