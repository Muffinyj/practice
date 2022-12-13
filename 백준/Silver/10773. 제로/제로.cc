#include <iostream>

int stack[100000];
int top = -1;

void push(int a){
    top += 1;
    stack[top] = a;
}

void pop(){
    top -= 1;
}

int main(){
    int n, a;
    std::cin >> n;
    for(int i = 0;i < n;i++){
        std::cin >> a;
        if(a == 0){
            pop();
        }
        else
            push(a);
    }
    int temp = 0;
    if(top == -1){
        std::cout << "0";
    }
    else{
        for(int i = 0;i <= top;i++){
            temp += stack[i];
        }
        std::cout << temp;
    }
    
    return 0;
}