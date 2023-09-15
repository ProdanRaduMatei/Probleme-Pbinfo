#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("qclasa.in");
ofstream fout("qclasa.out");

struct elev{
    int cod, ma, ab;
}e[45];

int main()
{
    int n, nmz = 0, mc = 0;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> e[i].cod >> e[i].ma >> e[i].ab;
        if (e[i].ma == 10)
            ++nmz;
        mc = mc + e[i].ma;
    }
    fout << nmz << endl;
    fout << mc / n << endl;
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (e[i].ab < e[j].ab)
                swap(e[i], e[j]);
            else if (e[i].ab == e[j].ab)
                if (e[i].cod > e[j].cod)
                    swap(e[i], e[j]);
    for (int i = 1; i <= 2; ++i)
        fout << e[i].cod << " " << e[i].ma << " " << e[i].ab << endl;
    return 0;
}
