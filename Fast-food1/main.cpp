#include <iostream>

using namespace std;

int v[10001];

int main()
{
    int n, t1, t2;
    cin >> n;
    int maxi = 0;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a] += 1;
        v[b + 1] -= 1;
        if (b > maxi)
            maxi = b;
    }
    for (int i = 1; i <= maxi; ++i)
        v[i] += v[i - 1];
    int maxim = 0;
    for (int i = 1; i <= maxi; ++i)
        if (v[i] > maxim)
            maxim = v[i];
    cout << maxim;
    return 0;
}