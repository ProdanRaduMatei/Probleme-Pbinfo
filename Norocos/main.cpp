#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

int count_lucky(int n) {
    int d = 2, count = 0, p;
    while (n > 1) {
        p = 0;
        while (n % d == 0) {
            ++p;
            n /= d;
        }
        if (p == 1)
            ++count;
        else if (p > 1)
            return 0;
        ++d;
        if (d * d > n)
            d = n;
    }
    return count;
}

int main() {
    int c, n, k, i, minim = INT_MAX, maxim = INT_MIN, count = 0;
    int v[1000];
    ifstream fin("norocos.in");
    ofstream fout("norocos.out");
    fin >> c;
    fin >> n >> k;
    for (int i = 0; i < n; ++i)
        fin >> v[i];
    if (c == 1) {
        for (i = 0; i < n; ++i)
            if (v[i] % 2) {
                ++count;
                minim = min(minim, v[i]);
                maxim = max(maxim, v[i]);
            }
        if (count)
            fout << minim << " " << maxim;
        else
            fout << 0;
    }
    else {
        for (i = 0; i < n; ++i)
            if (count_lucky(v[i]) == k)
                count++;
        fout << count;
    }
    return 0;
}
