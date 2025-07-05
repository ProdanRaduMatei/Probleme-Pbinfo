/*
Cerința
Să se calculeze cate numere prime sunt în intervalul [st, dr].

Date de intrare
Fișierul de intrare countprime.in conține pe prima linie două numere st și dr.

Date de ieșire
Fișierul de ieșire countprime.out va conține pe prima linie numărul cnt, reprezentând numărul de numere prime din intervalul dat.

Restricții și precizări
1 ≤ st ≤ dr < 232
dr - st ≤ 1.000.000
Exemplu:
countprime.in

2 10
countprime.out

4
Explicație
Sunt 4 numere prime în intervalul [2, 10].
*/

#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

unsigned long long int power(unsigned long long int x, unsigned long long int y, unsigned long long p)
{
    unsigned long long res = 1;

    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % p;

        y = y >> 1;
        x = (x*x) % p;
    }

    return res;
}

bool millerTest(unsigned long long d, unsigned long long n)
{
    unsigned long long a = 2 + rand() % (n - 4);

    unsigned long long x = power(a, d, n);

    if (x == 1  || x == n - 1)
        return true;

    while (d != n-1) {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }

    return false;
}

bool prime(unsigned long long n, unsigned long long k)
{
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;

    unsigned long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (unsigned long long i = 0; i < k; i++)
         if (!millerTest(d, n))
              return false;

    return true;
}

int main(void)
{
    unsigned long long st, dr, count = 0;

    fstream fin("countprime.in");
    ofstream fout("countprime.out");

    fin >> st >> dr;

    if(st == 2)
        count++;

    if(st % 2 == 0)
        st++;

    if(dr == 2 && st != 2)
        count++;

    if(dr % 2 == 0)
        dr--;

    for(unsigned long long i = st; i <= dr; i += 2)
        if(prime(i, 4))
            count++;

    fout << count;

    return 0;
}