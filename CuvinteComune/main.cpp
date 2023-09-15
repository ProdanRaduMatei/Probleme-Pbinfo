#include <bits/stdc++.h>

using namespace std;

int n, i, k;
char s1[256], s2[256], c[25], *p;
bool ok;
string v[256], aux;

int main()
{
    cin.getline(s1, 256);
    cin.getline(s2, 256);
    n = strlen(s1);
    p = strtok(s1, " .");
    while (p) {
        strcpy(c, p);
        v[++k] = c;
        p = strtok(NULL, " .");
    }
    n = strlen(s1);
    p = strtok(s2, " .");
    while (p) {
        strcpy(c, p);
        v[++k] = c;
        p = strtok(NULL, " .");
    }
    do {
        ok = true;
        for (i = 1; i < k; ++i)
            if (v[i] > v[i + 1]) {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                ok = false;
            }
    } while (!ok);
    for (i = 1; i <= k; ++i)
        cout << v[i] << "\n";
    return 0;
}
