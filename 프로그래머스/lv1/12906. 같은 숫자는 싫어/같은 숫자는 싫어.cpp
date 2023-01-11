#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int ptr = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (i != 0) {
            if (arr[i] != answer[ptr - 1]) {
                answer.push_back(arr[i]);
                ptr++;
            }
        }
        else {
            answer.push_back(arr[i]);
            ptr++;
        }
    }

    return answer;
}