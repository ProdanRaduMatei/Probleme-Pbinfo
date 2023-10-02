#include <fstream>
using namespace std;

int main() {
    int n, poz;
    ifstream fin("beta.in");
    fin >> n >> poz;
    ofstream fout("beta.out");
    if (poz >= 2 * n) {
        fout << -1;
        return 0;
    }
    int dir = 0, len = n;
    while (poz > len) {
        poz -= len;
        dir = 1 - dir;
        len /= 2;
    }
    if (dir == 0)
        fout << n - len + poz;
    else
        fout << n - poz + 1;
    return 0;
}