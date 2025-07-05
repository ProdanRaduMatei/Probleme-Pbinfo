#include <iostream>

using namespace std;

int desc(int n) {
    int cnt = 0, d = 2;
    while (n > 1) {
        int p = 0;
        while (n % d == 0) {
            p++;
            n /= d;
        }
        if (p)
            cnt++;
        d++;
        if (d * d > n)
            d = n;
    }
    return cnt;
}
bool ok(int a, int b){
    return desc(a) == desc(b);
}
int main(){
    int n, a, b, rez1 = 1000000000, rez2 = 1000000000;
    cin >> n;
    cin >> a;
    for (int i = 2; i <= n; ++i) {
        cin >> b;
        if (ok(a, b) && a + b < rez1 + rez2) {
            rez1 = a;
            rez2 = b;
        }
        a = b;
    }
    if (rez1 != 1000000000)
        cout << rez1 << ' ' << rez2;
    else
        cout << "NU EXISTA";
    return 0;
}
