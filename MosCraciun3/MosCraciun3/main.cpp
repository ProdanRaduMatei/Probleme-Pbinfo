/*
Cerința
Moș Crăciun este pregătit să ofere cadouri tuturor copiilor. Singura lui problema este Grinch, care încearcă să deschidă seiful cu cadouri al lui Moș Crăciun. Grinch a aflat codul, așa că Moș Craciun a decis să îl schimbe cu unul nou. Presupunem că parola seifului este n și avem 2 numere, p și k. Moș Craciun va inversa primele p cifre și ultimele k cifre ale parolei – parola este formată numai din cifre nenule. Fiind foarte bătrân și greșind mult la calcule, vă roagă să îl ajutați să determine noua parola.

Date de intrare
Programul citește de la tastatură numerele n p k.

Date de ieșire
Programul va afișa pe ecran noul cod.

Restricții și precizări
1 ≤ n < 1000000000000000000
dacă n nu are cel puțin p+k cifre, se va afișa mesajul imposibil.
Exemplu:
Intrare

1428429 2 3
Ieșire

4128924
*/

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long n,p,k;
    cin>>n>>p>>k;
    if(pow(10,p+k)/10>n)
        cout<<"imposibil";
    else
    {
        long long ogl=0,putere=1;
        while(k>0)
        {
            ogl=ogl*10+n%10;
            putere*=10;
            k--;
            n/=10;
        }
        while(n>pow(10,p))
        {
            ogl=putere*(n%10)+ogl;
            putere*=10;
            n/=10;
        }
        long long oglp=0;
        while(n>0)
        {
            oglp=oglp*10+n%10;
            n/=10;
        }
        oglp=oglp*putere+ogl;
        cout<<oglp;
    }
    return 0;
}