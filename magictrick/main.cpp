#include <bits/stdc++.h>

#define MAX 500000

using namespace std;

const string file = "magictrick";

ifstream in(file + ".in");
ofstream out(file + ".out");

#define cin in
#define cout out

int f[500005], nr[500005], c, n, x, d;
long long s[500005],drs, sum, cmmdc;

int main()
{
    cin >> c >> n;
    if (c == 1)
    {
        cin>>x;
        sum+=x;
        cmmdc=x;
        for (int i = 2; i <=n; ++i)
        {
            cin >> x;
            sum += x;
            int a = cmmdc, b = x;
            while (b) {
                int  r = a % b;
                a = b;
                b = r;
                cmmdc = a;
            }
        }
        cout << cmmdc * sum;
    }
    else
    {
        for (int i = 1; i <=n; ++i)
        {
            cin >> x;
            ++nr[x];
        }
        for (int i = 1; i <=MAX; ++i)
            for (int j = i; j <=MAX; j += i) {
                f[i] += (long long)nr[j];
                s[i] += (long long)nr[j] * j;
            }
        for (int i = 1; i <= MAX; ++i)
            if (f[i] >= 2 && s[i] * i > drs)
                drs = s[i] * i;
        cout << drs;
    }
    return 0;
}