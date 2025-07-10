/*
Cerinţă
Să se scrie un program care citește un număr natural și determină câte cifre ale numărului sunt mai mici decât prima sa cifră.

Date de intrare
Programul va citi de la tastatură un număr natural.

Date de ieşire
Programul va afişa pe ecran valoarea cerută.

Restricţii şi precizări
numărul citit va fi mai mic decât 2.000.000.000
Exemplu:
Intrare

32615
Ieşire

2
Explicație
Prima cifră a numărului dat este 3. În număr sunt două cifre mai mici decât 3.
*/

#include <iostream>

using namespace std;
int pc(int n)
 {
     if(n<10)return n;
     else return pc(n/10);
 }
int nrmaimici(int n)
 {
     if(n<10)return 0;
     else if (n%10<pc(n))return 1+nrmaimici(n/10);
          else return nrmaimici(n/10);   
 }

int main()
{
int n;cin>>n;
cout<<nrmaimici(n);

    return 0;
}