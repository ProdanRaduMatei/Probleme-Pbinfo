/*
Păcală a împrumutat fiecărei persoane din satul lui un număr de monezi de aur. Unele persoane sunt credule și Păcală, șiret fiind, doar acestora le-a împrumutat un număr de monezi care, scris invers, este număr prim. Mai târziu, când Păcală vrea să își recupereze banii, persoanelor credule le cere cu s monede mai mult decât le-a împrumutat. Unii săteni creduli sunt prieteni cu primarul și numărul care indică suma de bani împrumutată de ei conține cifra c. Aceste persoane știu de vicleșugul lui Păcală și ei, pentru a nu-l denunța la poliție, îi returnează acestuia cu s monede mai puține decât au primit.

Cerința
Cunoscându-se numărul n de săteni, cele n valori reprezentând numărul de monede pe care Păcală le-a împrumutat fiecăruia, cifra c și numărul s, se cere să se afișeze:
a) numărul de bani împrumutaţi fiecărui sătean care este prieten cu primarul
b) numărul persoanelor credule și răspunsul la întrebarea dacă Păcală a câștigat monezi în plus față de cele împrumutate: dacă da, se va afișa pe ecran valoarea 1; dacă nu se va câștiga nimic în plus și nici nu va pierde nimic se va afișa valoarea 0, iar dacă va pierde monezi față de cele împrumutate se va afișa valoarea -1.

Date de intrare
Fișierul de intrare pozne.in conține pe prima linie numărul p. Dacă p este egal cu 1, în fișierul pozne.out se va afișa doar cerința de la punctul a), iar dacă p este egal cu 2, în fișierul pozne.out se va afișa doar cerința de la punctul b).

A doua linie conține numerele n s c, în această ordine, iar a treia linie conține n valori, reprezentând numărul de monezi împrumutate de Păcală sătenilor.

Date de ieșire
Fișierul de ieșire pozne.out conţine o singură linie pe care se va afișa:
- pentru cerința a), un şir de numere, separate prin spații, fiecare număr reprezentând numărul de monezi împrumutate unui sătean care este prieten cu primarul (în ordinea în care apar aceste numere în fişierul de intrare).
- pentru cerința b), două numere cu spațiu între ele cu semnificația din enunț.

Restricții și precizări
0 < n ≤ 1000; 0 < s ≤ 500000; 0 ≤ c ≤ 9
0 < numărul monezilor împrumutate de fiecare sătean ≤ 999999
Se garantează că in șir există cel puțin un număr care, scris invers, este număr prim.
Exemplul 1
pozne.in

1
7 15 3
121 31 50 33 821 23 91
pozne.out

31 33 23
Explicație
Fiecare din cele trei numere conține cifra c (în cazul nostru 3).

Exemplul 2
pozne.in

2
7 15 3
121 31 50 33 821 23 91
pozne.out

3 1
Explicație
Se afișează 3 deoarece 31, 50 și 91, scrise invers, sunt numere prime:

31 -> 13
50 -> 5
91 -> 19
și 1 deoarece din cele 3 numere doar de la unu Păcală pierde monezi și de la celelalte 2 persoane câștigă monezi. Deci, prin vicleșug, Păcală câștigă mai mulți bani decât pierde:

31 conține cifra c ( -s=-15)
50 nu conține cifra c (+s=+15)
91 nu conține cifra c (+s=+15)
*/

#include <fstream>

using namespace std;

int n, s, c, cerinta;
ifstream fin("pozne.in");
ofstream fout("pozne.out");

int exista(int x, int c)
{
    int ok=0;
    if (x==0 && x==0) return 1;
    while (x && !ok)
    {
        if (x%10==c) return 1;
        x/=10;
    }
    return 0;
}

int oglindit(int x)
{
    int y = 0;
    while (x)
    {
        y = y*10+x%10;
        x/=10;
    }
    return y;
}

int estePrim (int n)
{
    if (n<2) return 0;
    if (n==2) return 1;
    if (n%2==0) return 0;
    int d = 3;
    while (d<=n/2)
    {
        if (n%d==0) return 0;
        d=d+2;
    }
    return 1;
}

int main()
{
    fin>>cerinta;
    if (cerinta==1)
    {
        fin>>n>>s>>c;

        for (int i=1; i<=n; i++)
        {
            int x;
            fin>>x;
            if (exista(x,c)) fout<<x<<" ";
        }
    }
    else if (cerinta==2)
    {
        int num=0, st=0;
        fin>>n>>s>>c;
        for (int i=1; i<=n; i++)
        {
            int x, y;
            fin>>x;
            y = oglindit(x);
            if (estePrim(y))
            {
                num++;
                if(exista(x, c)) st-=s;
                else st+=s;
            }
        }
        fout<<num<<" ";
        if (st>0) fout<<1;
        else if (st<0) fout<<-1;
        else fout<<0;
    }
}