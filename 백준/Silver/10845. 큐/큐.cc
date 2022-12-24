#include <iostream>
#define MAX 10001

//queue 라이브러리 안쓰고 구현해보기

using namespace std;

int q[MAX];
int f(0), r(0);

bool empty();

void push(int x) {
    q[r] = x;
    r = ++r % MAX;

    return;
}

void pop() {
    if (!empty()) {
        cout << q[f] << "\n";
        f = ++f % MAX;
    }
    else {
        cout << -1 << "\n";
    }

    return;
}

void size() {
    if (f <= r) {
        cout << r - f << "\n";
    }
    else {
        cout << (r + MAX) - f << "\n";
    }
    return;
}

bool empty() {
    if (r == f) {
        return true;
    }
    else {
        return false;
    }
}

void front() {
    if (!empty()) {
        cout << q[f] << "\n";
    }
    else {
        cout << -1 << "\n";
    }

    return;
}

void back() {
    if (!empty()) {
        cout << q[r - 1] << "\n";
    }
    else {
        cout << -1 << "\n";
    }
}

int main() {
    int n, x;
    string cmd;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> x;
            push(x);
        }
        else if (cmd == "pop") {
            pop();
        }
        else if (cmd == "size") {
            size();
        }
        else if (cmd == "empty") {
            cout << empty() << "\n";
        }
        else if (cmd == "front") {
            front();
        }
        else if (cmd == "back") {
            back();
        }
    }

    return 0;
}