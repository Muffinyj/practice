#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    map<int, string> poketmon;
    map<string, int> poketmon1;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        poketmon.insert(make_pair(i, s));
        poketmon1.insert(make_pair(s, i));
    }

    for (int i = 0; i < m; i++) {
        string p;
        bool c = false;
        cin >> p;

        if (isdigit(p[0])) {
            c = true;
        }

        int num = 0;
        if (c) {
            num = stoi(p);
        }

        if (num) {
            cout << poketmon[num] << "\n";
        }
        else {
            cout << poketmon1[p] << "\n";
        }

    }

    return 0;
}