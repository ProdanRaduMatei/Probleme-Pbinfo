#include <fstream>

using namespace std;

ifstream fin("bile2.in");
ofstream fout("bile2.out");

int n, m, h, k, x, t;
struct
{
    int height;
    int constanta;
} v[100001];

void solve()
{
    int anterior = v[x].height;
    k = v[x].constanta;
    h = v[x].height;
    bool show = 0;
    int temp = 0;
    if (h - t >= 0)
        fout << h - t << "\n";
    else
    {
        while (!show)
        {
            temp = t;
            t -= h;
            if (t <= 0)
            {
                fout << h - temp << "\n";
                show = 1;
                break;
            }
            h = anterior - k;
            anterior = h;
            temp = t;
            if (h <= 0)
            {
                fout << 0 << "\n";
                show = 1;
                break;
            }
            t -= h;
            if (t <= 0)
            {
                fout << temp << "\n";
                show = 1;
                break;
            }
        }
    }
}

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        fin >> h >> k;
        v[i].height = h;
        v[i].constanta = k;
    }
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> t;
        solve();
    }
    return 0;
}