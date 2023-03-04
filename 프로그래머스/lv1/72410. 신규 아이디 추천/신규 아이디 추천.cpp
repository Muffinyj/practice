#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    int ptr = 0;
    int size = new_id.size();
    int cnt = 0;

    //step 1.

    for (int i = 0; i < size; i++) {
        if (isalpha(new_id[i])) {
            new_id[i] = tolower(new_id[i]);
        }
    }
    //step 2.

    for (int i = 0; i < size; i++) {
        if (new_id[ptr] != '-' && new_id[ptr] != '_' && new_id[ptr] != '.' && !isdigit(new_id[ptr]) && !isalpha(new_id[ptr])) {
            new_id.erase(ptr, 1);
            ptr--;
        }
        ptr++;
    }
    size = new_id.size();
    ptr = 1;
    //step 3.

    for (int i = 1; i < size; i++) {
        if (new_id[ptr - 1] == '.' && new_id[ptr] == '.') {
            new_id.erase(ptr, 1);
            ptr--;
        }
        ptr++;
    }
    size = new_id.size();
    ptr = 0;
    //step 4.
    if (new_id[ptr] == '.') {
        new_id.erase(ptr, 1);
    }
    //step 5.
    if (new_id.empty()) {
        new_id.append(1, 'a');
    }
    //step 6.
    if (new_id.size() > 15) {
        new_id.erase(15, new_id.size() - 15);
    }
    ptr = new_id.size() - 1;
    while (new_id[ptr] == '.' && ptr >= 0) {
        new_id.erase(ptr, 1);
        ptr--;
    }
    //step 7.
    size = new_id.size();
    if (size < 3) {
        while (new_id.size() < 3) {
            new_id.append(1, new_id[size - 1]);
        }
    }

    answer = new_id;

    return answer;
}