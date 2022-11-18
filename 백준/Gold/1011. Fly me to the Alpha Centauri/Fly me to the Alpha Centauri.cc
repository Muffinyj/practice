#include <iostream>

int main() {
	int n;
	std::cin >> n;

	unsigned int x, y;
	unsigned int distance;
	unsigned int move = 1;
	unsigned int movecnt = 0;

	for (int i = 0; i < n; i++) {
		std::cin >> x >> y;
		distance = y - x;
		if (y - x == 1 || y - x == 2) {
			std::cout << y - x << "\n";
			continue;
		}
		else {
			while (distance / 2 >= move) {
				distance -= move * 2;
				move++;
				movecnt += 2;
			}
			if (1 <= distance && move >= distance) {
				movecnt++;
			}
			else if(move < distance) {
				movecnt += 2;
			}
			std::cout << movecnt << "\n";
		}
		move = 1;
		movecnt = 0;
	}
}