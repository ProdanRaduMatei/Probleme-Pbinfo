#include <iostream>
#include <cmath>

int main()
{
   /// a = BC, b = AC, c = AB, p = (AB+BC+AC)/2
   // sqrt(p*(p-a)*(p-b)*(p-c)) = a*b*c/(4R)   =>
   // R = a*b*c / (4*sqrt(p*(p-a)*(p-b)*(p-c)))
   double a, b, c, p, R;
   std::cin >> a >> b >> c;
   if (a+b >= c && a+c >= b && b+c >= a)
   {
      p = (a+b+c)/2;
      R = a*b*c / (4*sqrt(p*(p-a)*(p-b)*(p-c)));
      R *= 100;
      std::cout << int(R) / 100 << '.' << int(R) / 10 % 10 << int(R) % 10;
   }
   else
   {
      std::cout << "Imposibil";
   }

   return 0;
}