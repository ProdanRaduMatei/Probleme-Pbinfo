/*
Pornind de la numărul 1, orice număr natural n se poate obţine aplicând în mod repetat şi convenabil operaţii dintre cele de mai jos:
înmulţire cu 3 (operaţie codificată cu 3);
adunare cu 5 (operaţie codificată cu 5);
adunare cu 7 (operaţie codificată cu 7);
împărţire la 9 (operaţie codificată cu 9).
În acest proces de transformare a numărului putem folosi toate operaţiile sau numai câteva dintre ele.
De exemplu numărul 13 se poate obţine astfel:

1 + 7 = 8
8 * 3 = 24
24 * 3 = 72
72 / 9 = 8
8  + 5 = 13

Codificând procesul de transformare de la stânga la dreapta obţinem următorul şir de operaţii 7 3 3 9 5. O altă soluţie corectă, ce nu foloseşte toate operaţiile este: 5 7.

Cerinţă
Cunoscând numărul natural n, să se tipărească şirul de operaţii prin care se poate ajunge de la numărul iniţial 1 la numărul final n.

Date de intrare
Fişierul de intrare n3579.in conţine pe prima linie valoarea numărului natural n.

Date de ieşire
Fişierul de ieşire n3579.out va conţine pe prima linie elementele şirului de operaţii: numere naturale separate prin câte un spaţiu.

Restricţii şi precizări
1 < n <= 2 000 000 000;
Pot exista mai multe soluţii, se acceptă oricare, dacă se încadrează în timpul de execuţie;
Nu este obligatorie folosirea tuturor tipurilor de operaţii.
Exemplul 1
n3579.in

13
n3579.out

7 3 3 9 5
Exemplul 2
n3579.in

11
n3579.out

5 5
*/

#include <fstream>

using namespace std;
int a[100];
int main()
{   int n,i,k;
    ifstream fin("n3579.in");
    ofstream fout("n3579.out");
    fin>>n;
    k=0;
    while (n>1)
        if (n==2)
        {
            n=1;
            a[++k]=9;
            a[++k]=3;
            a[++k]=5;
        }
        else
        if (n==3)
        {
            n=1;
            a[++k]=3;
        }
        else
        if (n==4)
        {
            n=1;
            a[++k]=9;
            a[++k]=7;
            a[++k]=7;
            a[++k]=7;
            a[++k]=7;
            a[++k]=7;
        }
        else
        if (n==5)
        {
            n=1;
            a[++k]=9;
            a[++k]=3;
            a[++k]=7;
            a[++k]=7;
        }
        else
        if (n==6)
        {
            n=1;
            a[++k]=3;
            a[++k]=9;
            a[++k]=3;
            a[++k]=5;
        }
        else
        if (n==7)
        {
            n=1;
            a[++k]=5;
            a[++k]=9;
            a[++k]=3;
            a[++k]=5;
        }
        else
        if (n%3==0)
        {
            n=n/3;
            a[++k]=3;
        }
        else
            if ((n-5)%3==0)
            {
                n=(n-5)/3;
                a[++k]=5;
                a[++k]=3;
            }
            else
            {
                n=(n-7)/3;
                a[++k]=7;
                a[++k]=3;
            }

    for (i=k;i>0;i--)
        fout<<a[i]<<" ";
    fout<<"\n";
    fin.close();
    fout.close();
    return 0;
}