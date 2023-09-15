#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("sume2.in");
ofstream fout("sume2.out");
int main() {
    int n, m, v[100000], c, i, f, k, a = 0, b = 0, s;
    fin >> n;
    for (c = 1; c <= n; ++c)
        fin >> v[c];
    fin >> m;
    for (k = 1; k <= m; ++k) {
        fin >> i >> f;
        s = 0;
        for (a = i; a <= f; ++a) {
            s = s + v[a];
        }
        fout << s << endl;
    }
    return 0;
}
