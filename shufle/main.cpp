#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("shuffle.in");
ofstream fout("shuffle.out");

int n, s[10], p[10], c1[10], c2[10], a[10], cnt;

void afis()
{
    for (int i = 1; i <= n; ++i)
        fout << s[i] << " ";
    fout << '\n';
    ++cnt;
}

void back(int k)
{
    for (int i = 1; i <= n; ++i)
        if (p[i] == 0 && s[k - 1] != c1[i] && s[k - 1] != c2[i])
        {
            p[i] = 1;
            s[k] = i;
            if (k == n)
                afis();
            else
                back(k + 1);
            p[i] = 0;
        }
}

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    a[0] = -1;
    a[n + 1] = -1;
    for (int i = 1; i <= n; ++i)
    {
        c1[a[i]] = a[i - 1];
        c2[a[i]] = a[i + 1];
    }
    back(1);
    if (cnt == 0)
        fout << "nu exista";
    return 0;
}