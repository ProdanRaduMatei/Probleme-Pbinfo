#include <fstream>

#define ll long long

using namespace std;

ifstream cin("buldo.in");
ofstream cout("buldo.out");

int n;
ll v[100001], maxi, c;

void read() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (maxi < v[i])
            maxi = v[i];
    }
}


ll parcurgere(ll r) {
    ll cant = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] >= r)
            cant += (v[i] - r);
        else
            cant -= (r - v[i]);
        if (cant < 0)
            return -1;
    }
    return cant;
}


void solve() {
    int st = 1, dr = maxi, mid;
    ll t = 0;
    while (st <= dr) {
        mid = (st + dr) / 2;
        ll c = parcurgere(mid);
        if (c < 0)
            dr = mid - 1;
        else
            st = mid + 1, t = mid;
    }
    cout << t;
}


int main() {
    read();
    solve();
}