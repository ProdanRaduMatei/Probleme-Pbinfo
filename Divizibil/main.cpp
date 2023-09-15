/*
Teodora a primit o tema la matematica. Ea trebuie să raspundă la două întrebări:
1) Câte numere naturale nenule , mai mici decat n, nu sunt divizibile nici cu c1, nici cu c2?
2) Câte numere naturale nenule , mai mici decat n, nu sunt divizibile nici cu c1, nici cu c2, nici cu c3?

Cerința
Teodora vă roagă sa o ajutați cu intrebările si va recompenseaza cu 100 de puncte.

Date de intrare
Programul citește de la tastatură numărul t ce poate fi 1 sau 2.
Dacă t este 1 se vor citi trei numere n, c1, c2 cu semnificația din enunț.
Dacă t este 2 se vor citi patru numere n, c1, c2, c3 cu semnificația din enunț.

Date de ieșire
Programul va afișa pe ecran numărul ct, reprezentând numărul cerut.

Restricții și precizări
t poate fi 1 sau 2.
1 ≤ n ≤ 1000000000
2 ≤ c1,c2,c3 ≤9
oricare două cifre sunt prime intre ele
Exemplu 1:
Intrare

1 10 2 3
Ieșire

3
Explicație
Din cele 9 numere se scad 2,3,4,6,8,9.

Exemplu 2:
Intrare

2 10 3 5 7
Ieșire

4
Explicație
Din cele 9 numere se scad 3,5,6,7,9.
*/

#include <iostream>
using namespace std;
int main()
{
    int n, c1, c2, c3, t;
    cin >> t;
    if (t == 1)
    {
        cin >> n >> c1 >> c2;
        cout << n-(n / c1 + n / c2 - n / (c1 * c2));
    }
    else
    {
        cin >> n >> c1 >> c2 >> c3;
        cout <<n - (n / c1 + n / c2 + n / c3 - n / (c1 * c2) - n / (c2 * c3) - n / (c1 * c3) + n / (c1 * c2 * c3));
    }
    return 0;
}