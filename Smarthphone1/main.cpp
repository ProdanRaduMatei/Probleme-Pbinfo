/*
Cerința
Toată lumea cunoaște modelul de deblocare a telefoanelor sub formă de o tablou cu 3 linii și 3 coloane. Se pot trasa diferite modele de deblocare, dintr-un punct putând merge la oricare vecin al lui. (Sunt maximum 8 vecini de exemplu pentru punctul din mijloc și 3 vecini pentru un punct din colț).



Dacă numerotăm punctele ca mai sus, fiecărui model de deblocare îi corespunde un număr cu cifrele de la 1 la 9, cifrele numărului fiind în ordinea în care sunt parcurse punctele. De exemplu, numărul 98569 și 42536 corespunde unor modele de deblocare, iar numerele 98365 și 1223 nu corespund unor astfel de modele (în numărul 98365 cifrele 8 și 3 nu se învecinează, iar în 1223 cifra 2 apare pe două poziții consecutive).

Dându-se n numere naturale cu toate cifrele nenule, să se determine câte dintre ele corespund unui model de deblocare.

Date de intrare
Fișierul de intrare smartphone1.in conține pe prima linie numărul n, iar pe a doua linie n numere naturale separate prin spații.

Date de ieșire
Fișierul de ieșire smartphone1.out va conține pe prima linie numărul C, reprezentând valoarea cerută.

Restricții și precizări
1 ≤ n ≤ 1000
cele n numere date au cel puțin una și cel mult nouă cifre nenule
în tabloul dat, două cifre se învecinează pe linie, coloană sau diagonală;
Exemplu:
smartphone1.in

4
98569 42536 98365 1223
smartphone1.out

2
*/

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("smartphone1.in");
ofstream fout("smartphone1.out");

int n, a, i, nr = 0;

void verif(int x) {

    int a, xa, ya, b, xb, yb, ok = 1;

    while(x > 9){
        a = x % 100 / 10;
        b = x % 10;
        if(a == b){
            ok = 0;
            break;//daca cif sunt identice atunci e direct invalid
        }
        if(a % 3 == 0) {
            xa = 3;
            ya = a / 3;
        }
        else{
            ya = a / 3 + 1;
            xa = a % 3;//cele 9 numere le consider ca facand parte dint-o matrice patratica de 3x3 si le aflu coordonatele x si y
        }

        if(b % 3 == 0){
            xb = 3;
            yb = b / 3;
        }
        else{
            yb = b / 3 + 1;
            xb = b % 3;
        }
       if(abs(xa - xb) > 1) { //daca diferenta dintre coordonate este mai mare ca 1 inseamna ca nu sunt 1 langa altul, deci invalide
            ok = 0;
            break;
       }
       if(abs(ya - yb) > 1){
            ok = 0;
            break;
       }
        x /= 10;
    }
    if(ok == 1){
        nr++;
    }
}

int main(){
    fin>> n;
    for(i = 1; i <= n; i++) {//citire numere
        fin>> a;
        verif(a);
    }
    fout<< nr;

}