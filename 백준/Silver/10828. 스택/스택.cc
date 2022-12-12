#include <iostream>
#include <cstring>
#define Size 10000

int stack[Size];
int top = -1;

void push(int a) {
    top += 1;
    stack[top] = a;
}
void pop() {
    if (top == -1) {
        std::cout << "-1" << std::endl;
        return;
    }
    std::cout << stack[top] << std::endl;
    top -= 1;
}
void size() {
    std::cout << top + 1 << std::endl;
}
void empty() {
    if (top == -1)
        std::cout << "1" << std::endl;
    else
        std::cout << "0" << std::endl;
}
void _top() {
    if (top == -1)
        std::cout << "-1" << std::endl;
    else
        std::cout << stack[top] << std::endl;
}


int main() {
    char a[10];
    int n, q;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        if (!strcmp(a, "push")) {
            std::cin >> q;
            push(q);
        }
        else if (!strcmp(a, "pop")) {
            pop();
        }
        else if (!strcmp(a, "size")) {
            size();
        }
        else if (!strcmp(a, "empty")) {
            empty();
        }
        else if (!strcmp(a, "top")) {
            _top();
        }
    }
}