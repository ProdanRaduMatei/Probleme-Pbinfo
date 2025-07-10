#include <iostream>

using namespace std;

int prm(int n) {
    int d = 2, cnt = 0;
    while (n > 1) {
        if (n % d == 0)
            cnt++;
        while (n % d == 0)
            n /= d;
        d++;
        if (d * d > n)
            d = n;
    }
    return cnt;
}

int main() {
    int n, x, maxi = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        if (prm(x) == 1 && x > maxi)
            maxi = x;
    }
    if (maxi != 0)
    cout << maxi;
    else
        cout << "NU EXISTA";
    return 0;
}
