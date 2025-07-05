#include <fstream>

using namespace std;

ifstream cin("arc.in");
ofstream cout("arc.out");

int task, n, v[10001];

void read() {
    cin >> task >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
}

void solve1() {
    int ans = 0, p = 0;
    for (int i = 1; i <= n; i++)
        if (p != v[i]) {
            p = v[i];
            ans++;
        }
    cout << ans;
}

void print(int n) {
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    cout << "\n";
}

void remove(int i1, int j1, int &n) {
    int k = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        if (i < i1 || i > j1)
            v[++k] = v[i];
        else
            r++;
    }
    n -= r;
    int st = i1, dr = i1;
    while (v[st] == v[i1])
        st--;
    while (v[dr] == v[i1])
        dr++;
    st++;
    dr--;
    if (dr - st + 1 >= 3 && st != i1)
        remove(st, dr, n);
}

bool ok(int &n) {
    int left = 0, right = 0, lmax = 0;
    int p = 0, st = 0, dr = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] != p) {
            if (left && lmax < right - left + 1) {
                lmax = right - left + 1;
                st = left;
                dr = right;
            }
            left = right = i;
            p = v[i];
        }
        else
            right++;
    }
    if (left && lmax < right - left + 1) {
        lmax = right - left + 1;
        st = left;
        dr = right;
    }
    if (left && lmax >= 3)
        remove(st, dr, n);
    return (lmax >= 3);
}


void solve2() {
    while (n && ok(n));
    cout << n << "\n";
    for (int i = 1; i <= n; i++)
        cout << v[i] << "\n";
}


int main() {
    read();
    if (task % 2)
        solve1();
    else
        solve2();
}