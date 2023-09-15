/*
Vlad a inventat un nou joc. Jocul conţine N standuri aşezate în linie dreaptă. Fiecare stand are o etichetă pe care este scris un număr natural. Eticheta este considerată corectă dacă numărul îndeplineşte următoarele două condiţii:

conține atât cifre pare, cât și cifre impare;
începe cu cifrele impare așezate în ordine crescătoare, urmate de cifrele pare în ordine descrescătoare.
De exemplu, eticheta 137860 este corectă, dar etichetele 23541, 135, 64 şi 3146 nu sunt corecte.

Pentru jocul său, Vlad a construit robotul reparator care ştie să verifice numere şi să le repare, dacă este necesar. Robotul reparator se deplasează în linie dreaptă și se opreşte pe rând la fiecare dintre cele N standuri. La fiecare stand, robotul verifică eticheta şi dacă nu este corectă, o „repară”. Pentru a repara eticheta, robotul aranjează cifrele impare în ordine crescătoare, apoi, în continuare, aranjează cifrele pare în ordine descrescătoare; dacă eticheta nu conţine nicio cifră impară, cea mai mare cifră pară o înlocuieşte cu 9 ; dacă eticheta nu conţine nicio cifră pară, cea mai mică cifră impară o înlocuieşte cu 0 . Deplasarea de la un stand la altul durează t secunde, verificarea etichetei unui stand durează v secunde, iar repararea acesteia durează r secunde. Cursa robotului se încheie după ce robotul a verificat toate cele N standuri şi a reparat etichetele incorecte.

Cerința
Scrieţi un program care citeşte numărul N de standuri, timpul (ora h , minutul m , secunda s) când robotul ajunge la primul stand, timpii t , v și r cu semnificaţia din enunţ şi etichetele standurilor și care rezolvă următoarele cerințe:

calculează şi afişează timpul (ora, minutul şi secunda) când robotul a încheiat verificarea tuturor celor N standuri şi repararea etichetelor incorecte;
repară (unde este necesar) etichetele standurilor şi afişează etichetele celor N standuri la final.
Date de intrare
Fișierul de intrare robot4.in conține pe prima linie numărul C , reprezentând cerinţa care urmează să fie rezolvată (1 sau 2). Pe linia a doua se află numerele naturale N , h , m , s , iar pe linia a treia numerele naturale t , v , r , cu semnificaţia din enunţ. Numerele aflate pe aceeaşi linie sunt separate prin câte un spaţiu. Pe următoarele N linii se află etichetele standurilor, în ordinea aşezării acestora, câte o etichetă pe o linie.

Date de ieșire
Dacă C=1, fişierul de ieşire robot4.out va conţine o singură linie pe care vor fi scrise 3 numere naturale separate prin câte un spaţiu hf mf sf, reprezentând ora, minutul şi respectiv secunda la care robotul termină repararea.
Dacă C=2, fişierul de ieşire robot4.out va conţine N linii pe care vor fi scrise etichetele standurilor, în ordinea aşezării acestora, după ce robotul a încheiat verificarea şi repararea, câte o etichetă pe o linie.

Restricții și precizări
2 ≤ N ≤ 500
Etichetele standurilor au cel puțin două și cel mult nouă cifre.
Robotul începe și încheie repararea în aceeaşi zi; 0 ≤ h, hf < 24 ; 0 ≤ m, mf, s, sf < 60
Pentru rezolvarea corectă a cerinţei 1 se acordă 40 de puncte; pentru rezolvarea corectă a cerinţei 2 se acordă 60 de puncte.
Exemplul 1
robot4.in

1
3 11 20 50
7 5 15
376572
3564
123
robot4.out

11 21 49
Exemplul 2
robot4.in

2
3 11 20 50
7 5 15
376572
3564
113
robot4.out

357762
3564
130
Explicații
Pentru exemplul 1: Cerinţa este 1 . Există 3 standuri. Pentru simplitate notăm cu h:m:s ora h ,@m@ minute şi s
secunde. La primul stand robotul ajunge la ora 11:20:50. Primul stand are eticheta 376572, care este incorectă, deci robotul o repară. Aici va petrece 5 secunde pentru verificare şi 15 secunde pentru reparare, deci va pleca de aici la ora 11:21:10. La al doilea stand va ajunge la ora 11:21:17; eticheta sa 3564 este corectă deci robotul nu o va modifica; aici va petrece 5 secunde pentru verificare şi pleacă la ora 11:21:22. La al treilea stand va ajunge la ora 11:21:29. Al treilea stand are eticheta incorectă 123, robotul o repară, deci aici va petrece 5+15=20 secunde şi ora la care încheie cursa este 11:21:49.

Pentru exemplul 2: Cerinţa este 2 . Există 3 standuri. Primul stand are eticheta 376572, care este incorectă, robotul o repară şi aceasta devine 357762. La al doilea stand eticheta 3564 este corectă. deci robotul nu o va modifica. Al treilea stand are eticheta incorectă 113, robotul o repară şi devine 130.
*/

//Adriana Simulescu
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{ int N,i,cod,h,m,s,ok,cod1,cod2,ap[10],c,c1,j,T,t,v,r,ncorecte=0,cif,ci,cp,pp,p2,pi;
 ifstream in("robot4.in");
 ofstream out("robot4.out");
 in>>T;
 in>>N>>h>>m>>s;
 in>>t>>v>>r;
 if(T==2)
 for(i=1;i<=N;i++)
 {
     in>>cod;
     cod2=0;
     ci=0;cp=0;pp=1;pi=1;
     for(cif=1;cif<=9;cif=cif+2)
        {
            cod1=cod;
            while(cod1>0)
            {  if(cod1%10==cif)
                {cod2=cod2*10+cif;ci++; pi*=10;
                }
            cod1/=10;

            }
        }
        for(cif=8;cif>=0;cif=cif-2)
        {
            cod1=cod;
            while(cod1>0)
            {  if(cod1%10==cif)
                {cod2=cod2*10+cif;cp++; pp*=10;}
                cod1/=10;

            }
        }

      if(cod==cod2&&ci*cp!=0)
        out<<cod<<'\n';
      else
      {

        if(ci*cp!=0)
            out<<cod2<<'\n';
        else {if(ci==0)
                cod2=cod2%(pp/10)+9*(pp/10);
              else
                cod2=cod2%(pi/10)*10;
              out<<cod2<<'\n';
            }
     }

}
else
{
    for(i=1;i<=N;i++)
 {
     in>>cod;
     cod2=0;
     ci=0;cp=0;pp=1;pi=1;
     for(cif=1;cif<=9;cif=cif+2)
        {
            cod1=cod;
            while(cod1>0)
            {  if(cod1%10==cif)
                {cod2=cod2*10+cif;ci++; pi*=10;
                }
            cod1/=10;

            }
        }
        for(cif=8;cif>=0;cif=cif-2)
        {
            cod1=cod;
            while(cod1>0)
            {  if(cod1%10==cif)
                {cod2=cod2*10+cif;cp++; pp*=10;}
                cod1/=10;

            }
        }

    if(cod==cod2&&ci*cp!=0)
       {
           ncorecte++;
       }

}


    s=s+(N-1)*(t+v)+(N-ncorecte)*r+v;
    m=m+s/60;
    s=s%60;
    h=h+m/60;
    m=m%60;
    out<<h<<" "<<m<<" "<<s<<"\n";
}
in.close();
out.close();
return 0;
}