#include <iostream>

using namespace std;

void P(int x[], int n, int& s) {
	bool k = 0;
	for (int i = 0; i < n; ++i) {
		for (int d = 3; d * d <= x[i]; d = d + 2)


	}
}

int main() {
	int n, x[100], s;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i];
	P(x, n, s);
	cout << s;
	return 0;
}