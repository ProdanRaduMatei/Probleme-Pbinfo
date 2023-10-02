#include <fstream>

using namespace std;

ifstream cin("cmmdcsecv.in");
ofstream cout("cmmdcsecv.out");

int nr[1001];
int prime[501], m;
int v[100001], n;
int lmax;


void ciur() {
    for (int i = 1; ((i * i) << 1) + (i << 1) <= 1001; i++)
        if (!nr[i])
            for (int j = ((i * i) << 1) + (i << 1); (j << 1) + 1 <= 1001; j += ((i << 1) + 1))
                nr[j] = 1;
    for (int i = 3; i <= 1001; i += (1 << 1))
        if (!nr[i / 2])
            prime[++m] = i;
}

void citire() {
    cin >> n;
    int l = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] % 2 == 0)
            l++;
        else {
            if (lmax <= l && l >= 1)
                lmax = l;
            l = 0;
        }
    }
    if (lmax <= l && l > 1)
        lmax = l;
}

void solve() {
    int l = 0;
    for (int i = 1; i <= m; i++) {
        l = 0;
        for (int j = 1; j <= n; j++) {
            if (v[j] % prime[i] == 0)
                l++;
            else {
                if (lmax <= l && l >= 1)
                        lmax = l;
                    l = 0;
            }
        }
        if (lmax <= l && l > 1)
            lmax = l;
    }
}

int main() {
    ciur();
    citire();
    solve();
    cout << lmax;
}