#include <bits/stdc++.h>
using namespace std;
int zileLuna[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int esteBisect(int an) {
    return (an % 400) == 0 || ( an % 4 == 0 && an % 100 != 0 );
}
void calculeazaData(int &zi, int &luna, int &an, int nr) {
    int nrzileluna, lunacrt = luna;
    if( nr >= 0) {
        nrzileluna = zileLuna[lunacrt];
        if( luna == 2 && esteBisect(an))
            nrzileluna++;
        if( zi + nr > nrzileluna ) {
            nr = nr - nrzileluna + zi;
            zi = nrzileluna;
        }
        while( zi + nr > nrzileluna ) {
            lunacrt = lunacrt + 1;
            if(lunacrt > 12) {
                lunacrt = 1;
                an++;
            }
            nrzileluna = zileLuna[lunacrt];
            if( lunacrt == 2 && esteBisect(an))
                nrzileluna++;
            nr = nr - nrzileluna;
            zi = nrzileluna;
            luna = lunacrt;
        }
        zi = zi + nr;
    }
    else {
        if( zi + nr < 1 ) {
            nr += zi - 1;
            zi = 1;
        }
        while( zi + nr < 1 ) {
            lunacrt = lunacrt - 1;
            if(lunacrt < 1) {
                lunacrt = 12;
                an--;
            }
            nrzileluna = zileLuna[lunacrt];
            if( lunacrt == 2 && esteBisect(an))
                nrzileluna++;
            nr = nr + nrzileluna;
            zi = 1;
            luna = lunacrt;
        }
        zi = zi + nr;
    }
}
int main() {
    int zi, luna, an, nr;
    cin >> zi >> luna >> an >> nr;
    calculeazaData(zi, luna, an, nr);
    cout << zi << ' ' << luna << ' ' << an;
    return 0;
}
