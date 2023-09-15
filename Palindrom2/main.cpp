/*
Un număr se numește palindrom dacă prima lui cifră este egală cu ultima, a doua cu penultima și așa mai departe. De exemplu numerele 1221, 505 și 7 sunt palindromuri, în vreme ce 500, 1410 și 2424 nu sunt palindromuri.

Similar, un număr se numește aproape palindrom dacă are aceleași perechi de cifre identice ca un palindrom, mai puțin o pereche în care cifrele diferă. De exemplu numerele 500, 1411, 2444, 1220, 53625, 14 și 4014 sunt numere aproape palindromuri, în vreme ce 1221, 1410, 6, 505, 22 și 512125 nu sunt numere aproape palindromuri deoarece fie sunt palindromuri, fie au prea multe perechi de cifre diferite.

Mai definim palindromul asociat al unui număr x ca fiind cel mai mic număr palindrom p strict mai mare decât x (p>x). De exemplu palindromul asociat al lui 5442 este 5445, palindromul asociat al lui 2445 este 2552, al lui 545 este 555, al lui 39995 este 40004, al lui 500 este 505, iar al lui 512125 este 512215.

Cerințe
Scrieţi un program care citind un număr natural nenul n și apoi un șir de n numere naturale determină:

1. câte dintre cele n numere sunt palindrom
2. câte dintre cele n numere sunt aproape palindrom
3. palindromurile asociate pentru cele n numere citite.

Date de intrare
Fișierul de intrare palindrom2.in conține pe prima linie un număr C. Pentru toate testele, C poate lua numai valorile 1, 2 sau 3. Pe a doua linie se află numărul n, iar pe a treia linie cele n numere naturale despărțite prin câte un spațiu.

Date de ieșire
Fișierul de ieșire palindrom2.out:

dacă C=1, va conține un singur număr natural reprezentând numărul de numere palindrom din șir
dacă C=2, va conține numărul de numere din șir care sunt aproape palindrom
dacă C=3, va conține numerele palindrom asociate celor n numere din șir, separate prin câte un spațiu
Restricții și precizări
1 ≤ n ≤ 10 000
1 ≤ numerele din șir ≤ 2 000 000 000
Pentru rezolvarea corectă a primei cerinţe se acordă 20 de puncte, pentru rezolvarea corectă a celei de a doua cerințe se acordă 30 de puncte, iar pentru rezolvarea corectă a celei de a treia cerințe se acordă 50 de puncte.
Exemplul 1
palindrom2.in

1
7
1221 500 53635 505 7 4004 1410
palindrom2.out

5
Explicație
Explicație: Cele 5 numere palindrom sunt 1221, 53635, 505, 7 și 4004. (C fiind 1, se rezolvă doar prima cerință)

Exemplul 2
palindrom2.in

2
4
5442 2445 545 39995
palindrom2.out

3
Explicație
Explicație: Cele 3 numere aproape palindrom sunt 5442, 2445 și 39995. (C fiind 2, se rezolvă doar a doua cerință)

Exemplul 3
palindrom2.in

3
11
6 1411 2444 1221 505 1220 53625 14 4014 1410 22
palindrom2.out

7 1441 2552 1331 515 1221 53635 22 4114 1441 33
Explicație
Explicație: Palindromul asociat lui 6 este 7, al lui 1411 este 1441, al lui 2444 este 2552 etc. (C fiind 3, se rezolvă doar a treia cerință)
*/

#include <fstream>
typedef std::string str;
std::ifstream fin ("palindrom2.in");
std::ofstream fout ("palindrom2.out");

void swap(char &a, char &b)
{
   char aux = a;
   a = b;
   b = aux;
}

int strToInt(str x)
{
   int nr = 0;
   unsigned size = x.length();

   for (int i = 0; i < size; ++i)
      nr = nr * 10  +  (x[i] - '0');

   return nr;
}

int incrementMid(int nr)
{
   bool nine = true;
   int i;
   str x = std::to_string(nr);
   unsigned size = x.length();
   unsigned half = size /2;

   bool all_9 = true;
   for (i = 0; i < size; ++i)
      if (x[i] != '9')
         all_9 = false;
   if (all_9)
   {
      int rez = 1;
      for (i = 1; i < size; ++i)
         rez *= 10;
      return rez * 10 + 1;
   }

   if (size % 2 == 1)
   {
      if (x[half] == '9')
         x[half] = '0';
      else
      {
         nine = false;
         x[half] = ((x[half] - '0') + 1) + '0';
      }
   }

   for (int i = (int)half - 1; i >= 0 && nine; --i)
   {
      if (x[i] == '9')
         x[i] = '0';
      else
      {
         x[i] = ((x[i] - '0') + 1) + '0';
         nine = false;
      }
      x[size - i - 1] = x[i];
   }

   return strToInt(x);
}

int oglindit(int nr)
{
   int oglindit = 0;

   while (nr != 0)
   {
      oglindit = oglindit * 10  +  nr%10;
      nr /= 10;
   }

   return oglindit;
}

str oglindit(str nr)
{
   unsigned size = nr.length();
   unsigned half = size /2;
   for (int i = 0; i < half; ++i)
      swap(nr[i], nr[size - i - 1]);

   return nr;
}

int palindromAsociat(int nr)
{
   str str_rez = std::to_string(nr);
   int rez;
   int size = str_rez.length();
   int half = size /2;

   for (int i = 0; i < half; ++i)
      str_rez[size - i - 1] = str_rez[i];

   rez = strToInt(str_rez);
   if (rez <= nr)
      rez = incrementMid(rez);

   return rez;
}

bool palindrom(int nr)
{
   return oglindit(nr) == nr;
}

bool aproapePalindrom(int nr)
{
   str str_nr = std::to_string(nr);
   str ogl = oglindit(str_nr);
   int size = str_nr.length();
   int half = size /2;
   int unmatches = 0;

   for (int i = 0; i < half; ++i)
      if (str_nr[i] != str_nr[size - i - 1])
         unmatches ++;

   return unmatches == 1;
}

int main()
{
   int cer, n, i;
   fin >> cer >> n;
   int v[n];
   for (i = 0; i < n; ++i)
      fin >> v[i];

   if (cer == 1)
   {
      int palindroame = 0;
      for (i = 0; i < n; ++i)
            palindroame += palindrom(v[i]);

      fout << palindroame;
   }
   else if (cer == 2)
   {
      int apr_palindr = 0;
      for (i = 0; i < n; ++i)
         apr_palindr += aproapePalindrom(v[i]);

      fout << apr_palindr;
   }
   else
   {
      for (i = 0; i < n; ++i)
         fout << palindromAsociat(v[i]) << ' ';
   }
   return 0;
}