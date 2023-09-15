#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("diferenta.in");
ofstream fout("diferenta.out");

int main()
{
    int n, m, x;
    fin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            fin >> x;
            if (x % 2 == 1)
                fout << 1 << " ";
            else {
                if ((x / 2) % 2 == 0)
                    fout << 1 << " ";
                else
                    fout << 0 << " ";
            }
        }
        fout << endl;
    }
    return 0;
}
