#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("devt.in");
ofstream fout("devt.out");

int a[100001], n, s[100001], k, st, dr;

void gen_sir()
{
    a[1] = 1;
    for (int x = 2; x <= n; ++x)
        if (a[x] == 0)
            for (int j = x + x; j <= n; j += x)
                a[j] = 1;
}

int main()
{
    fin >> n;
    gen_sir();
    for (int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + a[i];
    fin >> k;
    while (k--)
    {
        fin >> st >> dr;
        fout << s[dr] - s[st - 1] << '\n';
    }
    return 0;
}