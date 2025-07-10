/*
Ionel i-a dat numărul său de telefon N lui Vasile, dar a greșit exact o cifră de pe o anumită poziție. Se cunoaște că pe acea poziție cifra corectă este o cifra pară.

Cerința
Determinați numărul minim NR de numere de telefon pe care trebuie să le încerce Vasile astfel încât printre ele să se afle cu siguranță numărul corect de telefon al lui Ionel.

Date de intrare
Fișierul de intrare numar4.in conține pe prima linie numărul N greșit de
telefon transmis de Ionel.

Date de ieșire
Fișierul de ieșire numar4.out va conține pe prima linie numărul NR de
combinații necesare lui Vasile pentru a nimeri cu siguranță și numărul corect al lui Ionel.

Restricții și precizări
Numărul N nu poate începe cu cifra 0. Numărul corect poate incepe cu cifra 0.
Numărul N are cel mult 9 cifre.
Exemplul 1
numar4.in

72361
numar4.out

23
Explicație
In numarul corect:

Pe prima poziție poate fi una din cifrele: 0, 2, 4, 6, 8 sau
Pe a doua poziție poate fi una din cifrele: 0, 4, 6, 8 sau
Pe a treia poziție poate fi una din cifrele: 0, 2, 4, 6, 8 sau
Pe a patra poziție poate fi una din cifrele: 0, 2, 4, 8 sau
Pe a cincea poziție poate fi una din cifrele: 0, 2, 4, 6, 8.
Așadar numărul total de combinații posibile este 5+4+5+4+5=23.

Exemplul 2
numar4.in

27544
numar4.out

22
*/

#include <fstream>

using namespace std;
ifstream fin("numar4.in");
ofstream fout("numar4.out");
int main()
{long n,nr=0;int nr_pare=0,nr_impare=0,c,i;
fin>>n;
while(n!=0)
{
    c=n%10;
    if(c%2==0)nr_pare++;
    else nr_impare++;
    n/=10;
}
for(i=1;i<=nr_pare;i++) nr+=4;
for(i=1;i<=nr_impare;i++)nr+=5;
fout<<nr<<'\n';
    fin.close();fout.close();
    return 0;
}