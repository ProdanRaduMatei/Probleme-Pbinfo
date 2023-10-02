#include <fstream>

using namespace std;

ifstream cin("secmax.in");
ofstream cout("secmax.out");

short n, v[25005], st[25005], dr[25005];
char c;

void read() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        v[i] = c - 48;
    }
}

void build() {
    int x = -1;
    for (int i = 1; i <= n; i++) {
        if (v[i] > x)
            st[i] = st[i - 1] + 1;
        else
            st[i] = 1;
        x = v[i];
    }
    x = -1;
    for (int i = n; i >= 1; i--) {
        if (v[i] > x)
            dr[i] = dr[i + 1] + 1;
        else
            dr[i] = 1;
        x = v[i];
    }
}

void solve() {
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans += (st[i] - 1) * (dr[i] - 1);
    cout << ans;
}

int main() {
    read();
    build();
    solve();
}