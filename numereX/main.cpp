#include <fstream>
#include <vector>

using namespace std;

ifstream fin("numere.in");
ofstream fout("numere.out");

const int N = 100000;
short task;
int n, m, t, maxi, nr;
int d[N + 1];
vector<int> v;
long long ans;

void read()
{
    fin >> task;
    if (task % 2)
        fin >> n;
    else
        fin >> n >> m >> t;
}

void ciur()
{
    for (int i = 1; i <= N; ++i)
        for (int j = i; j <= N; j += i)
            ++d[j];
}

void solve1()
{
    for (int i = 1; i <= n; ++i)
        if (maxi < d[i])
        {
            maxi = d[i];
            nr = i;
        }
    fout << nr;
}

void solve2()
{
    bool next = 0;
    for (int i = 1; !next && i <= N; ++i)
        if (t + 2 == d[i])
        {
            v.push_back(i);
            if (i > n)
                next = 1;
        }
    int st = 0, dr = 0, up = 0, down = 0;
    for (int i = 0; v.size() && i < v.size() - m; ++i)
    {
        if (i == 0)
        {
            st = v[i];
            down = 1;
        }
        else
        {
            st = v[i];
            down = v[i - 1] + 1;
        }
        dr = v[i + m - 1];
        up = v[i + m] - 1;
        while (up > n)
            --up;
        st = st - down + 1;
        dr = up - dr + 1;
        ans += (st * dr);
    }
    fout << ans;
}

int main()
{
    read();
    ciur();
    if (task % 2)
        solve1();
    else
        solve2();
    return 0;
}