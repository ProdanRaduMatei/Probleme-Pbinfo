#include <bits/stdc++.h>
using namespace std;
ifstream fin ("tripar.in");
ofstream fout ("tripar.out");
long long cer, n, m, p[50005], putere, rez;
int main() {
    fin >> cer >> n >> m;
    for(int i=1; i<=n; i++)
        fin >> p[i];
    if (cer == 1)
        for(int i=1; i<=n; i++) {
            putere = pow(4, m);
            p[i]*=p[i];
            fout << p[i]*putere << '\n';
        }
    else
        for(int i=1; i<=n; i++) {
            putere=pow(2, m);
            rez = p[i]*putere;
            rez = rez*(rez - 1);
            fout << 3*rez/2 << '\n';
        }
    return 0;
}
