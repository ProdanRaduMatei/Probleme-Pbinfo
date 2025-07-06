#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ifstream fin("antidivizor.in");
ofstream fout("antidivizor.out");

const int MAX_X = 60;
ll lcm_before[MAX_X + 2];
ll lcm_now[MAX_X + 2];

ll gcd(ll a, ll b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll safe_lcm(ll a, ll b)
{
    if (a == 0 || b == 0)
        return 0;
    if (a > LLONG_MAX / b)
        return -1; // overflow
    return a / gcd(a, b) * b;
}

void precalc()
{
    ll currLcm = 1;
    for (int x = 1; x <= MAX_X; ++x)
    {
        lcm_before[x] = currLcm;
        currLcm = safe_lcm(currLcm, x);
        if (currLcm == -1)
            break;
        lcm_now[x] = currLcm;
    }
}

ll computeFsum(ll N)
{
    ll res = 0;
    for (int x = 2; x <= MAX_X; ++x)
    {
        if (lcm_before[x] == 0 || lcm_before[x] > N)
            break;
        ll c1 = N / lcm_before[x];
        ll c2 = (lcm_now[x] == -1 || lcm_now[x] == 0 || lcm_now[x] > N) ? 0 : N / lcm_now[x];
        ll count = c1 - c2;
        res += count * x;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precalc();
    int T;
    fin >> T;
    while (T--)
    {
        ll N;
        fin >> N;
        fout << computeFsum(N) << "\n";
    }
    return 0;
}