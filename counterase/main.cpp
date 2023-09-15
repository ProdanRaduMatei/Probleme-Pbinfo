/*
Cerința
Dându-se un număr natural n să se afle câte numere se pot obține folosind biții acestuia.
Un număr natural x se obține folosind biții lui n dacă mulțimea biților setați ai lui x este inclusă în mulțimea biților setați ai lui n. De exemplu, pentru n = 5 reprezentarea binară este 101; x poate lua valorile 101, 100, 001, 000, adică 5, 4, 1, 0.

Date de intrare
Programul citește de la tastatură numărul n.

Date de ieșire
Programul va afișa pe ecran valoarea cerută.

Restricții și precizări
n are cel mult 500 cifre
Exemplu:
Intrare

5
Ieșire

4
*/

#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>

// inmultire cu 2
void Inmultire2(std::string& s)
{
   int add, rest;

   rest = 0;
   for (auto it = s.rbegin(); it != s.rend(); ++it)
   {
      add = rest + (*it - '0') * 2;
      *it = (add%10 + '0');
      rest = add/10;
   }

   if (rest == 1)
      s.insert(s.begin(), '1');
}

// impartire cu 2, returneaza restul impartirii la 2
int Impartire2(std::string& s)
{
   if (s == "1")
   {
      s = "0";
      return 1;
   }
   std::string::iterator it;
   int rest, i;

   if (*s.begin() == '1')
   {
      rest = 1;
      it = std::next(s.begin());
   }
   else
   {
      rest = 0;
      it = s.begin();
   }
      
   for (i = 0; it != s.end(); ++it)
   {
      rest = rest*10 + (*it - '0');
      s[i++] = (rest/2 + '0');
      rest %= 2;
   }

   if (s.size() != i)
      s.pop_back();

   return rest;
}


int main()
{
   std::string n, rez;
   std::cin >> n;
   int i, biti_setati;

   biti_setati = 0;
   while (n != "0")
      biti_setati += Impartire2(n);

   rez = "1";
   for (i = 0; i < biti_setati; ++i)
      Inmultire2(rez);
      
   std::cout << rez;
   return 0;
}