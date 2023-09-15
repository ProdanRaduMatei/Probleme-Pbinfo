#include <iostream>
#include <fstream>

using namespace std;

ifstream f("secventeneuniforme.in");
ofstream g("secventeneuniforme.out");

int secv, secvmax, cif, a,b,c;

bool diferite(int x, int y, int z) {
    return (x != y && x != z && y != z);
}

int main() {
    f >> a >> b >> c;
    if (diferite(a, b, c)) {
        secv = 3;
        secvmax = 3;
    }
    while (f >> cif) {
        a = b;
        b = c;
        c = cif;
        if (diferite(a, b, c))
            if (secv == 0)
                secv = 3;
            else
                ++secv;
        else {
            if (secv > secvmax)
                secvmax = secv;
            secv=0;
        }
    }
    if (secv > secvmax)
        secvmax = secv;
    g << secvmax;
}
