#include <iostream>

using namespace std;

int n, a[100001], c = 1;

int main()
{
    cin >> n;
    a[1] = 1;
    long long int suma = 0;
    while (n >= 10)
    {
        int t = 0;
        for (int j = 1; j <= c; ++j)
        {
            int cif = a[j] * 1024 + t;
            a[j] = cif % 10;
            t = cif / 10;
        }
        while (t)
        {
            a[++c] = t % 10;
            t /= 10;
        }
        n -= 10;
    }
    while (n)
    {
        int t = 0;
        for (int j = 1; j <= c; ++j)
        {
            int cif = a[j] * 2 + t;
            a[j] = cif % 10;
            t = cif / 10;
        }
        while (t)
        {
            a[++c] = t % 10;
            t /= 10;
        }
        n--;
    }
    for (int i = 1; i <= c; ++i)
        suma += a[i];
    cout << suma;
    return 0;
}