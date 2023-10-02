#include <bits/stdc++.h>

using namespace std;

const string file="secventa3";

ifstream fin(file + ".in");
ofstream fout(file + ".out");

vector <int>v;
int n, x, k, maxi, pmax;

int main() {
    fin >> n;
    v.push_back(0);
    fin >> x;
        v.push_back(x);
    for (int i = 2; i <= n; ++i) {
        fin >> x;
        v.push_back(x);
        if (v[i - 1] % 2 != x % 2)
            k++;
        else
            k = 0;
        if (k >= maxi) {
            maxi = k;
            pmax = i;
        }
    }
    fout << pmax - maxi << ' ' << pmax;
    return 0;
}