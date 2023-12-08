#include <iostream>
#include <cmath>

using namespace std;

bool Prim(int x) {
    if (x < 2) 
        return false;
    if (x == 2)
        return true;
    if (x % 2 == 0)
        return false;
    for (int d = 3; d * d <= x; d += 2)
        if (x % d == 0)
            return false;
    return true;
}

bool PatratPerfect(int x) {
    float y = sqrt(x);
    if (y == (int)y && Prim((int)y) && (int)y != x && (int)y != 1)
        return true;
    return false;
}

int main() {
    int n, x, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (PatratPerfect(x))
            cnt++;
    }
    cout << cnt;
    return 0;
}