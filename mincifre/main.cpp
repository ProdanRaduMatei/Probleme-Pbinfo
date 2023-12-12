#include <fstream>
#include <bits/stdc++.h>
#include <climits>

using namespace std;

ifstream fin("mincifre.in");
ofstream fout("mincifre.out");

int v[15];
bool ok;

int main() {
    char n;
    int c = 0, cif, i = 0;
    while (fin >> n) {
        v[int(n) - 48]++;
        c++;
    }
    cif = c;
    while (cif) {
        i = 0;
        while (v[i] == 0 && i < 10)
            i++;
        if (i == 10 && cif == c) {
            ++i;
            while (v[i] == 0 && i < 10)
                i++;
        }
        v[i]--;
        fout << i;
        cif--;
    }
    return 0;
}