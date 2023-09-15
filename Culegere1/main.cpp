#include <bits/stdc++.h>
 
using namespace std;
ifstream fin("culegere.in");
ofstream fout("culegere.out");



int main()
{
    long long int p, n, t = 0, m = 1, problems = 0, i;
    fin >> p >> n;
    problems = p * (p + 1) / 2;
    for (i = 1; i < problems; i *= 10)
        t += (problems - i + 1);
    fout << t << "\n";
    while (m * (m + 1) / 2 < n)
        ++m;
    fout << m;
    return 0;
}