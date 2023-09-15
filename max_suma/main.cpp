#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("max_suma.in");
ofstream fout("max_suma.out");

int main()
{
    int n, m, M = 0, s = 0, x;
    fin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        s = 0;
        M = 0;
        for (int j = 1; j <= m; ++j) {
            fin >> x;
            if (x > M)
                M = x;
            s = s + x;
        }
        fout << M << " " << s << endl;
    }
    return 0;
}
