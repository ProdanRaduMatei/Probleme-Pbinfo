#include <fstream>

using namespace std;

ifstream fin("palindromsd.in");
ofstream fout("palindromsd.out");

bool epal(int nr) {
    if (nr < 10)
        return true;
    int rasturnat = 0, numar = nr;
    while (numar > 0) {
        rasturnat = rasturnat * 10 + numar % 10;
        numar = numar / 10;
    }
    if (rasturnat == nr)
        return true;
    else
        return false;
}

int main()
{
    int pal[1001], n = 0, nr;
    while (fin >> nr) {
        if (epal(nr))
            pal[++n] = nr;
    }
    if (n == 0)
        fout << -1;
    else {
        for (int i = 1; i <= n / 2; ++i)
            fout << pal[i] << " " << pal[n - i + 1] << " ";
    }
    if (n % 2 == 1)
        fout << pal[n / 2 + 1];
    return 0;
}
