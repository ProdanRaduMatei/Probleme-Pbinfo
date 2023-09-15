#include <iostream>

using namespace std;

int n, stfin, drfin, a[1001], lmax = 0, l = 1, st = 1, dr = 1, sum, summax;

bool ok(int a, int b) {
    int d = 2;
    while (a > 1) {
        if (a % d == 0) {
            if (b % d != 0)
                return 0;
            else {
                while (a % d == 0)
                    a /= d;
                while (b % d == 0)
                    b /= d;
            }
        }
        d++;
        if (d * d > a)
            d = a;
    }
    return a == b;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int rez1 = -1, rez2 = -1;
    for (int i = 2; i <= n; ++i){
        if (ok(a[i - 1], a[i]) && rez1 + rez2 < a[i - 1] + a[i]){
            rez1 = a[i - 1];
            rez2 = a[i];
        }
    }
    if(rez1 != -1)
        cout << rez1 << ' ' << rez2 << endl;
    else
        cout << "NU EXISTA";
    return 0;
}
