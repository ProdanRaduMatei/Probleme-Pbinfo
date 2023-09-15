/*
O companie aeriană are planificate N zboruri. Fiecare zbor are asociate câte șase numere naturale cu următoarea semnificație: primul număr A1 identifică aeroportul de decolare, cel de-al doilea număr A2 identifică aeroportul de aterizare, următoarele patru numere naturale H1, M1, H2 și M2, reprezintă în ordine ora și minutul decolării, respectiv ora și minutul aterizării. Aterizarea poate să fie în ziua curentă sau în ziua următoare. Un zbor poate să dureze maximum 23 de ore și 59 de minute. De exemplu, pentru H1=10, M1=5, H2=15, M2=20 aterizarea are loc în aceeași zi cu decolarea (zborul durează 5 ore și 15 minute), iar pentru H1=23, M1=5, H2=1, M2=15 aterizarea are loc în ziua următoare (zborul durează 2 ore și 10 minute).

Un virus informatic s-a infiltrat în sistemele de calcul ale companiei și a inversat momentul de decolare cu cel de aterizare al zborurilor pe care le consideră speciale. Un zbor este considerat special de către acest virus în cazul în care codul aeroportului de decolare, A1, este un număr prim, iar codul aeroportului de aterizare, A2, se divide cu suma cifrelor lui A1.

Cerința
Cunoscându-se numărul de zboruri N și datele fiecăruia, înainte de intervenția virusului, să se determine:

Care este durata maximă a unui zbor, înainte de intervenția virusului.
Care este durata maximă a unui zbor, după intervenția virusului. Se iau în calcul atât duratele zborurilor inversate (speciale), cât și duratele zborurilor neinversate (nespeciale).
Date de intrare
Fișierul de intrare aeriana.in conține pe prima linie valoarea C (numărul cerinței, poate fi 1 sau 2), pe a doua linie valoarea N (numărul de zboruri). Pe fiecare dintre următoarele N linii sunt câte șase numere naturale A1, A2, H1, M1, H2, M2, în această ordine, despărțite prin câte un spațiu, cu semnificația din enunț.

Date de ieșire
Fișierul de ieșire aeriana.out va conține pe prima linie două numere naturale separate printr-un spațiu, reprezentând numărul de ore și respectiv numărul de minute ale zborului de durată maximă, în condițiile cerinței specificate.

Restricții și precizări
1 ≤ N ≤ 1000
0 ≤ H1, H2 ≤ 23
0 ≤ M1, M2 ≤ 59
0 ≤ A1, A2 ≤ 1.000.000.000
Un zbor va dura cel puțin un minut și cel mult 23 de ore și 59 de minute
Pentru 19 puncte, C=1 și toate zborurile se desfășoară în aceeași zi
Pentru 17 puncte, C=1, M1=0, M2=0 pentru toate zborurile
Pentru 17 puncte, C=1, fără alte precizări
Pentru 47 puncte, C=2
Exemplul 1:
aeriana.in

1
3
47 55 0 0 23 59
1 437 23 43 10 34
11 457 10 43 10 23
aeriana.out

23 59
Explicație
C=1, N=3. Duratele acestor zboruri sunt, în ordine, 23 de ore și 59 de minute, 10 ore și 51 de minute, iar pentru ultimul zbor, 23 de ore și 40 de minute.

Exemplul 2:
aeriana.in

2
3
47 55 0 0 23 59
1 437 23 43 10 34
11 457 10 43 10 23
aeriana.out

23 40
Explicație
C=2, N=3. Pentru primul zbor A1=47 este număr prim, suma cifrelor sale este egală cu 11 și A2=55 se divide cu 11, deci primul zbor devine 23:59-00:00 și are o durata de 0 ore și 1 minut. Al doilea zbor rămâne nemodificat, deoarece 1 nu e prim. Al treilea zbor rămâne nemodificat. Chiar dacă 11 este prim, 457 nu se divide cu 2 (suma cifrelor lui 11). Zborul de durata maximă, dupa interventia virusului, este cel de-al treilea.
*/

#include <bits/stdc++.h>
using namespace std;

ifstream f("aeriana.in");
ofstream g("aeriana.out");

bool prim(int n)
{
    if(n <= 3)
        return n >= 2;
    if(n % 2 == 0 || n % 3 == 0)
        return false;
    for(int d = 5; d * d <= n; d = d + 6)
        if(n % d == 0 || n % (d + 2) == 0)
                return false;
    return true;
}

int suma_cifre(int n)
{
    int sum = 0;
    while(n)
        sum = sum + n % 10, n = n / 10;
    return sum;
}

int task, n, i, A1, A2, h1, h2, m1, m2, decolare, aterizare, MAX, sum;
int main()
{
    f >> task >> n;
    if(task == 1)
    {
        for(i = 1; i <= n; i++)
        {
            f >> A1 >> A2 >> h1 >> m1 >> h2 >> m2;
            decolare = h1 * 3600 + m1 * 60;
            aterizare = h2 * 3600 + m2 * 60;
            if(aterizare >= decolare)
            {
                if(aterizare - decolare > MAX)
                    MAX = aterizare - decolare;
            }
            else
            {
                decolare = (23 * 3600 + 60 * 60) - decolare;
                if(aterizare + decolare > MAX)
                    MAX = aterizare + decolare;
            }
        }
        g << MAX / 3600 << " " << MAX % 3600 / 60;
    }
    else
    {
        for(i = 1; i <= n; i++)
        {
            f >> A1 >> A2 >> h1 >> m1 >> h2 >> m2;
            sum = suma_cifre(A1);
            if(prim(A1) && A2 % sum == 0)
            {
                decolare = h1 * 3600 + m1 * 60;
                aterizare = h2 * 3600 + m2 * 60;
                if(aterizare <= decolare)
                {
                    if(decolare - aterizare > MAX)
                        MAX = decolare - aterizare;
                }
                else
                {
                    aterizare = (23 * 3600 + 60 * 60) - aterizare;
                    if(aterizare + decolare > MAX)
                        MAX = aterizare + decolare;
                }
            }
            else
            {
                decolare = h1 * 3600 + m1 * 60;
                aterizare = h2 * 3600 + m2 * 60;
                if(aterizare >= decolare)
                {
                    if(aterizare - decolare > MAX)
                        MAX = aterizare - decolare;
                }
                else
                {
                    decolare = (23 * 3600 + 60 * 60) - decolare;
                    if(aterizare + decolare > MAX)
                        MAX = aterizare + decolare;
                }
            }
        }
        g << MAX / 3600 << " " << MAX % 3600 / 60;
    }

    return 0;
}