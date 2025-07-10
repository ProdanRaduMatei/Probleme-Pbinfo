#include <algorithm>
#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

int p[12], x[12], f[12], n;
unordered_map<int, int> primes;

static int prime(int a)
{
    int i, j, bound;

    if (a == 0 || a == 1)
        return 0;
    if (a == 2 || a == 3 || a == 5)
        return 1;
    if (a % 2 == 0 || a % 3 == 0 || a % 5 == 0)
        return 0;

    bound = sqrt((double)a);

    i = 7;
    j = 11;
    while (j <= bound && a % i && a % j)
    {
        i += 6;
        j += 6;
    }

    if ((j <= bound) || ((i <= bound) && (a % i == 0)))
        return 0;

    return 1;
}

static void backtrack(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (!f[i])
        {
            x[k] = p[i];
            f[i] = 1;

            if (!primes[x[k]] || !primes[x[k - 1]])
            {
                if (k == n)
                {
                    for (int j = 1; j <= n; j++)
                        cout << x[j] << " ";
                    cout << '\n';
                }
                else
                    backtrack(k + 1);
            }
            f[i] = 0;
        }
    }
}

int main()
{
    ios ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (auto i = 1; i <= n; i++)
    {
        cin >> p[i];

        if (prime(p[i]))
            primes[p[i]] = 1;
    }

    sort(p + 1, p + n + 1);

    backtrack(1);

    return 0;
}