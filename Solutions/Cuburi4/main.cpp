#include <iostream>

using namespace std;

long long c, n, x, L, H, maxL, maxH, i, ant;

int main() {
    cin >> c >> n;
    cin >> x;
    if (x % 2 == 0)
        L = 1;
    else
        L = 0;
    H = x;
    maxL = L;
    maxH = H;
    ant = x;
    for (i = 2; i <= n; ++i) {
        cin >> x;
        if (x % 2 == 0)
            ++L;
        else
            L = 0;
        maxL = max(L, maxL);
        if (x < ant)
            H += x;
        else
            H = x;
        maxH = max(H, maxH);
        ant = x;
    }
    if (c == 1)
        cout << maxL;
    else
        cout << maxH;
    return 0;
}