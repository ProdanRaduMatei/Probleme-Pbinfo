#include <iostream>

using namespace std;

int n, nrcif = 0, cif[9], x[9], y;
long long sum = 0;

void DescompunereCifre(int n)
{
    if (n)
    {
        DescompunereCifre(n / 10);
        cif[++nrcif] = n % 10;
    }
}

void FormareNumar()
{
    y = 0;
    for (int i = 1; i <= nrcif; ++i)
        y = y * 10 + cif[x[i]];
}

int Suma()
{
    FormareNumar();
    sum += y;
}

int Valid(int k)
{
    for (int i = 1; i < k; ++i)
        if (x[i] == x[k])
            return 0;
    return 1;
}

void Backtracking(int k)
{
    if (k > nrcif)
        Suma();
    else
    {
        for (int i = 1; i <= nrcif; ++i)
        {
            x[k] = i;
            if (Valid(k))
                Backtracking(k + 1);
        }
    }
}

int main()
{
    cin >> n;
    DescompunereCifre(n);
    Backtracking(1);
    cout << sum;
    return 0;
}