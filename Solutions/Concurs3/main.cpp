/*
În orașul X va avea loc o nouă ediție a concursului Y, la care participă trei echipe având numerele de concurs 1, 2 și 3. Echipele pot avea număr diferit de concurenți. Ordinea în care participanții intră în concurs este una oarecare. Fiecare concurent are de susținut 9 probe. La fiecare probă, un concurent obține un punctaj exprimat printr-un număr natural, cuprins între 0 și 10, inclusiv.

La scurt timp după ce un concurent a susținut toate cele 9 probe, se afișează performanța concurentului sub forma a două numere naturale, astfel:

primul număr poate fi 1, 2 sau 3 și reprezintă echipa din care face parte concurentul;
al doilea număr este obținut prin concatenarea (alipirea) numerelor ce reprezintă punctajele nenule obținute de concurent la cele 9 probe. Dacă un concurent are punctaj 0 la toate probele atunci al doilea număr este 0.
Punctajul total al unui concurent se obține adunând punctajele obținute de acesta la cele 9 probe. Punctajul unei echipe se obține adunând punctajele totale obt,inute de membrii acesteia. De exemplu, afișajul 2 14102172 semnifică faptul că acest concurent face parte din echipa 2 și are punctajele nenule 1, 4, 10, 2, 1, 7 și 2, la 7 dintre cele 9 probe susținute. La celelalte două probe a avut punctajul 0. Punctajul său total este 27, contribuția sa la punctajul echipei 2 fiind de 27 de puncte.

Este declarată campioană echipa cu punctajul cel mai mare. Dacă mai multe echipe au obținut cel mai mare punctaj, atunci toate aceste echipe sunt declarate campioane. Totuși, dacă toate echipele au totalizat 0 puncte, atunci nicio echipă nu este declarată campioană.

Cerința
Cunoscând numărul N de concurenți, echipele din care fac parte precum și punctajele obținute de fiecare dintre ei, să se determine:
1. punctajul maxim obținut de un concurent și numărul de concurenți care au obținut acest punctaj;
2. numărul sau numerele de concurs ale echipelor declarate campioane, în ordine crescătoare, și punctajul obținut de acestea. Dacă toate echipele au punctajul final 0, se va afișa textul FARA CAMPION.

Date de intrare
Fișierul de intrare concurs.in conține pe prima linie un număr C (care poate fi 1 sau 2), indicând cerința de rezolvat. Pe a doua linie se găsește un număr natural N reprezentând numărul de concurenți, iar pe fiecare dintre următoarele N linii se găsesc câte două numere naturale, separate printr-un spațiu, reprezentând echipa și punctajele fiecăruia dintre cei N concurenți, în ordinea intrării în concurs.

Date de ieșire
1. Dacă C = 1, fișierul de ieșire concurs.out va conține pe o singură linie două numere naturale, separate printr-un spațiu, reprezentând punctajul maxim obținut de un concurent și numărul de concurenți care au obținut acest punctaj.
2. Dacă C = 2, fișierul de ieșire va conține pe o singură linie textul FARA CAMPION dacă toate echipele au la final punctajul 0. În caz contrar linia va conține două, trei sau patru numere naturale separate prin câte un spațiu, reprezentând numărul sau numerele de concurs ale echipelor declarate campioane, în ordine crescătoare, și apoi punctajul obținut de acestea.

Restricții și precizări
Se garantează că datele din fișier respectă formatul precizat.
1 ≤ N ≤ 100.000
Pentru teste în valoare de 35 de puncte avem C = 1.
Pentru teste în valoare de 65 de puncte avem C = 2.
Exemplul 1:
concurs.in

1
7
1 1111973
2 3101971
1 1999
2 1010101
3 1010101
3 0
3 1371910
concurs.out

31 4
Explicație
Punctajele obținute de concurenți sunt: 23, 31, 28, 31, 31, 0, 31 deci punctajul maxim este 31 și sunt 4 concurenți cu acest punctaj.

Exemplul 2:
concurs.in

2
5
1 1111973
2 3101971
1 1999
3 1010101
3 1371910
concurs.out

3 62
Explicație
Sunt 5 concurenți, primul concurent este din echipa 1 și are punctajul 23, cel de-al doilea concurent este din echipa 2 și are punctajul 31, cel de-al treilea este din echipa 1 și are punctajul 28, al patrulea este din echipa 3 și are 31 de puncte, iar al cincilea este din echipa 3 și are 31 de puncte. Punctajul total al echipei 1 este 51, punctajul total al echipei 2 este 31, punctajul total al echipei 3 este 62. Deci va câștiga echipa 3 cu 62 de puncte.

Exemplul 3:
concurs.in

2
3
2 1111973
3 31019
1 1010111
concurs.out

1 2 3 23
Explicație
Sunt 3 concurenți, primul concurent este din echipa 2 și are punctajul 23, cel de-al doilea concurent este din echipa 3 și are punctajul 23, cel de-al treilea este din echipa 1 și are punctajul 23, Deci, toate cele 3 echipe au punctaj maxim 23.
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <climits>
#include <vector>

using namespace std;

int digitsum(long long int n)
{
    int s = 0, d;

    while(n) {
        d = n % 10;
        if(d)
            s += d;
        else
            s += 9;
        n /= 10;
    }

    return s;
}

int main(void)
{
    int c, n, m = INT_MIN, teams[3] = {0}, count = 0, t, d, i, sum = 0;
    long long int p;
    vector<pair<int, int> > s;

    ifstream fin("concurs.in");
    ofstream fout("concurs.out");

    fin >> c >> n;

    for(i = 0; i < n; i++) {
        fin >> t >> p;
        d = digitsum(p);
        teams[t - 1] += d;
        if(d > m)
            m = d, count = 1;
        else if(m == d)
            count++;
    }

    if(c == 1)
        fout << m << " " << count;
    else {

        for(i = 1; i <= 3; i++) {
            s.push_back(make_pair(teams[i - 1], -i));
            sum += teams[i - 1];
        }
        sort(s.begin(), s.end());
        m = s[2].first;

        if(sum == 0)
            fout << "FARA CAMPION";
        else {
            for(i = 2; i >= 0; i--) {
                if(s[i].first == m)
                    fout << -s[i].second << " ";
                else
                    break;
            }
            fout << m;
        }
    }

    return 0;
}