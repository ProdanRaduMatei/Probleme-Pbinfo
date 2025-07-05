#include <bits/stdc++.h>

using namespace std;

char s[25], t[25], aux;
int i, n, j;

int main()
{
    ifstream fin("permutarecuvant.in");
    ofstream fout("permutarecuvant.out");
    fin >> s;
    fout << s << " ";
    n = strlen(s);
    for (j = 1; j < n; ++j) {
        aux = s[0];
        for (i = 1; i < n; ++i)
            t[i - 1] = s[i];
        t[n - 1] = aux;
        t[n] = 0;
        fout << t << " ";
        strcpy(s, t);
    }
    return 0;
}
