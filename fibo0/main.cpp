/*
Se consideră şirul Fibonacci, definit astfel: f1=1
 , f2=1
, fn=fn−1+fn−2
 , dacă n>2.

Cerința
Se dau perechi de numere a și b cu a ≤ b. Să se calculeze pentru câte perechi fb
 este multiplu de fa
 .

Date de intrare
Fișierul de intrare fibo0.in conține pe fiecare linie câte două numere a și b cu semnificația din enunț .

Date de ieșire
Fișierul de ieșire fibo0.out va conține pe prima linie numărul N, reprezentând numărul de perechi ce respectă condiția impusă .

Restricții și precizări
Se vor citi până la 1.000.000 de perechi
Numerele citite vor fi numere naturale strict mai mari decât 2 și mai mici decât 2.000.000.002
Exemplu:
fibo0.in

4 9
4 8
10 12
7 21
fibo0.out

2
Explicație
f4=3
, iar f9=34
 care NU este multiplu de 3

f4=3
, iar f8=21
 care este multiplu de 3

f10=55
, iar f12=144
 care NU este multiplu de 55

f7=13
, iar f21=10946
 care este multiplu de 13
*/

#include <bits/stdc++.h>

using namespace std;

int main ()
{
    ifstream f("fibo0.in");
     ofstream g("fibo0.out");

   int a,b,nr=0;
   while(f>>a>>b)
   {
       if(b%a==0)
        nr++;
   }


g<<nr;
    return 0;
}