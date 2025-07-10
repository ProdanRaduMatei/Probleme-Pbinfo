#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   // stiai ca formula ariei trapezului exprimata in functie de laturi este (a+c) * sqrt(b*b - ((c-a)*(c-a) + b*b - d*d)
   //   *((c-a)*(c-a) + b*b - d*d) / 4/(c-a)/(c-a)) / 2; ?
   //   da, nici eu.
   // dar stiai ca trapezului exista doar daca este adevarata conditia |d-b| < |c-a| < d+b ?
   //   da, NIMENI nu stia asta.
   double a, b, c, d, A;
   cin >> a >> b >> c >> d;

   if ((abs(d-b) < abs(c-a) && abs(c-a) < abs(d+b))  ==  false)
   {
      cout << "Imposibil";
   }
   else
   {
      A = (a+c) * sqrt(b*b - ((c-a)*(c-a) + b*b - d*d)*((c-a)*(c-a) + b*b - d*d) / 4/(c-a)/(c-a)) / 2;
      A *= 100;

      cout << int(A)/100 << '.' << int(A)/10%10 << int(A)%10;
   }
}