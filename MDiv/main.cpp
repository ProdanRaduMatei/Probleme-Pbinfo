#include <fstream>
#include <iostream>
#include <climits>

using namespace std;

ifstream fin("mdiv.in");
ofstream fout("mdiv.out");

int f[1000001];
int divs[1000001];

int main() {
    int n, m, x, i, j;
    fin >> n;
    for (i = 0; i < n; ++i) {
        fin >> x;
        f[x]++;
    }
    for (i = 1; i <= 1000000; ++i)
        for (j = i; j <= 1000000; j += i)
            divs[j] += f[i];
    fin >> m;
    while (m--) {
        fin >> x;
        fout << divs[x] << '\n';
    }
}