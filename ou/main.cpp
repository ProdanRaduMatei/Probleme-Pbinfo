#include <fstream>
#define ll long long

using namespace std;

ifstream cin("ou.in");
ofstream cout("ou.out");

int n, st_global, dr_global;
long long v[100001], mars[100001], oua;

void read() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
}

long long cb_st(int lim_st, int i) {
    long long mid, st = 1, dr = lim_st, val = 0;
    while (st < dr) {
        mid = (st + dr) / 2;
        if (v[i] / (2 * mid) && i - mid)
            st = mid + 1, val = mid;
        else
            dr = mid - 1;
    }
    if (st > val && v[i] / (2 * st) && i - st)
        return st;
    return val;
}

long long cb_dr(int lim_dr, int i) {
    long long mid, st = 1, dr = lim_dr, val = 0;
    while (st < dr) {
        mid = (st + dr) / 2;
        if (v[i] / (2 * mid) && i + mid <= n)
            st = mid + 1, val = mid;
        else dr = mid - 1;
    }
    if (st > val && v[i] / (2 * st) && i - st)
        return st;
    return val;
}

void solve() {
    long long rtn;
    for (int i = 2; i < n; ++i) {
        st_global = i - 1;
        dr_global = n - i;
        if (st_global <= dr_global)
            rtn = cb_st(st_global, i);
        else 
            rtn = cb_dr(dr_global, i);
        if (!rtn)
            ++rtn;
        oua = v[i] / (2 * rtn);
        v[i] -= 2 * oua * rtn;
        mars[i - rtn] += oua;
        mars[i] -= oua;
        mars[i + 1] += oua;
        mars[i + rtn + 1] -= oua;
    }
}

void afisare() {
    for (int i = 1; i <= n; ++i) {
        mars[i] += mars[i - 1];
        v[i] += mars[i];
        cout << v[i] << " ";
    }
}

int main() {
    read();
    solve();
    afisare();
}