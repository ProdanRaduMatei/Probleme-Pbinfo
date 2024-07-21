#include <fstream>
#include <deque>

using namespace std;

ifstream fin("secv.in");
ofstream fout("secv.out");

const int NMAX = 1e6;
int sp1[NMAX + 1], sp2[NMAX + 1], v[NMAX + 1], task, n, k, s, ans;

void read()
{
    fin >> task >> n >> k >> s;
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        fin >> v[i];
        sp1[j] = sp1[j - 1] + v[i];
        sp2[i] = sp2[i - 1] + v[i];
        if (j >= k && sp1[j] - sp1[j - k] > s)
        {
            j -= k;
            ans++;
        }
        j++;
    }
}

void solve()
{
    deque<int> dq;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!dq.empty() && dq.front() == i - 1)
            dq.pop_front();
        if (i + k <= n)
        {
            while (!dq.empty() && sp2[i + k] - sp2[i - 1] >= sp2[dq.back()] - sp2[dq.back() - k - 1])
                dq.pop_back();
            dq.push_back(i + k);
        }
        if (!dq.empty() && sp2[dq.front()] - sp2[dq.front() - k - 1] > s + v[i])
            ans++;
    }
    fout << ans;
}

int main()
{
    read();
    if (task % 2)
        fout << ans;
    else
        solve();
    return 0;
}