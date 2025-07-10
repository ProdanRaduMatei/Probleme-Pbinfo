#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("eureni.in");
ofstream fout("eureni.out");

long long s, n, e, b[11], t;

int main()
{
    fin >> s >> n >> e;
    b[1] = 1;
    for (int i = 2; i <= n; ++i)
        b[i] = b[i - 1] * e;
    for (int i = n; i > 0; --i) {
        int c = 0;
        while (s - b[i] >= 0) {
            s = s - b[i];
            ++c;
        }
        if (c > 0)
            fout << b[i] << " " << c << endl;
        t = t + c;
    }
    fout << t;
    return 0;
}
