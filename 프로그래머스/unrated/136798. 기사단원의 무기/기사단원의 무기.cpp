#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void getPrimeNum(int* primeNum, int num) {
    for (int i = 1; i <= num; i++) {
        primeNum[i]++;
        for (int j = i + i; j <= num; j = j + i) {
            primeNum[j]++;
        }
    }
}

int solution(int number, int limit, int power) {
    int answer = 0;
    int* primeNum = (int*)calloc(number + 1, sizeof(int));
    for(int i = 0;i <= number;i++){
        primeNum[i] = 0;
    }
    getPrimeNum(primeNum, number);
           
    for(int i = 1;i <= number;i++){
        if(primeNum[i] <= limit){
            answer += primeNum[i];
        }
        else{
            answer += power;
        }
    }
    
    
    return answer;
}