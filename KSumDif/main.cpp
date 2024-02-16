#include <iostream>
#include <cmath>

using namespace std;

long long int v[10001];

int main()
{
    long long n, k, s = 0, i;
    cin >> n >> k;
    for (i = 0; i < n; ++i)
        cin >> v[i];
    while (k > 1)
    {
        for (i = 0; i < n; ++i)
            v[i] += (v[i + 1] - abs(v[i] - v[i + 1]));
        --k;
        --n;
    }
    for (i = 0; i < n; ++i)
        s += v[i];
    cout << s;
    return 0;
}