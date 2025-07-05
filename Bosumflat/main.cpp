/*
Vrăjitorul informatician Arpsod a făcut un farmec asupra unui șir de N numere naturale, fiecare număr având exact 8 cifre (doar vrăjitorul știe de ce a ales cifra 8). În urma farmecului, numerele au început să prindă sentimente. Un număr X se numește bosumflat dacă există un alt număr Y, printre cele N, cu proprietatea că, numărul format din cifrele de pe poziții impare ale lui X este strict mai mic decât numărul format din cifrele de pe poziții pare ale lui Y și numărul format din cifrele de pe poziții pare ale lui X este strict mai mare decât numărul cifrele de pe poziții impare ale lui Y.

Vom defini gradul de bosumflare al unui număr X ca fiind egal cu numărul de numere dintre cele N, care îl bosumflă pe X.

Pentru că vrăjitorul este prea ocupat cu alți bosumflați, vă roagă pe voi să determinați gradul de bosumflare pentru fiecare dintre cele N numere.

Cerința
Cunoscându-se N, numărul de numere precum și numerele efective, determinați gradul de bosumflare pentru fiecare număr în parte.

Date de intrare
Pe prima linie a fișierului bosumflat.in se găsește numărul natural N. Pe cea de-a doua linie se găsesc N numere naturale (nu neapărat distincte), fiecare având exact 8 cifre.

Date de ieșire
Pe prima linie a fișierului bosumflat.out se vor afișa N numere naturale separate prin spațiu cu semnificația că al i-lea număr afișat reprezintă gradul de bosumflare al celui de-al i-lea număr din șirul inițial.

Restricții și precizări
2 ≤ N ≤ 5000
Cele N numere sunt naturale și au exact 8 cifre
Dacă un număr nu este bosumflat atunci acesta are gradul de bosumflare 0.
Se garantează că primele două cifre ale fiecărui număr sunt nenule.
Nu încercați să înțelegeți sentimentele numerelor, deoarece sunt foarte dificile.
Exemplu:
bosumflat.in

5
15629013 29032000 19970808 33331111 86000000
bosumflat.out

3 4 4 3 2
Explicație
Dacă X = 15629013 și Y = 29032000, X este bosumflat de Y deoarece 1691 < 9300 și 5203 > 2020 ( cifrele marcate se găsesc pe poziții pare).
*/

#include <fstream>
using namespace std;

#define Nmax 5002

ifstream fin ( "bosumflat.in" );
ofstream fout ( "bosumflat.out" );

int grad[Nmax];

struct Numar{
    int impar, par;
}v[Nmax];

int Par ( int x ){
    return x / 1000000 % 10 * 1000 + x / 10000 % 10 * 100 + x / 100 % 10 * 10 + x % 10;
}

int Impar ( int x ){
    return x / 10000000 % 10 * 1000 + x / 100000 % 10 * 100 + x / 1000 % 10 * 10 + x / 10 % 10;
}

bool Bosumflat ( int x, int y ){
    return ( v[x].impar < v[y].par && v[x].par > v[y].impar );
}

int main(){

    int N, x;

    fin >> N;

    for ( int i = 1; i <= N; ++i ){
        fin >> x;
        v[i].par = Par (x);
        v[i].impar = Impar (x);
    }

    for ( int i = 1; i < N; ++i )
        for ( int j = i+1; j <= N; ++j )
            {
                grad[i] += Bosumflat ( i, j );
                grad[j] += Bosumflat ( j, i );
            }


    for ( int i = 1; i <= N; ++i )
        fout << grad[i] << " ";

}