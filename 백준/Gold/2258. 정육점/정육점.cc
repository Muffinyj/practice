#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct meat {
	int w;
	int p;
};

bool compare(const meat& a, const meat& b) {
	if (a.p < b.p) {
		return 1;
	}
	else if (a.p == b.p) {
		if (a.w > b.w) {
			return 1;
		}
		return 0;
	}
	return 0;
}

int main() {
	int n, m;
	cin >> n >> m;
	meat* mt = (meat*)calloc(n, sizeof(meat));

	for (int i = 0; i < n;i++) {
		cin >> mt[i].w >> mt[i].p;
	}

	sort(mt, mt+n, compare);

	int weight = 0;
	int price = 0, curP = 0;
	int tmp = 0, wtmp = 0;
	int i = 0;
	while (1) {
		if (i == n) {
			if (weight < m) {
				price = -1;
			}
			break;
		}
		else if (weight < m) {
			weight += mt[i].w;
			if (curP == mt[i].p) {
				if (curP == mt[n - 1].p) {
					price += mt[i].p;
				}
				else {
					tmp = i;
					while (curP == mt[tmp].p) {
						tmp++;
						wtmp += mt[tmp].w;
					}
					if (mt[tmp].p >= price + mt[i].p) {
						price += mt[i].p;
					}
					else {
						i = tmp;
						weight += wtmp;
						price = mt[i].p;
						curP = price;
					}
				}
			}
			else {
				price = mt[i].p;
				curP = price;
			}
		}
		else {

			break;
		}
		i++;
		wtmp = 0;
	}

	printf("%d", price);

	return 0;
}