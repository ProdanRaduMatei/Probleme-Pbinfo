#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("blackfriday.in");
ofstream fout("blackfriday.out");

int main()
{
    int n, ibf[11], dbf[11], p[11], pm = 0, o;
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> ibf[i];
    for (int i = 1; i <= n; ++i)
        fin >> dbf[i];
    for (int i = 1; i <= n; ++i) {
        p[i] = (100 * dbf[i]) / ibf[i];
        if (100 - p[i] > pm) {
            pm = 100 - p[i];
            o = i;
        }
    }
    fout << o;
    return 0;
}
