#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int CL[n + 1];
    for (int i = 1; i <= n; ++i)
        CL[i] = i;
    int op, x, y;
    while (m--) {
        cin >> op >> x >> y;
        if (op == 1) {
            if (CL[x] != CL[y]) {
                for (int i = 1; i <= n; ++i)
                    if (i != y && CL[i] == CL[y])
                        CL[i] = CL[x];
                CL[y] = CL[x];
            }
        }
        else
            if (CL[x] == CL[y])
                cout << "DA\n";
            else
                cout << "NU\n";
    }
    return 0;
}