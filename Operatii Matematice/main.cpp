#include <bits/stdc++.h>
 
using namespace std;

ifstream fin("operatiimatematice.in");
ofstream fout("operatiimatematice.out");

int main()
{
    int n, v[101];
    fin >> n ;
    int first;
    fin >> first;
    int calc1, calc2, var;
    for (int i = 2; i < n; ++i) {
        fin >> var;
        calc1 = first * 3 + var;
        first = calc1 - (calc1 / 7) * 7;
    }
    fin >> var;
    first = first * 3 + var;
    fout << first << "\n";
    if (first % 7 == 0)
        fout << "DA";
    else
        fout << "NU";
    return 0;
}