#include <iostream>

using namespace std;

int main() {
    int l, r, nrpare = 0, nrp = 0;
    cin >> l >> r;
    for (int i = l; i <= r; ++i)
        if (i % 2 == 0)
            ++nrpare;
    for (int i = 1; i <= nrpare; ++i)
        nrp = nrp + nrpare;
    cout << nrp;
    return 0;
}