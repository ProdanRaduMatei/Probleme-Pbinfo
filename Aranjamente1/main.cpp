#include <iostream>

using namespace std;

int a, b, n, x[9];

void afisare()
{
    for (int i = 1; i <= n; ++i)
        cout << x[i] << " ";
    cout << "\n";
}

int valid(int k)
{
    for (int i = 1; i < k; ++i)
        if (x[i] == x[k])
            return 0;
    return 1;
}

void back(int k)
{
    if (k > n)
        afisare();
    else
        for (int i = a; i <= b; ++i)
        {
            x[k] = i;
            if (valid(k))
                back(k + 1);
        }
}

int main()
{
    cin >> a >> b >> n;
    back(1);
    return 0;
}