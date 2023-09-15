#include <fstream>

using namespace std;

ifstream fin("vterminal.in");
ofstream fout("vterminal.out");

bool prim(int x);
int n;

int main()
{
    fin >> n;
    int x, s = 0, k;
    for (int i = 1; i <= n; ++i) {
        fin >> x;
        if (prim(x))
            s = s + x;
    }
    while (true) {
        k = 0;
        while (s != 0) {
            k = k + s % 10;
            s = s / 10;
        }
        s = k;
        if (k < 10)
            break;
    }
    fout << k;
    return 0;
}

bool prim(int x) {
    if (x < 2)
        return 0;
    if (x == 2)
        return 1;
    if (x % 2 == 0)
        return 0;
    for (int i = 3; i * i <= x; i = i + 2)
        if (x % i == 0)
            return 0;
    return 1;
}
