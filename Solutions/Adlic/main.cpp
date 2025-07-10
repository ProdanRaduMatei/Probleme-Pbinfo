#include <fstream>

using namespace std;

ifstream fin("adlic.in");
ofstream fout("adlic.out");

int v[1000002];

int main() {
    int cerinta;
    fin >> cerinta;
    if (cerinta == 1) {
        int n;
        fin >> n;
        int x, y;
        fin >> x;
        while (fin >> y && y >= x)
            x = y;
        fout << y;
    }
    else {
        int nrClase = 0, n;
        int x, y;
        fin >> n;
        fin >> x;
        v[++nrClase] = x;
        for (int i = 1; i < n; i++) {
            fin >> y;
            if (y < v[nrClase])
                v[++nrClase] = y;
            else {
                int st = 1, dr = nrClase;
                int poz = 0;
                while (st <= dr) {
                    int mij = (st + dr) / 2;
                    if (v[mij] <= y) {
                        poz = mij;
                        dr = mij - 1;
                    }
                    else
                        st = mij + 1;
                }
                if (poz)
                    v[poz] = y;
            }
        }
        fout << nrClase;
    }
}