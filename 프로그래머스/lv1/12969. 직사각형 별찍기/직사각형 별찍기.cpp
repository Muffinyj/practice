#include <iostream>

using namespace std;

void star(int a, int b){
    for(int i = 0;i < b;i++){
        for(int j = 0;j < a;j++){
            cout << "*";
        }
        cout << "\n";
    }
}

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    star(a,b);
    return 0;
}