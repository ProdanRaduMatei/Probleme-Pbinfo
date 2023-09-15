#include <iostream>

using namespace std;

void next_perm(int n, int P[]) {
	int u = P[n];
	for (int i = n; i > 1; --i)
		P[i] = P[i - 1];
	P[1] = u;
}

int main() {
	int n, P[100000];
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> P[i];
	next_perm(n, P);
	for (int i = 1; i <= n; ++i)
		cout << P[i] << " ";
	return 0;
}