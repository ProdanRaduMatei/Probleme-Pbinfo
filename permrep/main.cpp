#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("permrep.in");
ofstream fout("permrep.out");
int n, p[30];
char s[256], cuv[256];
void afis()
{
    for (int i = 1; i <= n; i++)
        fout << s[i];
    fout << '\n';
}
void back(int k)
{
    for (int i = 0; i < 30; i++)
        if (p[i] > 0)
        {
            p[i]--;
            s[k] = i + 'a';
            if (k == n)
                afis();
            else
                back(k + 1);
            p[i]++;
        }
}
int main()
{
    fin >> cuv;
    n = strlen(cuv);
    for (int i = 1; i <= n; ++i)
        p[cuv[i - 1] - 'a']++;
    back(1);
    return 0;
}