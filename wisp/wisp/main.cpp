#include <bits/stdc++.h>

using namespace std;

ifstream fin("wisp.in");
ofstream fout("wisp.out");

int main() {
    long long int n, k;
    fin >> n >> k;
    unsigned long long int s = 0;
    unsigned long long int nr = 0;
    nr = k;
    s = k;
    if (n % 2 == 0) {
        n--;
        while (n > 1) {
            nr += 2 * n;
            s += nr;
            nr += 2 * n;
            s += nr;
            n -= 2;
        }
        s += nr + 2;
    }
    else {
        n--;
        while (n > 1) {
            nr += 2 * n;
            s += nr;
            nr += 2 * n;
            s += nr;
            n -= 2;
        }
    }
    fout << s;
    return 0;
}
