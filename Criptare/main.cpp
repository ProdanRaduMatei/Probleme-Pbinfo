#include <bits/stdc++.h>
using namespace std;
ifstream fin ("criptare.in");
ofstream fout ("criptare.out");
#define MAX 1010
int n, lin[MAX], col[MAX];
bool a[MAX][MAX];
vector<int> L, C;
int main() {
    fin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++) {
            fin >> a[i][j];
            lin[i] = lin[i] || a[i][j];
            col[j] = col[j] || a[i][j];
        }
    for (int i = 1; i <= n; i ++) {
        if (lin[i] == 0)
            L.push_back(i);
        if (col[i] == 0)
            C.push_back(i);
    }
    fout << max(L.size(), C.size()) << '\n';
    int mn = min(L.size(), C.size());
    for (int i = 0; i < mn; i ++)
        fout << L[i] << ' ' << C[i] << '\n';
    if (L.size() > C.size())
        for (int i = mn; i < L.size(); i ++)
            fout << L[i] << ' ' << 1 << '\n';
    else
        for (int i = mn; i < C.size(); i ++)
            fout << 1 << ' ' << C[i] << '\n';
    return 0;
}
