/*
Gina şi Mihai joacă împreună jocul Cuart. Ei au la dispoziție un șir de 2*N cartonașe ce conțin numere naturale. Primele N cartonașe, de la stânga la dreapta, sunt ale Ginei, iar următoarele N ale lui Mihai. Gina traversează șirul, de la stânga la dreapta și scrie pe o foaie de hârtie, pe primul rând, un șir de numere obținut din numerele de pe cartonașele sale, din care a șters toate cifrele pare. La fel procedează Mihai care scrie pe foaia sa de hârtie, pe primul rând, șirul de numere obținut din numerele de pe cartonașele sale, din care a șters toate cifrele impare. Dacă dintr-un număr s-au șters toate cifrele, sau au rămas doar cifre egale cu 0, atunci numărul este ignorat, deci pe hârtie nu se scrie nimic.
Fiecare copil, notează pe hârtia sa, pe al doilea rând, un alt șir de numere obținut astfel: pentru fiecare număr X scris pe primul rând, copilul va scrie cel mai mare număr natural K cu proprietatea că 1+5+9+13+...+ K ≤ X. În jocul copiilor, numărul X se numește cuarț dacă 1+5+9+13+...+K = X.



În exemplul de mai sus, Gina nu a scris niciun număr cuarț pe primul rând, iar Mihai a scris unul singur (6=1+5).

Regulile de câștig ale jocului sunt următoarele:

Câștigă acel copil care are scrise pe primul rând cele mai multe numere cuarț. În acest caz, valoarea de câștig a jocului este egală cu numărul de numere cuarț scrise de copilul câștigător.
Dacă cei doi copii au scris același număr de numere cuarț, atunci va câștiga cel care are primul număr scris pe primul rând, mai mare decât al celuilalt. Acest prim număr scris de câștigător va reprezenta valoarea de câștig.
Dacă nici Gina și nici Mihai nu au scris niciun număr pe hârtie, se consideră egalitate și nu câștigă niciunul.
Cerinţe
Scrieţi un program care să citească numărul N reprezentând numărul de cartonașe ale unui copil şi cele 2*N numere de pe cartonașe, în ordine de la stânga la dreapta și care să determine:

1) Cel mai mare număr de pe cele 2*N catonașe, pentru care nu s-a scris niciun număr pe primul rând (a fost omis), nici pe hârtia Ginei, nici pe hârtia lui Mihai; dacă nu a fost omis niciun număr, se va scrie 0;
2) Câștigătorul jocului și afișează numărul 1 dacă a câștigat Gina, 2 pentru Mihai sau 0 în caz de egalitate.
3) Valoarea de câștig a jocului, sau 0, în caz de egalitate.

Date de intrare
Fișierul de intrare cuart.in conține pe prima linie un număr natural P. Pentru toate testele de intrare, numărul P poate avea doar valoarea 1, valoarea 2 sau valoarea 3. Pe a doua linie a fișierului de intrare cuart.in se găsește numărul natural N reprezentând numărul de cartonașe ale fiecărui copil și pe a treia linie, în ordine de la stânga la dreapta, numerele de pe cele 2*N cartonașe, separate prin câte un spațiu.

Date de ieșire
Dacă valoarea lui P este 1, se va rezolva numai punctul 1) din cerințe. În acest caz, fişierul de ieşire cuart.out va conține pe prima linie un număr natural reprezentând răspunsul la cerinţa 1).

Dacă valoarea lui P este 2, se va rezolva numai punctul 2) din cerințe. În acest caz, fişierul de ieşire cuart.out va conține pe prima linie un număr natural reprezentând răspunsul la cerinţa 2).

Dacă valoarea lui P este 3, se va rezolva numai punctul 3) din cerințe. În acest caz, fişierul de ieşire cuart.out va conține pe prima linie un număr natural reprezentând răspunsul la cerinţa 3).

Restricții și precizări
1 ≤ N ≤ 1000
1 ≤ numerele de pe cartonașe < 100.000.000
Pentru rezolvarea corectă a primei cerinţe se acordă 20 de puncte, pentru rezolvarea corectă a celei de a doua cerințe se acordă 30 de puncte, pentru rezolvarea corectă a celei de a treia cerințe se acordă 50 de puncte.
Exemplul 1
cuart.in

1
4
1234 48 284260 75 756 1232515 153 98
cuart.out

284260
Explicație
P = 1, pentru acest test, se rezolvă cerința 1).

Gina a scris pe hârtia sa, pe două rânduri numerele:

13 75
 5 21
Mihai a scris pe hârtie numerele:

6 22 8
5 9  5
Cel mai mare număr omis este 284260

Exemplul 2
cuart.in

2
4
1234 48 284260 75 756 1232515 153 98
cuart.out

2
Explicație
P = 2, pentru acest test, se rezolvă cerința 2).

A câștigat Mihai deoarece are un număr cuarț, iar Gina niciunul

Exemplul 3
cuart.in

3
1
154 2181
cuart.out

28
Explicație
P = 3, pentru acest test, se rezolvă cerința 3).

Gina a scris pe hârtia sa, pe două rânduri numerele:

15
9
Mihai a scris pe hârtie numerele:

28
13
Ambii copii au scris câte un număr cuarț, însă a câștigat Mihai care are primul număr scris pe primul rând mai mare decât al Ginei. Valoarea de câștig a jocului este 28.
*/

