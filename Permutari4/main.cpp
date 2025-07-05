#include <fstream>
#include <stack>

using namespace std;

ifstream cin("permutari4.in");
ofstream cout("permutari4.out");

const int NMAX = 1e5;
int n, v[NMAX + 1], st[NMAX + 1], dr[NMAX + 1];

void read() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
}

void build() { 
    stack <int> s, d;
    for (int i = 1; i <= n; i++) {
        while (!s.empty() && v[i] >= v[s.top()])
            s.pop();
        if (s.empty())
            st[i] = 1;
        else
            st[i] = s.top() + 1;
        s.push(i);
    }
    for (int i = n; i >= 1; i--) {
        while (!d.empty() && v[i] >= v[d.top()])
            d.pop();
        if (d.empty())
            dr[i] = n;
        else
            dr[i] = d.top() - 1;
        d.push(i);
    }
}

void solve() {
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (dr[i] - st[i] + 1 == v[i])
            ans++;
    cout << ans;
}

int main() {
    read();
    build();
    solve();
}