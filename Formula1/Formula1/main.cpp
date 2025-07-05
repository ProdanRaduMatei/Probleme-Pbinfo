#include <fstream>
#include <cmath>
using namespace std;
int main()
{
   ifstream cin ("formula1.in");
   ofstream cout ("formula1.out");
   long long c, k, n;
   cin >> c >> k >> n;
   if (c == 1)
      cout << (k*2-1)*(k*2-1);
   else
   {
      n = n*2 - 1;   c = 0;
      for (long long i=3; i<=n; i+=2)
         c += i*i/2;
      c += c+1;
      c = sqrt(c);
      if (c%2 == 0)
         c--;
      cout << c*c;
   }
   return 0;
}