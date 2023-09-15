#include <bits/stdc++.h>
 
using namespace std;
ifstream fin("numerus.in");
ofstream fout("numerus.out");

long long int n, i, k, a, b, l, c;

int main()
{
    fin >> k >> n;
    a = 5 * (k - 1) + 1;
    b = 5 * k;
    if (k % 2 == 1) {
        for (i = a; i <= b; ++i)
            fout << i << ' ';
        fout << b;
    }
    else {
        fout << b << ' ';
        for (i = b; i >= a; --i)
            fout << i << ' ';
    }
    fout << "\n";
    l = n / 5;
    if (n % 5 != 0)
        ++l;
    fout << l << "\n";
    if (n % 5 == 0)
        if (l % 2 == 0)
            fout << 'A' << ' ' << 'B';
        else
            fout << 'E' << ' ' << 'F';
    else if (l % 2 == 1) {
        char c = 'A' + n % 5 - 1;
        fout << c;
    }
    else {
        char c = 'F' - n % 5 + 1;
        fout << c;
    }
    fout << "\n";
    fin.close();
    fout.close();
    return 0;
}