/*
Cerinţă
Să se scrie un program care citește un număr natural și determină câte cifre ale numărului sunt mai mari decât a doua sa cifră.

Date de intrare
Programul va citi de la tastatură un număr natural.

Date de ieşire
Programul va afişa pe ecran valoarea cerută.

Restricţii şi precizări
numărul citit va fi mai mic decât 2.000.000.000 și mai mare decât 9
Exemplu:
Intrare

32615
Ieşire

3
Explicație
A doua cifră a numărului dat este 2. În număr sunt trei cifre mai mari decât 2.
*/

#include <iostream>
using namespace std;
int main() {
    int n, nc, cif2_n = 0, nr = 0;
    cin >> n;
    nc = n;
    while(nc>9) {
        cif2_n = nc%10;
        nc /= 10;
    } while(n!=0) {
        if(n%10 >  cif2_n)
            nr++;
        n /= 10;
    }
    cout << nr;
}