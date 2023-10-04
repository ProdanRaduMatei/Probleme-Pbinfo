#include <fstream>
#include <climits>
#include <iostream>

using namespace std;

ifstream fin ("graffiti.in");
ofstream fout ("graffiti.out");

const int nMAX = 100e3;
const int lognMAX = 16;

int n;
int inal[nMAX + 1];
int lung[nMAX + 1];
long long spLung[nMAX + 1];
int rmq[nMAX + 1][lognMAX + 1];

int log2(int x) {
    return 31 - __builtin_clz(x);
}

void buildRMQ() {
    int i, j;
    for (i = 1; i <= n; ++i)
        rmq[i][0] = inal[i];
    for (j = 1; (1<<j) <= n; ++j)
        for (i = 1; i + (1<<j) - 1 <= n; ++i)
            rmq[i][j] = std::min(rmq[i][j - 1], rmq[i + (1<<(j - 1))][j - 1]);
}

int queryRMQ(int x, int y) {
    int j = log2(y - x + 1);
    return std::min(rmq[x][j], rmq[y - (1<<j) + 1][j]);
}

int main() {
    int q, i, x, y;
    fin >> n;
    for (i = 1; i <= n; ++i) {
        fin >> lung[i] >> inal[i];
        spLung[i] = spLung[i - 1] + lung[i];
    }
    buildRMQ();
    fin >> q;
    for (i = 1; i <= q; ++i) {
        fin >> x >> y;
        fout << queryRMQ(x, y) * (spLung[y] - spLung[x - 1]) << '\n';
    }
}