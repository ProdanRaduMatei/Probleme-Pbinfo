#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long v[1000000] = {0}, x, d = 0, i = 1;
    while (cin >> v[i] && v[i] != 0)
    	++i;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j)
            if (v[i] == v[j]) {
                cout << v[i];
                return 0;
            }
    }
    return 0;
}
