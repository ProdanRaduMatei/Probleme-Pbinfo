#include <bits/stdc++.h>

using namespace std;

vector <int>G[101];

struct poz {
    int val, cul;
}f[2001];
int n, m, x, y, cer, rez[2001], cnt;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        f[i].val = i;
        f[i].cul = i;
    }
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> cer >> x >> y;
        if(cer == 1)
        {
            int mini = min(f[x].cul , f[y].cul) , maxi = max(f[x].cul , f[y].cul);
            f[x].cul = mini;
            f[y].cul = mini;
            for(int i = 1 ; i <= n ; i++)
                if(f[i].cul == maxi) f[i].cul = mini;
        }
        else
        {
            if(f[x].cul == f[y].cul) rez[++cnt] = 1;
            else rez[++cnt] = 0;
        }
    }
    for(int i = 1 ; i <= cnt ; i++)
        if(rez[i] == 1) cout << "DA\n";
        else cout << "NU\n";
}
