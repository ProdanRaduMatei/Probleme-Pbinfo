#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("gradina.in");
ofstream fout("gradina.out");
int main()
{
    int n, k, p, i = 0, j = 0, cnt, Lin[1000], Col[1000], l = 0, c = 0, lin, col, m, g[1000][1000];
    fin >> n >> p >> k;
    for (cnt = 0; cnt < p; cnt = cnt + 2, ++i, ++j) {
        fin >> Lin[i] >> Col[j];
        if (k == 1) {
            fout << "1" << endl << p;
            return 0;
        }
        else {
            l = Lin[i];
            c = Col[j];
            g[l][c] = 1;

        }
    }
    return 0;
}