#include <fstream>

using namespace std;

ifstream fin("cuart.in");
ofstream fout("cuart.out");

int P, N, g1, m1, n9, n8;

int stergePare(int x)
{
    int p = 1, rez = 0;
    while (x)
    {
        if (x%2==1)
        {
            rez = x%10*p+rez;
            p*=10;
        }
        x/=10;
    }
    return rez;
}

int stergeImpare(int x)
{
    int p = 1, rez = 0;
    while (x)
    {
        if (x%2==0)
        {
            rez = x%10*p+rez;
            p*=10;
        }
        x/=10;
    }
    return rez;
}

void Cuart(int x, int &k, int &sum)
{
    k = 1, sum = 0;

    while (sum<x)
    {
        sum+=k;
        k+=4;
    }
}

int main()
{
    fin>>P>>N;

    int GMax=0, MMax = 0, nrCG = 0, nrCM = 0;

    for (int i=1; i<=N; i++)
    {
        int x, y;
        fin>>x;

        if (i==1) g1=x;
        y = stergePare(x);
        if (y==0)
        {
            if (x>GMax)
                GMax = x;
        }
        else
        {
            int z, sum;
            Cuart(y, z, sum);
            if (sum==y) nrCG++;
        }
    }

    for (int i=1; i<=N; i++)
    {
        int x, y;
        fin>>x;
        if (i==1) m1=x;
        y = stergeImpare(x);
        if (y==0)
        {
            if (x>MMax)
                MMax = x;
        }
        else
        {
            int z, sum;
            Cuart(y, z, sum);
            if (sum==y) nrCM++;
        }
    }

    if (P==1)
    {

        fout<<max(GMax, MMax);
    }
    else if (P==2)
    {
        if (nrCM==0 && nrCG==0) fout<<0;
        else if (nrCM==nrCG)
        {
            if (g1>m1) fout<<1;
            else fout<<2;
        }
        else if (nrCG>nrCM) fout<<1;
        else fout<<2;
    }
    else if (P==3)
    {
        if (g1==99999999) fout<<g1;
        else 
        if (nrCM==0 && nrCG==0) fout<<0;
        else if (nrCM==nrCG)
        {
            int r1,t1, r2, t2;
            Cuart(g1, r1, t1);
            Cuart(m1, r2, t2);
            if (r1>r2) fout<<g1;
            else fout<<m1;
        }
        else if (nrCG>nrCM) fout<<nrCG;
        else fout<<nrCM;
    }
}