#include <fstream>
#define ull unsigned long long

using namespace std;

ifstream cin("tan.in");
ofstream cout("tan.out");

ull n;
int fr[10];
ull x;
short par, cif_min = 10;
short pare;
int main() {
    cin >> n;
    while (n) {
        fr[n % 10]++;
        if (cif_min > n % 10ull && n % 10ull)
            cif_min = n % 10ull;
        if (par < n % 10ull && (n % 10ull) % 2ull == 0)
            par = n % 10ull;
        if ((n % 10ull) % 2ull == 0)
            pare++;
        n /= 10ull;
    }
    x = x * 10ull + cif_min;
    fr[cif_min]--;
    if (cif_min % 2ull == 0)
        pare--;
    if (!pare)
        x = 0, fr[cif_min]++;
    if (cif_min == par && !fr[par])
        for (int i = 0; i <= 8; i += 2)
            if (fr[i]) {
                par = i;
                break;
            }
    for (int i = 0; i <= 9; i++) {
        if (i == par)
            while (fr[i] > 1) {
                x = x * 10ull + i;
                fr[i]--;
            }
        else
            while (fr[i]) {
                x = x * 10ull + i;
                fr[i]--;
            }
    }
    if (fr[par])
        x = x * 10ull + par;
    cout << x;
}