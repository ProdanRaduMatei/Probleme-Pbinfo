using namespace std;
#ifdef EZ
   #include "./ez/ez.h"
#else
   #include <bits/stdc++.h>
#endif
#define mp make_pair
#define mt make_tuple
#define ll long long
#define pb emplace_back
#define fi first
#define se second

int getInt()
{
    char c;
    while (!isdigit(c = getchar_unlocked()) && c != -1);
    if (c == -1)
        return 0;
    int x = c-'0';
    while (isdigit(c = getchar_unlocked()))
        x = x*10 + c-'0';
    return x;
}

int getRealNumber(int x)
{
    int toadd = 0;
    if (x >= 2)
        toadd += 16;
    if (x >= 5)
        toadd += 10;
    if (x >= 13)
        toadd += 10;
    if (x >= 71)
        toadd -= 14;
    if (x >= 103)
        toadd -= 14;
    return x + toadd;
}

int getDistance(int x)
{
    if (55 <= x && x <= 70)
        return 86 - x;
    if (87 <= x && x <= 102)
        return 118 - x;
    int xr = getRealNumber(x);
    return (xr + 17) / 18 * 18 - xr;
}

int main()
{
    freopen("chimie.in", "r", stdin);
    freopen("chimie.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int x, ans = 2, ap = 0;
    while (x = getInt())
    {
        int dx = getDistance(x);
        int dans = getDistance(ans);
        if (dx > dans)
            ans = x, ap = 1;
        else if (dx == dans)
            if (x > ans)
                ans = x, ap = 1;
            else if (x == ans)
                ap++;
    }
    cout << ans << ' ' << ap;
}