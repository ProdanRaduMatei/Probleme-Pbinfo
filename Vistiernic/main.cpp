#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("vistiernic.in");
ofstream fout("vistiernic.out");

int d2, d5, n, nr;

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> nr;
        while (nr % 2 == 0) {
            ++d2;
            nr = nr / 2;
        }
        while (nr % 5 == 0) {
            ++d5;
            nr = nr / 5;
        }
    }
    if (d2 <= d5)
        fout << d2;
    else
        fout << d5;
    return 0;
}
