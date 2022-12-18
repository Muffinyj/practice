#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, dec(9), cnt(0), tmp, i(1);
	cin >> n;

	tmp = n;
	while (tmp > 0) {
		tmp = n - dec;
		if (tmp < 0) {
			cnt += n * i;
		}
		else {
			cnt += dec*i;
			n = tmp;
			dec = (9 * pow(10,i));
			i++;
		}
	}

	cout << cnt;

	return 0;
}