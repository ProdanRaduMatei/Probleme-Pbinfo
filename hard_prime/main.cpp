#include <fstream>
#include <set>

using namespace std;

ifstream cin("hard_prime.in");
ofstream cout("hard_prime.out");

long long x;
int n;
set<int> M;

int prime(int x)
{
    if (x <= 3)
        return x >= 2;
    if (x % 2 == 0 || x % 3 == 0)
        return 0;
    for (int d = 5; d * d <= x; d += 6)
        if (x % d == 0 || x % (d + 2) == 0)
            return 0;
    return 1;
}

void citire()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        if (prime(x))
            M.insert(x);
    }
}

void afisare()
{
    for (auto e : M)
        cout << e << ' ';
}

int main()
{
    citire();
    afisare();
    return 0;
}