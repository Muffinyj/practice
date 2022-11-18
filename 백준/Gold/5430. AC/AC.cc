#include <iostream>
#include <string>
#define SWAP(x,y,t) ((t)=(x), (x)=(y),(y)=(t))

int main() {
	int n; //총 횟수
	int num; //배열 개수
	char dummy; //[,] 제거
	std::cin >> n;
	
	std::string a; //RD 문자 저장

	for (int i = 0; i < n; i++) {
		std::cin >> a;
		std::cin >> num;
		int* p = new int[num];
		int errflag = 0;
		int flag = 0;
		//배열입력
		if (num == 0) {
			std::cin >> dummy;
			std::cin >> dummy;
		}
		else {
			for (int i = 0; i < num; i++) {
				std::cin >> dummy; //[ ,
				std::cin >> p[i];
			}
			std::cin >> dummy; //]
		}

		int begin = 0;
		int end = num - 1;
		int tmp;

		//판별
		for (int j = 0; j < a.size(); j++) {
			if (a[j] == 'R' && a[j + 1] == 'R') {
				j = j + 1;
				continue;
			}
			else if (a[j] == 'R') {
				SWAP(begin, end, tmp);
				flag == 0 ? flag = 1 : flag = 0;
			}
			else {
				if (flag == 0) {
					if (begin > end) {
						errflag = 1;
						break;
					}
					else {
						begin++;
					}
				}
				else {
					if (begin < end) {
						errflag = 1;
						break;
					}
					else {
						begin--;
					}
				}
			}
		}
		if (errflag == 1) {
			std::cout << "error\n";
		}
		else {
			if (flag == 0) {
				std::cout << "[";
				for (int j = begin; j <= end; j++) {
					std::cout << p[j];
					if (j != end) {
						std::cout << ",";
					}
				}
				std::cout << "]";
			}
			else {
				std::cout << "[";
				for (int j = begin; j >= end; j--) {
					std::cout << p[j];
					if (j != end) {
						std::cout << ",";
					}
				}
				std::cout << "]";
			}
			std::cout << "\n";
		}
	}

}