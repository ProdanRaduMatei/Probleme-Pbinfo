#include <iostream>

using namespace std;

int rezultat[100002], V[1002], n, x;

int main()
{
    rezultat[0] = 1;
    rezultat[1] = 1;
    cin >> n;
    for (int k = 1; k <= n; k++)
    {
        V[k] = 1;
        cin >> x;
        int divizor = 2;
        while (x != 1)
        {
            if (x % divizor == 0)
                V[k] *= divizor;
            while (x % divizor == 0)
                x /= divizor;
            if (divizor == 2)
                divizor = 3;
            else
                divizor += 2;
            if (divizor * divizor > x)
                divizor = x;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        int t = 0;
        for (int j = 1; j <= rezultat[0]; j++)
        {
            int cif = t + V[i] * rezultat[j];
            rezultat[j] = cif % 10;
            t = cif / 10;
        }
        while (t)
        {
            rezultat[++rezultat[0]] = t % 10;
            t /= 10;
        }
    }
    for (int i = rezultat[0]; i > 0; i--)
        cout << rezultat[i];
    return 0;
}