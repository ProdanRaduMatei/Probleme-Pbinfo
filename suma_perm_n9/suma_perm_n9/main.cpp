/*
Cerința
Scrieți un program care citește un număr natural n și care să calculeze și să afișeze suma S a tuturor numerelor obținute prin rearanjarea cifrelor lui n. Numărul n are toate cifrele distincte.

Date de intrare
Programul citește de la tastatură numărul n.

Date de ieșire
Programul va afișa pe ecran numărul S, reprezentând suma cerută.

Restricții și precizări
n are cel mult 9 cifre și are cifrele distincte.
Exemplu:
Intrare

123
Ieșire

1332
Explicație
Numere obținute din 123 prin amestecarea cifrelor sunt 123, 132, 213, 231, 312 și 321, iar suma lor este 1332.


*/

#include <iostream>
#include <algorithm>
using namespace std;

int n, v[10], a[10], cnt = 0, s = 0;

int nr_cif(int n)
{
    int cnt = 0;
    while(n)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}

int sum_cif(int n)
{
    int s=0;
    while(n)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main()
{
    cin >> n;

    if(n == 0)
    {
        cout << 0;
        return 0;
    }

    int nrc = nr_cif(n);
    int sumc = sum_cif(n);

    int f = 1;
    for(int i=1; i < nrc; i++)
        f *= i;

    sumc *= f;

    int nr1 = 0;
    long long p = 1;

    long long s = 0;
    for(int i = 1; i <= nrc; i++)
    {
        s += p * sumc;
        p *= 10;
    }

    cout << s;
    return 0;
}