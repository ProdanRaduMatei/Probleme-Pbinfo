#include <iostream>

using namespace std;

int modificare(int v[], int n) {
	int p[10000], c = 0;
	bool k = 0;
	for (int i = 0; i < n; ++i) {
		k = 0;
		if (v[i] % 2 == 0 && v[i] != 2)
			k = 1;
		else {
			for (int d = 3; d * d <= v[i]; d = d + 2)
				if (v[i] % d == 0)
					k = 1;
		}
		if (k == 1) {
			p[c] = v[i];
			++c;
			for (int j = i; j < n - 1; ++j)
				v[j] = v[j + 1];
			--n;
		}
	}
	for (int i = 0; i < c; ++i)
		v[i + n] = v[i];
}

int main()
{
    int n, v[10000];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    modificare(v, n);
    for (int i = 0; i < n; ++i)
        cout << v[i] << " ";
    return 0;
}
