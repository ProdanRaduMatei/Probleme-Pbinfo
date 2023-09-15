/*
La ora de matematică Georgică a învăţat o nouă operaţie: ridicarea la putere. În timpul orei de informatică aprofundează această noţiune considerând două numere naturale m şi n, cu acelaşi număr de cifre şi calculând:

a) puterea p = ab , unde a este ultima cifră a lui m, iar b este ultima cifră a lui n;
b) suma s a tuturor puterilor de forma xy, unde x şi y sunt cifre din m, respectiv n de pe aceeaşi poziţie. De exemplu pentru m=624 şi n=253, se va calcula s= 43 + 25 + 62 şi se obţine s=132.

Cerinţă
Scrieţi un program, care pentru două numere naturale date m şi n determină:

a) puterea p definită în enunţ;
b) suma s definită în enunţ.

Date de intrare
Fişierul de intrare putere.in conţine pe prima linie numerele m şi n, separate între ele printr-un spaţiu.

Date de ieşire
Fişierul de ieşire putere.out va conţine, pe prima linie p şi pe a doua linie s.

Restricţii şi precizări
0 <m,n< 2000000001
Toate cifrele lui n sunt nenule.
m şi n au acelaşi număr de cifre.
Exemplu
putere.in

624 253
putere.out

64
132	
Explicaţie
m=624, n=253.
p= 43 , adică p=64 s= 43 + 25 + 62 , adică s=132.
*/

#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

ifstream fin("putere.in");
ofstream fout("putere.out");

int main() {
    int m, n, s = 0, p;
    fin >> m >> n;
    p = pow(m % 10, n % 10);
    while(m) {
        s += pow(m % 10, n % 10);
        m /= 10;
        n /= 10;
    }
    fout << p << endl << s;
}