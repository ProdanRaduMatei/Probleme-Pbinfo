#include <fstream>
using namespace std;

int main() {
    ifstream fin ("culori.in");
    ofstream fout ("culori.out");
    int cerinta, dimen, pasi, a, posibil, raspuns;
    fin >> cerinta;
    if (cerinta == 1) {
        fin >> dimen >> dimen >> pasi >> a;
        dimen--;
        posibil = 0,  raspuns = 0;
        while (dimen--) {
            fin >> pasi;
            if (a == pasi)
                posibil++;
            else {
                if (posibil > raspuns)
                    raspuns = posibil;
                posibil = 1;
            }
            a = pasi;
        }
        fout << raspuns;
    }
    else {
        fin >> cerinta >> dimen >> pasi;
        int v[dimen], mars[dimen+1];
        for (a = 0; a < dimen; ++a) {
            fin >> v[a];
            mars[a] = 0;
        }
        while (pasi--) {
            fin >> posibil >> raspuns >> cerinta;
            mars[posibil-1] += cerinta;
            mars[raspuns] -= cerinta;
        }
        cerinta = 0;
        for (a = 0; a < dimen; ++a) {
            cerinta += mars[a];
            fout << v[a] + cerinta << ' ';
        }
    }
    return 0;
}