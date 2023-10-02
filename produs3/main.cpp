#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("produs3.in");
ofstream fout("produs3.out");

int f[1001];

static int intlg(int n, int x) {
    int c = 0;
    while (n % x == 0) {
        n /= x;
        c++;
    }
    return c;
}


int main(void) {
    int n, c2 = 0, c3 = 0, c5 = 0, x , i;
    unsigned long long c = 0;
    fin >> n;
    for (i = 0; i < n; i++) {
        fin >> x;
        c2 = (c2 + intlg(x, 2)) % 2;
        c3 = (c3 + intlg(x, 3)) % 2;
        c5 = (c5 + intlg(x, 5)) % 2;
        f[4 * c2 + 2 * c3 + c5]++;
    }
    c = f[0];
    for (i = 0; i <= 10; i++)
        c += (1LL * f[i] * (f[i] - 1) / 2);
    fout << c;
    return 0;
}