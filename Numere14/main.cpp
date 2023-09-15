/*
Victor a primit în dar de la mama sa un joc cu n numere naturale, fiecare dintre ele având număr impar de cifre. Din fiecare număr din joc, el trebuie să extragă cifra din mijloc.

Numărul de puncte pe care le câştigă Victor este egal cu suma cifrelor impare situate în mijlocul fiecărui număr dat.

Cerinţă
Cunoscând numărul n de numere, precum şi cele n numere naturale pe care le primeşte Victor, ajutaţi-l să calculeze corect suma cifrelor impare din mijlocul fiecărui număr citit.

Date de intrare
Fişierul numere14.in conţine pe prima linie numărul n de numere naturale, iar pe următoarea linie n numere naturale având număr impar de cifre.

Date de ieşire
Fişierul numere14.out va conţine pe prima linie un număr ce reprezintă suma cifrelor impare situate în mijlocul fiecărui număr citit.

Restricţii şi precizări
1 < n < 1000000
cele n numere din joc au cel mult 9 cifre fiecare
Exemplu:
numere14.in

5
123 34567 222 271 1523412 
numere14.out

15
*/

#include <fstream>
using namespace std;
ifstream fin("numere14.in");
ofstream fout("numere14.out");
int n,x,s,c,i,j,k,cx;
int main()
{
  fin>>n;
  s=0;
  for(i=1;i<=n;i++)
  {
      fin>>x;
      k=0;
      cx=x;
      while(cx!=0)
      {
          k++;
          cx=cx/10;
      }
      for(j=1;j<=k/2;j++)
         x=x/10;
      if(x%2!=0)
         s=s+x%10;
  }
   fout<<s<<endl;
    return 0;
}