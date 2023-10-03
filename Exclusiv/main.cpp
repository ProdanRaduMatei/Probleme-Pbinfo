#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream cin("exclusiv.in");
ofstream cout("exclusiv.out");

int n, m, x;
vector <int> v, s;

void read() {
    cin >> m >> n;
    s.push_back(0);
    v.push_back(0);
    for (int i = 1; i <= m; i++) {
        cin >> x;
        s.push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        cin >> x;
        v.push_back(x);
    }
}

void solve() {
    int maxi = -1;
    int st = 0, dr = 0;
    bool k = 0;
    for (int i = 1; i <= n; i++) {
        x = v[i];
        maxi = 0;
        st = 0;
        dr = 0;
        k = 0;
        for (int j = 1; j <= m; j++) {
            if (!k && s[j] != x && s[j] != -1) {
                k = 1;
                st = dr = j;
            }
            else if (k && s[j] != x && s[j] != -1) {
                dr = j;
            }
            else if (k && (s[j] == x || s[j] == -1)) {
                if (maxi < dr - st + 1)
                    maxi = dr - st + 1;
                s[j] = -1;
                dr = st = 0;
                k = 0;
            }
            if (s[j] == x)
                s[j] = -1;
        }
        if (dr && maxi < dr - st + 1)
            maxi = dr - st + 1;
        cout << maxi << "\n";
    }
}

int main() {
    read();
    solve();
}