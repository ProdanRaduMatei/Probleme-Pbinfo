#include <iostream>

using namespace std;

int n, x[15];

bool cond(int k)
{
    if (k >= n / 2 + 1 && x[n / 2 + 1] != n)
        return 0;
    for (int i = 1; i < k; i++)
        if (x[i] == x[k])
            return 0;
    return 1;
}

bool sol(int k)
{
    return k == n;
}
void print(int k)
{
    for (int i = 1; i <= k; i++)
        cout << x[i] << ' ';
    cout << '\n';
}

void bkt(int k)
{
    for (int i = 1; i <= n; i++)
    {
        x[k] = i;
        if (cond(k))
            if (sol(k))
                print(k);
            else
                bkt(k + 1);
    }
}

int main()
{
    cin >> n;
    bkt(1);
    return 0;
}