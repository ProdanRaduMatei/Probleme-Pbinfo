#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream cin("ktlon.in");
ofstream cout("ktlon.out");

vector<int> a;
vector<int> f;
vector<int> r;
long long int n, m, k, maxim, poz, c, ctm, sol, ctm1, ctm2, M, cs, s, sf, sr, ctmr, ctmf;

int main() {
    cin >> c;
    if (c == 1) {
        cin >> n >> m;
        for (int h = 1 ; h <= m ; h++) {
            maxim = 0;
            poz = 0;
            a.clear();
            ctm = 0;
            ctm1 = 0;
            ctm2 = 0;
            for (int x = 0 ; x < 2 * n ; x++) {
                cin >> k;
                a.push_back(k);
                if (k > maxim) {
                    maxim = k;
                    poz = x;
                }
            }
            for (auto x : a)
                if (x == maxim)
                    ctm++;
            if (ctm == 1)
                if (poz > n)
                    sol++;
        }
        cout<<sol;
    }
    else {
        cin >> n >> m;
        for (int h = 1 ; h <= m ; h++) {
            maxim = 0;
            poz = 0;
            f.clear();
            r.clear();
            ctm = 0;
            ctm1 = 0;
            ctm2 = 0;
            cs = -1;
            M = 0;
            s = 0;
            ctmf = 0;
            ctmr = 0;
            for (int x = 0 ; x < n ; x++) {
                cin>>k;
                f.push_back(k);
                if (k > maxim) {
                    maxim = k;
                    poz = x;
                }
            }
            for (int x = n ; x < 2 * n ; x++) {
                cin>>k;
                r.push_back(k);
                if (k > maxim) {
                    maxim = k;
                    poz = x;
                }
            }
            for (auto x : f)
                if (x == maxim)
                    ctmf++;
            for (auto x : r)
                if (x == maxim)
                    ctmr++;
            sort(f.begin(), f.end());
            sort(r.begin(), r.end());
            if ((ctmr == 0 && ctmf != 0) || (ctmf == 0 && ctmr != 0)) {
                if (poz < n)
                    cs = 0;
                else
                    cs = 1;
                if (cs == 0) {
                    for (int x = n - 1 ; x >= 0  ; x--)
                        if (f[x] > r[n-1])
                            M++;
                        else
                            break;
                    int t = n - 1;
                    while (M) {
                        s += (f[t] - r[t]);
                        t--;
                        M--;
                    }
                    sf += s;
                }
                else {
                    for (int x = n - 1 ; x >= 0  ; x--)
                        if (r[x] > f[n-1])
                            M++;
                        else
                            break;
                    int t = n - 1;
                    while (M) {
                        s += (r[t] - f[t]);
                        t--;
                        M--;
                    }
                    sr += s;
                }
            }
        }
        if (sr > sf)
            cout<<sr;
        else
            cout<<sf;
    }
}