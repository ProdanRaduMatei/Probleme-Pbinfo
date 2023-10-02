#include <fstream>

using namespace std;

ifstream cin("secvb.in");
ofstream cout("secvb.out");

int b[50001], n, t, secv;
short x;

void read() {
    cin >> n >> t;
    int ct = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        ct = 0;
        while (x) {
            if ((x & 1))
                ct++;
            x = (x >> 1);
        }
        b[i] = ct;
    }
}


void solve() {
    int st = 1, sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += b[i];
        if (sum >= t) {
            while (sum > t)
                sum -= b[st], st++;
            if (sum == t)
                secv++;
        }
    }
    cout << secv;
}

int main() {
    read();
    solve();
}