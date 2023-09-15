/*
Împăratul Tiberius Claudius Caesar Augustus Germanicus, pasionat de luptele de gladiatori, a decis să organizeze cele mai mari jocuri care s-au organizat vreodată în Roma Antică.

Pentru a realiza aceste jocuri, Tiberius a chemat la Roma N gladiatori. Apoi, pentru a îi organiza, a decis să aranjeze cei N gladiatori în felul următor: primul gladiator are la dreapta lui gladiatorul 2, iar la stângă lui pe nimeni, gladiatorul 2 are la stângă lui gladiatorul 1 și la dreapta lui gladiatorul 3, …, gladiatorul N-1 are la dreapta lui gladiatorul N și la stângă lui gladiatorul N-2, iar gladiatorul N are la stânga lui gladiatorul N-1, iar la dreapta lui pe nimeni. Împăratul Tiberius poate decide ca doi gladiatori să poarte o bătălie doar dacă se află unul lângă altul. După ce această bătălie se termină, gladiatorul care câștigă se întoarce în șir, iar gladiatorul care pierde părăsește șirul. Atunci când un gladiator pierde o bătălie și părăsește șirul, toți gladiatorii din dreapta lui se mută cu o poziție mai la stânga. Fiecare gladiator are un nivel de faimă egal cu un număr natural, iar pentru a face jocurile mai spectaculoase, împăratul a decis ca atunci când doi gladiatori poartă o bătălie, mereu gladiatorul cu un nivel de faimă mai mic va câștiga. Dacă doi gladiatori au nivelul de faimă egal, atunci va câștiga cel din stânga. Pentru a măsura cât de spectaculoase sunt jocurile, împăratul a inventat un număr, numit “coeficientul de entuziasm”. Acest număr este egal cu 0 înainte să înceapă jocurile. În urma unei bătălii coeficientul de entuziasm crește cu diferența dintre nivelul de faimă al celor doi gladiatori. De exemplu, dacă doi gladiatori poartă o bătălie, iar unul dintre gladiatori are nivelul de faimă egal cu 7 și celălalt are nivelul de faimă egal cu 5, atunci coeficientul va crește cu 7 - 5 = 2. Jocurile se termină atunci când mai rămâne un singur gladiator în picioare.
Cerința
Ajutați-l pe Împăratul Tiberius și spuneți-i care este cel mai mare coeficient de entuziasm pe care îl poate obține atunci când se termină jocurile.

Date de intrare
Pe prima linie a intrării standard se află numărul N, iar pe a doua linie se afla N numere naturale separate prin câte un spaţiu, reprezentând nivelul de faimă al fiecărui gladiator.

Date de ieșire
La ecran se va afișa pe o singură linie un număr natural, care reprezintă coeficientul de entuziasm maxim care poate fi obținut.

Restricții și precizări
1 ≤ N ≤ 100.000
Nivelul de faimă al unui gladiator este un număr natural mai mic decât 1.000.000.000.
Pentru teste în valoare de 15 puncte, toți gladiatorii au același nivel de faimă.
Pentru teste în valoare de alte 25 puncte, primul gladiator are cel mai mic nivel de faimă, iar restul gladiatorilor sunt așezați în ordine descrescătoare
Pentru teste în valoare de alte 20 de puncte, gladiatorii sunt așezați în ordine crescătoare după nivelul de faimă
Pentru teste în valoare de 55 de puncte, N ≤ 1000
Exemplul 1:
Intrare

5
1 2 3 1 7
Ieșire

9
Explicație
Putem obține coeficientul de faimă 9 în modul următor:

Inițial coeficientul de faimă este egal cu 0.
Alegem ca prima bătălie să fie între gladiatorul 4 și gladiatorul 5. Nivelul de entuziasm crește cu 7-1=6, devenind 6, iar gladiatorul 5 părăseșe șirul. Astfel rămânem cu gladiatorii: 1, 2, 3, 4.
A doua bătălie va fi între gladiatorul 1 și gladiatorul 2. Nivelul de entuziasm crește cu 2-1=1, devenind 7, iar gladiatorul 2 părăseșe șirul. Astfel rămânem cu gladiatorii: 1, 3, 4.
A treia bătălie va fi între gladiatorul 1 și gladiatorul 3. Nivelul de entuziasm crește cu 3-1=2, devenind 9, iar gladiatorul 3 părăseșe șirul. Astfel rămânem cu gladiatorii: 1, 4.
Ultima bătălie va fi între gladiatorul 1 și gladiatorul 4. Nivelul de entuziasm crește cu 1-1=0, devenind 9, iar pentru că gladiatorii au nivel de faimă egal și gladiatorul 1 se află mai în stânga, gladiatorul 4 părăsește șirul. Astfel rămânem cu gladiatorul: 1.
Modul de a alege bătăliile nu este neaparat unic.

Exemplul 2:
Intrare

5
1 2 5 6 8
Ieșire

17

*/

#include <bits/stdc++.h> //DaryuF
#define MAX (int)1e5+5

using namespace std;
const string file="";
ifstream in(file + ".in");
ofstream out(file + ".out");
//#define cin in
//#define cout out
long long task,n,v[100001],mini=1000000000000,p,s;
int main()
{
   cin.tie(0)->ios_base::sync_with_stdio(false);
   cout.tie(0);
 cin>>n;
 int x1,x;
for(int i=1;i<=n;i++)
{
    cin>>v[i];
if(v[i]<mini)
{
    mini=v[i];
    p=i;
}
}
for(int i=1;i<=n;i++)
    if(p!=i) s+=v[i];
s-=mini*(n-1);
cout<<s;
    return 0;
}