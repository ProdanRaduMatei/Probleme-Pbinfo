#include <cstring>
#include <fstream>

using namespace std;

ifstream fin("nmod25.in");
ofstream fout("nmod25.out");

int n, x;
int v[100011];
char c[100001];

int exponentiere(int base, int e)
{
    if (!e)
        return 1;
    else if (e % 2)
        return base * exponentiere(base, e - 1);
    int p = exponentiere(base, e / 2);
    return p * p;
}

int main()
{
    fin >> x >> c;
    int n = strlen(c);
    for (int i = 0; i < n; i++)
        v[n - i] = c[i] - '0';
    bool ok = 1;
    int a = v[4] * 1000 + v[3] * 100 + v[2] * 10 + v[1];
    if (a % (exponentiere(2, x)) == 0)
        fout << "DA\n";
    else
        fout << "NU\n";
    if (a % (exponentiere(5, x)) == 0)
        fout << "DA\n";
    else
        fout << "NU\n";
    return 0;
}