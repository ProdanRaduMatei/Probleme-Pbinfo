#include <bits/stdc++.h>

using namespace std;

int i, j, q, n, m, lu, k, k1, k2, k3;
char s[15000], c[50], *p, sep[] = " ";
string v1[105], v2[105], v3[105];

int main()
{
    ifstream fin("s_p_c.in");
    ofstream fout("s_p_c.out");
    fin.getline(s, sizeof(s));
    p = strtok(s, sep);
    while (p) {
        strcpy(c, p);
        lu = strlen(c);
        if (c[lu - 1] == 'S') {
            c[lu - 2] = NULL;
            v1[++k1] = c;
        }
        if (c[lu - 1] == 'P') {
            c[lu - 2] = NULL;
            v2[++k2] = c;
        }
        if (c[lu - 1] == 'C') {
            c[lu - 2] = NULL;
            v3[++k3] = c;
        }
        p = strtok(NULL, sep);
    }
    sort(v1 + 1, v1 + k1 + 1);
    sort(v2 + 1, v2 + k2 + 1);
    sort(v3 + 1, v3 + k3 + 1);
    for (i = 1; i <= k1; ++i)
        for (j = 1; j <= k2; ++j)
            for (q = 1; q <= k3; ++q)
                fout << v1[i] << " " << v2[j] << " " << v3[q] << "\n";
    return 0;
}
