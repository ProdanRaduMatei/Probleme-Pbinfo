#include <fstream>

#define N 10000000

using namespace std;

int Ciur[N + 1], F[N + 1];

int main() {
    for (int i = 2; i <= N; ++i)
        if (Ciur[i] == 0) {
            Ciur[i] = i;
            for (int j = 2; i * j <= N; ++j)
                Ciur[i * j] = i;
        }
    int n, x, cnt = 0;
    ifstream f("jocprim.in");
    f >> n;
    while (n--) {
        f >> x;
        if (F[Ciur[x]] == 0)
            ++cnt;
        ++F[Ciur[x]];
    }
    f.close();
    ofstream g("jocprim.out");
    g << cnt << '\n';
    for (x = 2; x <= N; ++x)
        if (F[x])
            g << x << ' ' << F[x] << '\n';
    g.close();
    return 0;
}