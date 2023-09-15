#include <fstream>

using namespace std;

ifstream fin("pesti.in");
ofstream fout("pesti.out");

int main() {
    int n, z, g2, i, s, r, nr = 0, G;
    long long g1, k;
    char L;
    fin >> n >> G >> z;
    k = G;
    s = z / 7;
    r = z % 7;
    for (i = 1; i <= n; i++) {
        fin >> L >> g1 >> g2;
        g1 = g1 + z * g2;
        if (g1 >= k) {
            fout << g1 << ' ' << L << '\n';
            nr++;
        }
    }
    if (nr == 0)
        fout<<0;
    fout.close();
    fin.close();
    return 0;
}