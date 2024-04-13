#include <iostream>

using namespace std;

int main()
{
    int n, v[101] = {0};
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n - 1; ++j)
        {
            int var;
            cin >> var;
            if (j < i)
                v[j] += var;
            else
                v[j + 1] += var;
        }
    int maxim = 0, nrOrdine = 0;
    for (int i = 1; i <= n; ++i)
        if (v[i] > maxim)
        {
            maxim = v[i];
            nrOrdine = i;
        }
    cout << nrOrdine;
    return 0;
}