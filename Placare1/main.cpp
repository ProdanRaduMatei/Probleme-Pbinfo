/*
Un perete dreptunghiular de lățime L și o înălțime foarte mare (teoretic infinită) trebuie să fie protejat la bază cu plăci dreptunghiulare de faianță, de dimensiuni A și respectiv B. Plăcile se monteză una lângă cealaltă, pe mai multe rânduri orizontale, de jos în sus, pe fiecare rând de la stânga la dreapta, TOATE plăcile fiind așezate ”în picioare” (cu latura de mărime A pe orizontală și cea de mărime B pe verticală) sau TOATE ”culcate” (cu latura de mărime B pe orizontală și cea de mărime A pe verticală). Pentru a nu se pierde material, dacă la capătul unui rând nu încape o placă întreagă, se taie din ea porțiunea necesară, porțiunea rămasă fiind folosită la începutul rândului următor.

De exemplu, dacă peretele are lungimea L=10, iar plăcile de dimensiune A=3 și B=4 sunt așezate în picioare, atunci primul rând se completează cu porțiunea de dimensiuni 1 și 4, iar porțiunea rămasă de dimensiuni 2 și 4 este folosită pe rândul al doilea, ca în desenul de mai jos (plăcile hașurate).



Pe rândul al doilea se montează plăcile în continuare în același mod, completându-l la capăt cu o porțiune de placă, restul de placă fiind folosit pe rândul al treilea etc. până ce rândul se încheie cu o placă întreagă, nemaifiind necesară nicio completare cu o porțiune de placă. În acest moment procesul de placare se încheie.Dacă primul rând se încheie cu placă întreagă, atunci placarea se încheie cu un singur rând completat.

Cerința
Cunoscând lățimea L a peretelui și dimensiunile A și B ale plăcilor de faianță, stabiliți înălțimea maximă placată care se poate obține după metoda descrisă mai sus.

Date de intrare
Se citesc din fișierul placare1.in, în această ordine, L, A și B, numere naturale nenule.

Date de ieșire
In fișierul placare1.out se va afișa numărul natural H reprezentând înălțimea maximă placată cu faianță.

Restricții și precizări
1 ≤ A, B ≤ 20.000
1 ≤ L ≤ 1.000.000.000
Exemplu:
placare1.in

10 3 4
placare1.out

12
Explicație
Explicații:
Modul de placare este figurat în desenul de mai sus și se observă că înălțimea placată este 12.

Dacă plăcile se așezau ”culcat”, se obținea o placare cu înălțimea 6, ca în desenul de mai jos.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <bitset>
#include <cstring>
#include <algorithm>
using namespace std;

string  nume = "placare1";

ifstream fin(nume + ".in");
ofstream fout(nume + ".out");

typedef unsigned long long ull;
typedef long long  ll;

ull cmmdc(ull a, ull b)
{
	while (b)
	{
		ull r = a % b;
		a = b;
		b = r;
	}
	return a;
}

ull cmmmc(ull a, ull b)
{
	return a * b / cmmdc(a, b);
}

int main()
{

	ull Latime, A, B;
	fin >> Latime >> A >> B;
	fout << max(cmmmc(Latime, A)/Latime * B, cmmmc(Latime, B)/Latime * A);

	
}