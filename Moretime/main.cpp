#include <fstream>

using namespace std;

ifstream cin("moretime.in");
ofstream cout("moretime.out");

struct element
{
    int nr_cont;
    int val;
} v[10001];

int n, nrc, bani;
short ans;
int k, st, dr;
int s[10001], temp;
bool stop;

short cifre(int x)
{
    short t = 0;
    while (x)
    {
        x /= 10;
        t++;
    }
    return t;
}

int exponentiere(int base, int e)
{
    if (!e)
        return 1;
    else if (e % 2)
        return base * exponentiere(base, e - 1);
    int p = exponentiere(base, e / 2);
    return p * p;
}

void read()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nrc >> bani;
        short nr_cifre = cifre(nrc);
        nr_cifre--;
        short c1 = nrc % 10;
        short c2 = nrc / (exponentiere(10, nr_cifre));
        if (c1 == c2)
        {
            ans++;
            k++;
            v[k].nr_cont = nrc;
            v[k].val = bani;
            s[k] = s[k - 1] + v[k].val;
        }
    }
}

void solve()
{
    for (int i = 1; i <= k && !stop; i++)
        if (s[i] % ans == 0)
        {
            cout << i << "\n";
            temp = i;
            stop = 1;
        }
    if (stop == 1)
        for (int i = 1; i <= temp; i++)
            cout << v[i].nr_cont << " ";
    else if (!stop)
        for (int i = 1; i <= k; i++)
            for (int j = i + 1; j <= k; j++)
                if (s[i] % ans == s[j] % ans)
                {
                    st = i, dr = j;
                    break;
                }
    st++;
    cout << dr - st + 1 << "\n";
    for (int p = st; p <= dr; p++)
        cout << v[p].nr_cont << " ";
}

int main()
{
    read();
    cout << ans << "\n";
    solve();
}