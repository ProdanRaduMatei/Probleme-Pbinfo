#include <fstream>

using namespace std;

ifstream cin("tort.in");
ofstream cout("tort.out");

const int NMAX = 4e5;
int sume[NMAX + 1], v[NMAX / 2 + 1], n, ans;

void read() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
}

void solve() {
    int s = 0;
    for (int i = n; i >= 1; i--) {
        s += v[i];
        sume[s] = 1;
    }
    for (int i = 1; i < s; i++)
        if (sume[i])
            for (int j = i; j < s; j += i)
                if (sume[j])
                    ans++;
                else 
                    break;
    cout << ans;
}

int main() {
    read();
    solve();
}