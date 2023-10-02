#include <fstream>
#include <vector>

using namespace std;

ifstream fin("secventa.in");
ofstream fout("secventa.out");

vector<int> a;
int ctm, maxim, st, dr, s_max, s, n, k;

int main() {
    ios_base::sync_with_stdio(false);
    fin.tie(0);
    fout.tie(0);
    fin >> n;
    for (int x = 1 ; x <= n ; x++) {
        fin >> k;
        a.push_back(k);
    }
    s = a[0];
    ctm = 1;
    for (int x = 1 ; x < n ; x++) {
        if (a[x] % 2 != a[x - 1] % 2) {
            ctm++;
            s += a[x];
        }
        else {
            if (ctm > maxim) {
                maxim = ctm;
                s_max = s;
                st = x - ctm + 1;
                dr = x;
            }
            else if (ctm == maxim) {
                if (s >= s_max) {
                    maxim = ctm;
                    s_max = s;
                    st = x - ctm + 1;
                    dr = x;
                }
            }
            ctm = 1;
            s = a[x];
        }
    }
    if (ctm > maxim) {
        maxim = ctm;
        s_max = s;
        st = n - ctm + 1;
        dr = n;
    }
    else if (ctm == maxim) {
        if (s >= s_max) {
            maxim = ctm;
            s_max = s;
            st = n - ctm + 1;
            dr = n;
        }
    }
    ctm = 1;
    s = a[n];
    fout << st << ' ' << dr;
}