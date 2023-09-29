#include <iostream>

using namespace std;

int minim = 1000001, val, mij, dr, st, k, n, a[1001];

int main() {
    cin >> n >> k;
    for (int x = 1 ; x <= n ; x++)
        cin >> a[x];
    st = 1, dr = 1000000;
    while (st <= dr) {
        mij = (st + dr) / 2;
        val = 0;
        for (int x = 1 ; x <= n ; x++)
            val += mij / a[x];
        if (val >= k) {
            if (mij < minim)
                minim = mij;
            dr = mij - 1;
        }
        else
            st = mij + 1;
    }
    cout << minim;
}