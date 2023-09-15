/*
Cerința
Se generează un şir de numere naturale ai cărui primi termeni sunt, în această ordine:
1, 20, 21, 300, 301, 320, 321, 4000, 4001, 4020, 4021, 4300, 4301, 4320, 4321, 50000,...
Deduceţi regula după care sunt generaţi termenii şirului şi scrieţi un program care să citească numerele naturale k, n şi x şi care să determine:
a) numărul de termeni ai şirului care au prima cifră (cea mai semnificativă) egală cu k;
b) cel de-al n-lea termen al şirului din enunţ;
c) cel mai mare termen al şirului, mai mic sau egal decât x.

Date de intrare
Fișierul de intrare nr.in conține o singură linie pe care sunt scrise trei numere naturale k, n şi x, separate prin câte un spaţiu.

Date de ieșire
Fişierul de ieşire nr.out va conţine 3 linii:
– pe prima linie se va scrie un număr natural reprezentând numărul de termeni ai şirului care au prima cifră (cea mai semnificativă) egală cu k;
– pe a doua linie se va scrie un număr natural reprezentând cel de-al n-lea termen al şirului din enunţ;
– pe a treia linie se va scrie un număr natural reprezentând cel mai mare termen al şirului, mai mic sau egal cu x.

Restricții și precizări
1 ≤ k ≤ 9
3 ≤ n ≤ 511
1 ≤ x ≤ 2.000.000.000
Exemplu:
nr.in

4 19 57890
nr.out

8
50021
54321
Explicație
Pe prima linie a fişierului nr.out se scrie numărul 8, deoarece sunt 8 termeni în şir care au prima cifră egală cu k=4).
Pe a doua linie a fişierului se scrie numărul 50021, deoarece cel de-al n-lea (n=19) termen al şirului este 50021.
Numerele 54321 şi 600000 sunt doi termeni situaţi pe poziţii consecutive în şirul din enunţ, iar 54321 ≤ 57890 < 600000. Astfel, numărul 54321 se scrie pe ultima linie a fişierului nr.out.
*/

#include <iostream> 
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;


string	nume = "nr";
ifstream fin(nume + ".in");
ofstream fout(nume + ".out");

typedef  long long int ull;
typedef long long int ll;

ll numar(ll n)
{

	ll aux = n;

	ll p = 1, res = 0, idx = 1;
	aux = n;

	while (aux)
	{
		if (aux % 2 == 1)
		{
			res += p * idx;
		}
		idx++;
		p *= 10;
		aux /= 2;
	     
	}


	return res;
}

int main()
{
    char x[10];
	ll k, n;
	fin >> k >> n >> x;
	fout <<(1ull<< k - 1)<< '\n';
	ll aux = n;

	ll p = 1, res = 0, idx = 1;
	aux = n;
	
	while (aux)
	{
		if (aux % 2 == 1)
		{
			res += p * idx;
		}
		idx++;
		p *= 10;
		aux /= 2;
	}
	fout << res << '\n';
     int  c = strlen(x);
	
	  if (c==10) fout<<987654321;
    else
    {
        int i=0;
        while ((x[i]==c-i+48 or x[i]=='0') and i<c) ++i;
        while (x[i]<c-i+48 and x[i]!='0' and i<c) {x[i]='0'; ++i;}
        for (int j=i; j<c;++j) x[j]=c-j+48;
        if (x[0]=='0')
        {
            for (int j=0; j<c-1;++j) x[j]=x[j+1];
            x[c-1]=0;
        }
        fout<<x;
    }
}