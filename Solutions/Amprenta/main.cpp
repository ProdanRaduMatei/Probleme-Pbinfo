#include<bits/stdc++.h>

using namespace std;

ifstream fin("amprenta.in");
ofstream fout("amprenta.out");

long long cerinta, n, p, q, r, sol;

int main()
{
    fin >> cerinta;
    if (cerinta == 1) {
        fin >> n;
        if (n % 11 >= 6)
            fout << 11 - n % 11 << '\n';
        else
            fout << n % 11 << '\n';
    }
    else{
        fin >> p >> q >> r;
        if (p > q)
            swap(p, q);
        while (p % 11 != 0 && p <= q) {
            if (p % 11 == r || 11 - p % 11 == r)
                sol++;
            p++;
        }
        while (q % 11 != 0 && q >= p) {
            if (q % 11 == r || 11 - q % 11 == r)
                sol++;
            q--;
        }
        if (p <= q) {
            if (r == 0)
                sol += q / 11 - p / 11 + 1;
            else
                sol += 2 * (q / 11 - p / 11);
        }
        fout << sol << '\n';
    }
    return 0;
}