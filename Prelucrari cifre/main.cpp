#include <iostream>

using namespace std;

int main()
{
    int n, sp = 0, simp = 0, sdiv = 0, smari = 0, pcn = 1, ss, u, z;
    cin >> n;
    u = n % 10;
    while (n) {
        sp = sp + (n % 10) * (n % 10);
        if ((n % 10) % 2 == 1)
            simp = simp + n % 10;
        if ((n % 10) % 3 == 0)
            sdiv = sdiv + n % 10;
        if (n % 10 > 5)
            ++smari;
        if (n % 10 != 0)
            pcn = pcn * (n % 10);
        z = n % 10;
        n = n / 10;
    }
    ss = u + z;
    cout << sp << " " << simp << " " << sdiv << " " << smari << " " << pcn << " " << ss;
    return 0;
}
