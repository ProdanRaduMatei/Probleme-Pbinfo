#include <iostream>

using namespace std;

int main()
{
    long long n, v[100001], d = -1000000000;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (v[i] - v[j] > d)
                d = v[i] - v[j];
    cout << d;
    return 0;
}
