#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define LL long long
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define X first
#define Y second

struct Task
{
    int id, len, deadline, start;
};

int n, sol = 0;
vector<Task> a;
vector<bool> chosen;
vector<pair<LL, LL>> cal;

bool byDeadline(const Task &x, const Task &y)
{
    return x.deadline < y.deadline;
}

int main()
{
    ifstream fin("bolovani.in");
    fin >> n;
    a.resize(n + 1);
    FOR(i, 1, n)
    fin >> a[i].len >> a[i].deadline, a[i].id = i;
    sort(a.begin() + 1, a.end(), byDeadline);
    chosen.resize(n + 1);
    LL t = 0;
    FOR(i, 1, n)
    if (t + a[i].len <= a[i].deadline)
        chosen[i] = true, ++sol, a[i].start = t + 1, t += a[i].len;
    else
    {
        int longest = -1;
        FOR(j, 1, n)
        if (chosen[j])
            if (longest == -1 || a[longest].len < a[j].len)
                longest = j;
        if (longest != -1 && a[longest].len > a[i].len)
        {
            chosen[longest] = false;
            t -= a[longest].len;
            a[i].start = t + 1;
            FOR(j, longest + 1, n)
            if (chosen[j])
                a[j].start -= a[longest].len;
            chosen[i] = true;
            t += a[i].len;
        }
    }
    cal.resize(n + 1);
    FOR(i, 1, n)
    if (chosen[i])
        cal[a[i].id] = {a[i].start, a[i].start + a[i].len - 1};
    FOR(i, 1, n)
    if (!chosen[i])
        cal[a[i].id] = {t + 1, t + a[i].len}, t += a[i].len;
    ofstream fout("bolovani.out");
    fout << sol << '\n';
    FOR(i, 1, n)
    fout << cal[i].X << ' ' << cal[i].Y << '\n';
    return 0;
}