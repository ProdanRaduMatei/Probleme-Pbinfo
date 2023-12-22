#include <fstream>

using namespace std;

int n, x, p[10001], i, c, j, lmax, u[10001];
ifstream fin("numere.in");
ofstream fout("numere.out");
int prim(int x) {
    int i;
    if (x <= 1)
        return 0;
    for (i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}

int main() {
    fin >> n >> c;
    if (c == 1) {
        for (i = 1; i <= n; i++) {
            fin >> x;
            if (prim(x) == 0) {
                for (j = x / 2; j >= 2; j--)
                    if (x % j == 0 && prim(j) == 1) {
                        x = j;
                        break;
                    }
            }
            if (p[x] == 0)
                p[x] = u[x] = i;
            else
                u[x] = i;
        }
        for (i = 2; i <= 10000; i++)
            if (u[i] - p[i] + 1 > lmax)
                lmax = u[i] - p[i] + 1;
        fout << lmax;
    }
    else {
        for (i = 1; i <= n; i++) {
            fin >> x;
            if (prim(x) == 0) {
                for (j = x / 2; j >= 2; j--)
                    if (x % j == 0 && prim(j) == 1) {
                        x = j;
                        break;
                    }
            }
            p[x]++;
        }
        int s = 0;
        for (i = 2; i <= 10000; i++)
            s = s + p[i] * (p[i] - 1) / 2;
        fout << s;
    }
    return 0;
}