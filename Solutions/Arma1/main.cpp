/*
În anul 2214 a izbucnit primul război interstelar. Pământul a fost atacat de către n civilizaţii extraterestre, pe care le vom numerota pentru simplicitate de la 1 la n.

Pentru a se apăra, pământenii au inventat o armă specială ce poate fi încărcată cu proiectile de diferite greutăţi, fabricate dintr-un material special denumit narun. Dacă arma este programată la nivelul p, atunci un proiectil de greutate k va ajunge exact la distanţa kp km (k la puterea p) faţă de Pământ şi dacă în acel punct se află cartierul general al unui atacator, acesta va fi distrus. De exemplu, dacă arma este programată la nivelul 2, un proiectil de greutate 10 va distruge cartierul general al extratereştrilor situat la distanţa 102 = 100 km de Pământ.

Arma poate fi încărcată cu proiectile de diferite greutăţi, dar cum narunul este un material foarte rar şi foarte scump, pământenii vor să folosească proiectile cât mai uşoare pentru a distruge cartierele generale inamice.

Cerința
Cunoscându-se n, numărul atacatorilor, precum şi cele n distanţe până la cartierele generale ale acestora, să se scrie un program care determină:

cantitatea minimă de narun necesară pentru a distruge toate cartierele generale inamice;
nivelurile la care trebuie programată arma, pentru a distruge fiecare cartier general inamic cu o cantitate minimă de narun.
Date de intrare
Fișierul de intrare arma1.in conține pe prima linie un număr natural c reprezentând cerinţa care trebuie să fie rezolvată (1 sau 2). Pe cea de a doua linie se află numărul natural n, reprezentând numărul atacatorilor. Pe următoarele n linii se află n numere naturale, câte un număr pe o linie; pe cea de a i-a linie dintre cele n (1≤i≤n) se află distanţa faţă de Pământ a cartierului general al celei de a i-a civilizaţii extraterestre.

Date de ieșire
Dacă cerinţa c=1, atunci pe prima linie a fişierului arma1.out va fi scris un număr natural reprezentând cantitatea minimă de narun necesară distrugerii tuturor cartierelor generale inamice.

Dacă cerinţa este c=2, atunci fişierul de ieşire arma1.out va conţine n linii. Pe a i-a linie (1≤i≤n) se va scrie nivelul la care trebuie programată arma pentru a distruge cartierul general al celei de a i-a civilizaţii extraterestre.

Restricții și precizări
1 ≤ n ≤ 10 000
Distanţele până la cartierele generale inamice sunt numere naturale nenule ≤ 2.000.000.000.
Pentru 50% dintre teste cerinţa este 1.
Exemplul 1:
arma1.in

1
5
100 
97 
625 
40353607 
81
arma1.out

122
Exemplul 2:
arma1.in

2
5
100 
97 
625 
40353607 
81
arma1.out

2 
1 
4 
9 
4
Explicație
Primul cartier general se poate distruge cu un proiectil de greutate 10, programat la nivelul 2, al doilea obiectiv cu un proiectil de greutate 97 programat la nivelul 1, al treilea cu un proiectil de greutate 5 programat la nivelul 4, al patrulea cu un proiectil de greutate 7 programat la nivelul 9, iar ultimul cu un proiectil de greutate 3 programat la nivelul 4.

Cantitatea minimă de narun necesară este 10+97+5+7+3=122.

Nivelurile sunt în ordine: 2 1 4 9 4
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f("arma1.in");
ofstream g("arma1.out");

int n,v[10002],pr[50000],nr,c[50000],opt,niv;//pr - sirul numerelor prime
int fp[50000];//fp[i] - retine nivelul maxim la care trebuie programata arma pt a distuge inamicul i
long long s;//cantitatea minima necesara

void ciur(){
    long long i,j;
    nr = 0;
    pr[++nr] = 2;
    for(i = 3; i <=48000; i = i + 2){
        if(c[i] == 0){
            pr[++nr] = i;
            for(j = i; j*i <= 48000; j = j + 2)
                c[i*j] = 1;
        }
    }
}

int cmmdc(int a, int b){
    int r;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int nivel(int d){//determin cmmdc al puterilor factorilor primi din descompunerea lui d
    int i,rez, p;
    rez = 0;//rezultatul

    for(i = 1; i <= nr && pr[i]*pr[i] <= d;++i){
        p = 0;

        while(d % pr[i] == 0){//cat timp pr[i] este factor prim
            p = p + 1;//cresc puterea
            d = d / pr[i]; //noua valoare
        }
        if(p != 0){//daca pr[i] apare in descompunere
            if(p == 1) return 1; //daca apare la puterea 1 nu mai continui
            else {
                rez = cmmdc(rez,p); //retin cmmdc al puterilor
            }
        }
    }
    if(rez == 0 || d != 1) return 1;//daca e numar prim sau mai avem un factor primnivelul e 1
    else return rez;
}

long long x_la_p(long long x, int p, int d){
    long long y = x, rasp = 1;
    while(p > 1){

        if(p % 2 == 1) rasp = rasp*y;
        y = y * y;
        if(y > d) return d + 1;//daca depasesc d nu mai calculez
        p = p/2;
    }
    return rasp*y;

}
int cant_minim(int d, int p){
    //pentru a determina cantitatea minima trebuie sa determin o valoare x, a.i. x^p = d
    long long x,ls,ld,y;
    if(p == 1) return d;//daca e numar prim

    x = d;
    y = 1;
    //calculez [sqrt(d)]
    while(x > y){
        x = (x + y) / 2;
        y = d / x;
    }

    if(p == 2) return x;//daca e patrat perfect
    ls = 1; ld = x;
    y = x_la_p(x,p,d);
    while(y != d) {

        if(y > d) ld = x;

        if(d > y) ls = x;

        x = ls + (ld - ls)/2;

        y = x_la_p(x,p,d);//calculez x ^ p

    }
   return x;
}

int main()
{
    int i;
    ciur();
    f>>opt>>n;
    for(i = 1; i <= n; ++i) {
            f>>v[i];
            niv = nivel(v[i]);
            fp[i] = niv;
    }
    if(opt == 1){
        s = 0; //initial
        for(i = 1; i <= n; ++i)
            s = s + cant_minim(v[i],fp[i]);
        g<<s;
    }
    if(opt == 2){
        for(i = 1; i <= n; ++i) g<<fp[i]<<"\n";
    }
    return 0;
}