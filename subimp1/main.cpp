#include <iostream>

using namespace std;

int n, x[20];

void afisare(int n)
{
    for (int i = 1; i <= n; ++i)
        cout << x[i] << " ";
    cout << "\n";
}

void back(int k)
{
    for (int i = x[k - 1] + 1; i <= n; ++i)
    {
        x[k] = i;
        if (k % 2 == 1)
            afisare(k);
        back(k + 1);
    }
}

int main()
{
    cin >> n;
    back(1);
    return 0;
}