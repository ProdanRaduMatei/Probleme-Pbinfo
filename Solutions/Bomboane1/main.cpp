/*
Cerința
Lui Cristian, ca oricărui alt copil, îi plac bomboanele. A primit cadou de la prietenii lui cutii cu bomboane. Fiind multe cutii le-a numerotat: 1, 2, 3, … Desfăcând câteva, a văzut că există o legătură între numărul de pe etichetă și numărul de bomboane din cutie. Astfel în fiecare cutie sunt atâtea bomboane câți divizori pari are numărul de pe cutie. De exemplu cutia cu numărul 10 conține 2 bomboane, cutia cu numărul 8 conține 3 bomboane ș.a.m.d.

Cristian a ales la întâmplare două etichete x și y dorind să desfacă toate cutiile cu etichete cuprinse între x și y. Ajutați-l să determine prima cutie, etichetată cu a, și utima cutie, etichetată cu b, cu număr maxim de bomboane (x≤a≤b≤y), câte cutii n sunt cu acest număr de bomboane și care este acest număr d de bomboane.

Date de intrare
Fișierul de intrare bomboane1.in conține pe prima linie numerele naturale nenule x și y separate prin câte un spațiu.

Date de ieșire
Fișierul de ieșire bomboane1.out va conține o singură linie pe care vor fi scrise cele patru valori determinate, în ordinea din cerință (a b n d), separate prin câte un spațiu.

Restricții și precizări
1 ≤ x ≤ a ≤ b ≤ y ≤ 1.000.000.000
y - x ≤ 1000
Exemplu:
bomboane1.in

10 20
bomboane1.out

12 20 3 4
Explicație
Dacă parcurgem toate numerele de la 10 la 20 constatăm că numărul maxim de divizori pari este 4 obținut la numerele 12, 16 şi 20 (3 numere).
*/

#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("bomboane1.in");
ofstream fout("bomboane1.out");

int nrDivPar(int n)
{
    int ans = 0;
    if (n%2==0)
    for (int i=1; i*i<=n; i++)
    {
        if (n%i==0)
        {
            int x = n/i;
            if (i%2==0)
                ans++;
            if (x!=i)
            if (x%2==0) ans++;
        }
    }
    return ans;
}

int x, y, n, d, a, b, maxi=0;
int main()
{
    fin>>x>>y;
    for (int i=x; i<=y; i++)
    {
        int nr = nrDivPar(i);
        if (nr>maxi)
        {
            maxi = nr;
            a=b=i;
            n = 1;
        }
        else if (nr==maxi)
        {
            b=i;
            n++;
        }
    }
    fout<<a<<" "<<b<<" "<<n<<" "<<maxi;
}