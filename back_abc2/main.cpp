#include <iostream>
using namespace std;

int n, m, x[11];

void Afisare()
{
    int i;
    char c;
    for (i = 1; i <= m; i++)
    {
        c = 'A' + x[i] - 1;
        cout << c;
    }
    cout << "\n";
}

int Valid(int k)
{
    int i;
    for (i = 1; i < k; i++)
        if (x[i] == x[k])
            return 0;
    return 1;
}

void Backtracking(int k)
{
    if (k > m)
        Afisare();
    else
    {
        int i;
        for (i = 1; i <= n; i++)
        {
            x[k] = i;
            if (Valid(k))
                Backtracking(k + 1);
        }
    }
}

int main()
{
    cin >> n >> m;
    Backtracking(1);
    return 0;
}