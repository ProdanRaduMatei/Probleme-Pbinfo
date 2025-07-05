#include <iostream>

using namespace std;

int main() {
    int l1, L1, l2, L2, d, n;
    cin >> l1 >> L1 >> d;
	l2 = l1 / d;
    L2 = L1 / d;
   	if (l1 % d == 0 && L1 % d == 0)
        n = l2 * L2;
    else if (l1 % d == 0 && L1 % d != 0)
        n = l2 * L2 + l2;
    else if (l1 % d != 0 && L1 % d == 0)
        n = l2 * L2 + L2;
    else if (l1 % d != 0 && L1 % d != 0)
        n = l2 * L2 + l2 + L2 - 1;
    cout << n;
    return 0;
}
