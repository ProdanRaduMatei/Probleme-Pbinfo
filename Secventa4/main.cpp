#include <bits/stdc++.h>

using namespace std;

const string file="secventa4";

ifstream fin(file + ".in");
ofstream fout(file + ".out");

vector <int>v;
int n, x, k, maxi, pmax;

int main() {
    fin>>n;
    v.push_back(0);
    fin>>x;
        v.push_back(x);
    for (int i = 2; i <= n; ++i) {
        fin >> x;
        v.push_back(x);
        if (v[i - 1] % 10 == x % 10)
            k++;
        else
            k = 0;
        if (k > maxi) {
            maxi = k;
            pmax = i;
        }
    }
    fout << pmax - maxi << ' ' << pmax;
    return 0;
}