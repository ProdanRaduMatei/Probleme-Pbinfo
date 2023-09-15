#include <iostream>

using namespace std;

int interval(int a[], int n) {
	int x = a[0], y = a[n - 1], c = 0;
	if (y < x)
		swap(x, y);
	for (int i = 0; i < n; ++i)
		if (a[i] >= x && a[i] <= y)
			++c;
	return c;
}

int main()
{
	int n, a[100];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cout << interval(a, n);
}