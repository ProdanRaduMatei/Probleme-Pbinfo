#include <fstream>

using namespace std;

ifstream fin("gcd.in");
ofstream fout("gcd.out");

bool fr1[1000001], fr2[1000001];
int n, x;

void read() {
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> x;
        fr1[x] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        fin >> x;
        fr2[x] = 1;
    }
}

void solve() {
    int d = 1000000, maxi = -1;
    bool ok1 = 0, ok2 = 0;
    short exista = 0;
    while (d) {
        exista = 0;
        ok1 = 0;
        ok2 = 0;
        for (int i = 1; i * d <= 1000000; ++i) {
            if (fr1[i * d] && !ok1) {
                ok1 = 1;
                ++exista;
            }
            if (fr2[i * d] && !ok2) {
                ok2 = 1;
                ++exista;
            }
            if (exista == 2)
                break;
        }
        if (maxi < d && exista == 2)
            maxi = d;
        --d;
    }
    fout << maxi;
}

int main() {
    read();
    solve();
    return 0;
}