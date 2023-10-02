#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sminus.in");
ofstream fout("sminus.out");

int a[100000];

int main(void) {
    int n, i, sum = 0, smax = 0, s = 0, left = 0, right = 0, pi = 0, pj = 0;
    fin >> n;
    for (i = 0; i < n; i++)
        fin >> a[i];
    for (right = 0; right < n; right++) {
        s += a[right];
        if (s < 0)
            s = 0, left = right + 1;
        if (s >= smax)
            smax = s, pi = left, pj = right;
    }
    for (i = pi; i <= pj; i++)
        a[i] *= -1;
    for (i = 0; i < n; i++)
        sum += a[i];
    fout << pi + 1 << ' ' << pj + 1 << endl << sum;
    return 0;
}