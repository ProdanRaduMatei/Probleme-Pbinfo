/*
Un joc dispune de N cuburi galbene și N cuburi albastre, de dimensiuni identice; pe fiecare cub galben este scris un număr natural nenul, de cel mult 9 cifre. Jocul urmărește construirea unui castel alcătuit din mai multe rânduri de cuburi, în care rândul de sus este format dintr-un singur cub, de culoare galbenă, iar fiecare dintre celelalte rânduri încep și se termină cu câte un cub de culoare galbenă. Oricare două cuburi vecine pe același rând au câte o latură comună și fiecare cub, cu excepția celor galbene de pe margine, are o latură comună cu un cub care aparține rândului de deasupra. Oricare două cuburi cu o latură comună au culori diferite. Rândurile de cuburi sunt numerotate de jos în sus, începând de la 1.
Pentru construcția castelului se preiau cuburile galbene în ordinea în care acestea sunt date, iar cele albastre într-o ordine oarecare, și sunt plasate pe rânduri, de jos în sus, și pe fiecare rând de la stânga la dreapta, astfel: primul cub se plasează pe rândul de la bază (numerotat cu 1), apoi fiecare cub (galben sau albastru) se plasează fie în continuare, pe rândul curent, la dreapta, fie pe un rând nou, peste un cub al rândului curent. După plasarea cubului din vârful castelului, pe fiecare cub albastru se scrie un număr egal cu suma numerelor scrise pe cei doi vecini galbeni situați pe același rând, în stânga și în dreapta sa.
Pentru a câștiga jocul, castelul obținut trebuie să aibă un număr maxim de rânduri, chiar dacă poate nu folosește toate cuburile date.

Cerința
Cunoscând numerele scrise pe cele N cuburi galbene, în ordinea dată, scrieți un program care să determine:
1) numărul cuburilor galbene, dintre cele N date, pe care sunt scrise valori de o singură cifră;
2) rândul pe care se află cubul din vârful castelului și numărul scris pe acest cub;
3) numărul cuburilor albastre din care este alcătuit castelul și suma tuturor numerelor de pe acestea.

Date de intrare
Fișierul de intrare castel.in conţine:

pe prima linie două numere naturale C și N, în această ordine, despărțite printr-un spațiu, unde C reprezintă numărul cerinţei și poate avea valorile 1, 2 sau 3, iar N are semnificația din enunț;
pe a doua linie, N numere naturale despărțite prin câte un spațiu, reprezentând numerele scrise pe cuburile galbene, în ordinea în care sunt preluate.
Date de ieșire
Fișierul de ieșire castel.out va conține pe prima linie:

un singur număr natural pentru rezolvarea cerinței 1, reprezentând valoarea determinată conform acestei cerințe;
două numere naturale despărțite printr-un spațiu, în cazul cerințelor 2 și 3. Pentru cerința 2, primul număr reprezintă rândul pe care se află cubul din vârful castelului iar cel de-al doilea număr reprezintă valoarea scrisă pe acest cub. Pentru cerința 3, prima valoare reprezintă numărul de cuburi albastre care alcătuiesc castelul, iar a doua valoare reprezintă suma tuturor numerelor scrise pe aceste cuburi.
Restricții și precizări
3 ≤ n ≤ 5.000
Pentru 25 de puncte, C = 1
Pentru 30 de puncte, C = 2
Pentru 45 de puncte, C = 3
Exemplul 1:
castel.in

1 12
17 5 11 2 17 17 4 2 2 5 34 88
castel.out

6
Explicație
C = 1 și sunt 6 cuburi pe care sunt scrise numere de o singură cifră.

Exemplul 2:
castel.in

2 12
17 5 11 2 17 17 4 2 2 5 34 88
castel.out

4 5
Explicație
Exemplul corespunde imaginii din enunț și C = 2. Cubul din vârful castelului este pe rândul 4 și pe el este scris 5.

Exemplul 3:
castel.in

3 12
17 5 11 2 17 17 4 2 2 5 34 88
castel.out

6 110
Explicație
Exemplul corespunde imaginii din enunț și C = 3. Sunt 6 cuburi albastre în castel și suma numerelor scrise pe acestea este 110.
*/

#include <bits/stdc++.h>
using namespace std;

ifstream f("castel.in");
ofstream g("castel.out");

long long task, n, i, j, x, cnt, s, cuburi, a[5002];
int main()
{
    f >> task >> n;
    if(task == 1)
    {
        for(i = 1; i <= n; i++)
        {
            f >> x;
            if(x >= 0 && x <= 9)
                cnt++;
        }
        g << cnt;
    }
    else if(task == 2)
    {
        for(i = 1; i <= n; i++)
            f >> a[i];
        for(i = 1; cnt <= n; i++)
        {
            if(cnt + i <= n)
                cnt = cnt + i, x = i;
            else
                break;
        }
        g << x << " " << a[cnt];
    }
    else
    {
        for(i = 1; i <= n; i++)
            f >> a[i];
        for(i = 1; x <= n; i++)
        {
            if(x + i <= n)
                x = x + i;
            else
                break;
        }
        j = 1;
        for(i = x - 1; i > 1;)
        {
            cnt++;
            s = s + (a[i - 1] + a[i]);
            if(cnt == j)
            {
                j++;
                i = i - 2;
                cuburi = cuburi + cnt;
                cnt = 0;
            }
            else
                i--;
        }
        g << cuburi << " " << s;
    }

    return 0;
}