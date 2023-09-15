/*
Fie şirul tuturor numerelor naturale de la 1 la un număr oarecare N. Considerând asociate câte un semn (+ sau -) fiecărui număr şi adunând toate aceste numere cu semn se obţine o sumă S. Problema constă în a determina pentru o sumă dată S numărul minim N pentru care, printr-o asociere de semne tuturor numerelor de la 1 la N, se poate obţine S.

Cerința
Pentru un S dat, găsiţi valoarea minimă N şi asocierea de semne numerelor de la 1 la N pentru a obţine S în condiţiile problemei.

Date de intrare
Fișierul de intrare sumaoni.in conține pe prima linie un întreg pozitiv S reprezentând suma ce trebuie obţinută.

Date de ieșire
Fișierul de ieșire sumaoni.out va conține pe prima linie numărul minim N pentru care se poate obţine suma S, iar pe următoarele linii, până la sfârşitul fişierului, numerele care au semn negativ, câte unul pe linie. Ordinea de afişare a numerelor nu are importanţă. Celelalte numere care nu apar în fişier se consideră pozitive.

Restricții și precizări
1 ≤ S ≤ 100.000
Dacă există mai multe soluţii se cere doar una.
Exemplul 1:
sumaoni.in

12
sumaoni.out

7
1
7
Explicație
Suma 12 se poate obţine din minimum 7 termeni astfel: 12 = -1 + 2 + 3 + 4 + 5 + 6 - 7. Atenţie: nu este singura posibilitate de asociere de semne termenilor de la 1 la 7.

Exemplul 2:
sumaoni.in

15
sumaoni.out

5
Explicație
Suma 15 se poate obţine din minimum 5 termeni astfel: 15 = 1 + 2 + 3 + 4 + 5. Pentru că toate numerele din șir au semnul +, atunci se afișează doar valoarea lui N.


*/

#include<fstream>
using namespace std;

ifstream fin("sumaoni.in");
ofstream fout("sumaoni.out");
int main()
{
    int s; fin >> s;
    int st = 1,dr = 1000,n = 0;

    while(st <= dr)
        {
            int mid = st + (dr - st) / 2;
            int sg = mid * (mid + 1) / 2;
            if(sg >= s)
                {
                    n = mid;
                    dr = mid - 1;
                }

            else
                {
                    st = mid + 1;
                }
        }

    int diff = n * (n + 1) / 2 - s;
    while(diff & 1)
        {
            n++;
            diff = n * (n + 1) / 2 - s;

        }

    fout << n << '\n';
    if(diff == 0)
        return 0;

    if(diff / 2 <= n)
        {
            fout << diff / 2;
            return 0;
        }

    diff /= 2;
    for(int i = 1; i <= diff / 2  && i <= n; i++)
        {
            if(diff - i <= n && diff - i != i)
                {
                    fout << i << '\n' << diff - i;
                    return 0;
                }
        }
    
    fin.close();
    fout.close();
    return 0;//superpeace
}