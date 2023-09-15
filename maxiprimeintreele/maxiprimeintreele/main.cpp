#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("maxprimeintreele.in");
ofstream fout("maxprimeintreele.out");

double maxi = 0;
int nrmaxi;

long Totient(long nr) {
  long i, rank = nr;
  if (nr == 1)
      return 0;
  if (!(nr % 2)) {
         rank -= rank / 2;
         while (!(nr % 2))
             nr /= 2;
   }
  for (i = 3; i * i <= nr; i += 2)
   if (!(nr % i))
        {
          rank -= rank / i;
          while (!(nr % i))
              nr /= i;
        }
  if (nr > 1)
      rank -= rank / nr;
  return rank;
}
int main() {
    int x;
    while (fin >> x) {
        if ((double) x / Totient(x) > maxi) {
            maxi = (double) x / Totient(x);
            nrmaxi = x;
        }
    }
    fout << nrmaxi;
    return 0;
}
