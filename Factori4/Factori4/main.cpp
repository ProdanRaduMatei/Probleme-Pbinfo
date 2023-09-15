#include <iostream>

using namespace std;

bool ok(int n) {
    int d = 2, cnt = 0;
    while (n > 1) {
        int p = 0;
        while (n % d == 0) {
            n /= d;
            p++;
        }
        if (p)
            cnt++;
        d++;
        if (d * d > n)
            d = n;
    }
    return cnt == 1;
}
int main() {
    int n, x, mini = 1000000000;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        if (ok(x) && x < mini)
            mini = x;
    }
    if (mini < 1000000000)
    cout << mini;
    else
        cout << "NU EXISTA";
    return 0;
}
