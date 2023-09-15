/*
Cerința
Se dă un număr natural nenul n. Trebuie să determinați suma anumitor cifre din n. O cifră poate fi adunată la sumă numai dacă ea este strict mai mare decât toate celelalte din dreapta sa. De exemplu, dacă n = 3712531, atunci suma va fi 7+5+3+1. De exemplu, 7 se adaugă la sumă pentru că în dreapta sa se află cifrele 1,2,5,3,1, toate strict mai mici. La fel, la sumă s-a adunat 3 deoarece în dreapta sa se află doar cifra 1. S-a adunat și 1 pentru că în dreapta sa nu se află nicio cifră.

Date de intrare
Programul citește de la tastatură numărul n.

Date de ieșire
Programul va afișa pe ecran numărul S, reprezentând suma cifrelor menționate în cerință.

Restricții și precizări
1 ≤ n ≤ 2.000.000.000
Exemplul 1:
Intrare

4713
Ieșire

10
Explicație
Se adună cifrele 7+3 = 10.

Exemplul 2:
Intrare

12345
Ieșire

5
Explicație
Suma este formată doar din cifra unităților.

Exemplul 3:
Intrare

987654321
Ieșire

45
Explicație
Se adună toate cifrele.


*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int s = 0;
    int max = 0;
    while (n)
    {
        if (n % 10 > max)
        {
            max = n % 10;
            s += max;
        }
        n /= 10;
    }
    cout << s;
}