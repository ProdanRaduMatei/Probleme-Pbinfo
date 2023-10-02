#include <fstream>

using namespace std;

ifstream cin("sir6.in");
ofstream cout("sir6.out");

int task, n, v[100001];

void read() {
    cin >> task >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
}

void solve1() {
    int l = 0, lmax = 0, t = -1;
    for (int i = 1; i <= n; i++) {
        if (t != v[i]) {
            lmax = max(lmax, l);
            l = 1;
            t = v[i];
        }
        else
            l++;
    }
    lmax = max(lmax, l);
    cout << lmax;
}

void solve2() {
    int l = 0, t = -1, start = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] != t) {
            if (t != -1)
                cout << v[start] << " " << l << " ";
            t = v[i];
            l = 1;
            start = i;
        }
        else
            l++;
    }
    cout << v[start] << " " << l;
}

int main() {
    read();
    if (task % 2)
        solve1();
    else
        solve2();
}