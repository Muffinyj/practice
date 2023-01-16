#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string number[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    for (int i = 0; i < 10; i++) {
        size_t n = s.find(number[i]);
        while (string::npos != n) {
            s.replace(n, number[i].size(), to_string(i));
            n = s.find(number[i]);
        }
    }

    answer = std::stoi(s);

    return answer;
}
