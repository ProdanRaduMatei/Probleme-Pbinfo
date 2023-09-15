#include <iostream>
#include <cmath>

int main()
{
   // noi stim ca
   // adica eu stiu ca
      // aria unui triunghi este sqrt(p*(p-a)*(p-b)*(p-c))
      // dar aria unui triunghi mai are o formula. aria mai este egala si cu p*r
         // unde p = (a+b+c)/2
      // noi cunoastem a, b, c si p
      // deci, daca egalam cele doua rezultate, vom avea o singura necunoscuta: r
         // unde r este raza cercului inscris, ceea ce ne cere si problema
      // sqrt(p*(p-a)*(p-b)*(p-c)) = p*r  =>  r = sqrt(p*(p-a)*(p-b)*(p-c)) / p
   double a, b, c, p, r; /// nu se precizeaza daca a, b, c sunt numere naturale
   std::cin >> a >> b >> c;
   if (a+b >= c && a+c >= b && b+c >= a)
   {
      p = (a+b+c) /2;
      r = sqrt(p*(p-a)*(p-b)*(p-c)) / p;
      r *= 100;
      if (int(r) % 10 == 0)
      {
         if (int(r) / 10 % 10 == 0)
            std::cout << int(r) / 100 << ".00";
         else
            std::cout << int(r) / 100 << '.' << int(r) / 10 % 10 << 0;
      }
      else
         std::cout << int(r) / 100 << '.' << int(r) / 10 % 10 << int(r) % 10;
   }
   else
   {
      std::cout << "Imposibil";
   }
   return 0;
}