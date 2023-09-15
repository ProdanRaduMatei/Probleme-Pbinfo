#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("coada2.in");
ofstream fout("coada2.out");

long long x, y, z, t;

int main()
{
    fin >> x >> y >> z;
    if (x >= y || x >= z) {
        fout << -1;
        return 0;
    }
    t = y + z - x;
    fout << ((t < 2) ? -1 : t);
    fin.close();
    fout.close();
    return 0;
}
