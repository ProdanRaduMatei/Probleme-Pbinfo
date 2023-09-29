#include <iostream>
#include <vector>

using namespace std;

const int inf = 2000000001;
vector<int> s;
int n, ri, rj, dmin, x, y, z, d;

inline int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

inline int max(int x, int y, int z)
{
    return max(max(x, y), z);
}

inline int cb(int i)
{
    int j = n - 1, mij, st = i, dr = n - 1, dif = inf, s1, s2;
    while (st <= dr) {
        mij = (st + dr) / 2;
        s1 = s[mij] - s[i - 1];
        s2 = s[n] - s[mij];
        if (s1 < s2) {
            if (dif > s2 - s1) {
                dif = s2 - s1;
                j = mij;
            }
            st = mij + 1;
        }
        else {
            if (dif > s1 - s2) {
                dif = s1 - s2;
                j = mij;
            }
            dr = mij - 1;
        }
    }
    return j;
}
int main() {
    cin >> n;
    s = vector<int>(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        s[i] = s[i - 1] + x;
    }
    ri = 1;
    rj = 2;
    x = s[1];
    y = s[2] - s[1];
    z = s[n] - s[2];
    dmin = max(x, y, z) - min(x, y, z);
    for (int i = 1; i < n - 1; ++i) {
        int j = cb(i + 1);
        x = s[i];
        y = s[j] - s[i];
        z = s[n] - s[j];
        d = max(x, y, z) - min(x, y, z);
        if (d < dmin) {
            dmin = d;
            ri = i;
            rj = j;
        }
    }
    cout << ri << ' ' << rj;
    return 0;
}