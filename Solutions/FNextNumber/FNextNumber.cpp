#include <iostream>

using namespace std;

long long NextNumber(long long n) {
	long long m = n + 1;
	int c, cn = 0, cm = 0;
	bool k = 0;
	while (n) {
		if (n % 2 == 1)
			++cn;
		n = n / 2;
	}
	while (k == 0) {
		c = m;
		cm = 0;
		while (c) {
			if (c % 2 == 1)
				++cm;
			c = c / 2;
		}
		if (cm == cn)
			k = 1;
		else
			++m;
	}
	return m;
}

int main() {
	long long n;
	cin >> n;
	cout << NextNumber(n);
	return 0;
}