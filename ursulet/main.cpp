#include <fstream>

using namespace std;

ifstream cin("ursulet.in");
ofstream cout("ursulet.out");

int n, x, s, lmax, st, dr, smax, start, j;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (s < 0) {
            s = x;
            start = i;
            j = i;
        }
        else {
            s += x;
            j = i;
        }
        if (s > smax) {
            smax = s;
            st = start;
            dr = j;
        }
    }
    cout << smax << "\n";
    cout << st << " " << dr << "\n";
}