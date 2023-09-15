/*
Pentru că îi plac cifrele, Skippie, iepurașul norocos, a stabilit cum se obține cifra de control a unui număr: se efectuează suma cifrelor sale, apoi suma cifrelor acestei sume, până când suma obținută este un număr format dintr-o singură cifră. Această ultimă cifră, spune Skippie, poartă numele de cifră de control. Skippie a ascuns în păadure n ouă roșii. Pe fiecare ou a pictat câte un număr natural nenul. Iar acum se întreabă care este suma dintre cel mai mare și cel mai mic număr natural care se pot forma din toate cifrele distincte folosite în scrierea numărului pictat. În plus, pentru că lui Skippie îi plac problemele complicate, pentru fiecare număr pictat pe câte un ou el ar vrea să afle și de câte ori apare cifra de control a numărului în scrierea tuturor numerelor naturale mai mici sau egale decât numărul pictat.

Cerința
1. Pentru fiecare dintre cele n numere pictate de Skippie aflați suma dintre cel mai mare și cel mai mic număr natural care se pot forma din toate cifrele distincte folosite în scrierea numărului pictat.
2. Pentru fiecare dintre cele n numere pictate de Skippie aflați de câte ori apare cifra de control a numărului pictat în scrierea tuturor numerelor naturale mai mici sau egale decât numărul pictat.

Date de intrare
Fișierul de intrare iepuras.in conține un număr natural C. Acesta poate avea valorile 1 sau 2 și reprezintă cerința problemei. Cea de-a doua linie a fișierului de intrare conține un număr natural n reprezentând numărul de ouă roșii pictate de Skippie. Fiecare dintre următoarele n linii ale fișierului de intrare conține câte un număr natural nenul reprezentând numerele pictate de iepuras, pe cele n ouă roșii.

Date de ieșire
Fișierul de ieșire iepuras.out va conține n numere întregi, fiecare pe o linie separată. În ordinea apariției numerelor pictate de iepuras în fișierul de intrare, se afișează răspunsurile la cerința C.

Restricții și precizări
1 ≤ C ≤ 2
1 ≤ n ≤ 100.000
numerele pictate de iepuraș sunt mai mici sau egale cu 1018
Exemplul 1:
iepuras.in

1
2
121
33343
iepuras.out

33
77
Explicație
Se rezolvă cerința 1. Sunt 2 ouă pictate (n = 2). Pentru primul ou, pictat cu numărul 121:
- cel mai mare număr natural cu cifre distincte format cu toate cifrele distincte ale numărului pictat este 21;
- cel mai mic număr natural cu cifre distincte format cu toate cifrele distincte ale numărului pictat este 12.
Deci suma celor două numere este 33 (21 + 12 = 33).

Pentru al doilea ou, pictat cu numărul 33343:
- cel mai mare număr natural cu cifre distincte format cu toate cifrele distincte ale numărului pictat este 43;
- cel mai mic număr natural cu cifre distincte format cu toate cifrele distincte ale numărului pictat este 34.
Deci suma celor două numere este 77 (43 + 34 = 77).

Exemplul 2:
iepuras.in

2
2
123
191
iepuras.out

22
39
Explicație
Se rezolvă cerința 2. Sunt 2 ouă pictate (n = 2). Pe primul ou este scris numărul 123 iar pe al doilea ou numărul 191. Cifra de control a numărului 123 este 6 (1 + 2 + 3 = 6). Numărul de apariții aale cifrei 6 în scrierea a tuturor numerelor naturale mai mici sau egale cu 123 este 22. Cifra 6 apare în scrierea numerelor: 6, 16, 26, 36, 46, 56, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 76, 86, 96, 106, 116 de 22 de ori. Cifra de control a numărului 191 este 2. (1 + 9 + 1 = 11, 1 + 1 = 2). Numărul de apariții ale cifrei 2 în scrierea tuturor numerelor naturale mai mici sau egale cu 19 este 39. Cifra 2 apare în scrierea numerelor 2, 12, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 32, 42, 52, 62, 72, 82, 92, 102, 112, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 132, 142, 152, 162, 172, 182 de 39 de ori.
*/

#include <bits/stdc++.h>

using namespace std;
ifstream fin("iepuras.in");
ofstream fout("iepuras.out");
int n, C;
long long nr, nmax, nmin, aux, nrap, p;
long long numar_mare(long long x)
{
    int frm[10];
    for(int c=0; c<10; ++c)
        frm[c]=0;
    long long mare=0;
    do
    {
        frm[x%10]=1;
        x/=10;
    }while(x);
    for(int c=9; c>=0; --c)
        if(frm[c])
            mare=mare*10+c;
    return mare;
}
long long numar_mic(long long x)
{
    int frc[10], ok=0;
    long long mic=0;
    for(int c=0; c<10; ++c)
        frc[c]=0;
    do
    {
        frc[x%10]=1;
        if(x%10==0)
            ok=1;
        x/=10;
    }while(x);
    if(ok)
    {
        int c=1;
        while(frc[c]==0)
            c++;
        mic=c;
        frc[c]=0;
    }
    for(int c=0; c<10; ++c)
        if(frc[c])
        {
            mic=mic*10+c;
            frc[c]=0;
        }
    return mic;
}
int main()
{
    fin>>C;
    if(C==1)
    {
        fin>>n;
        for(int i=1; i<=n; ++i)
        {
            fin>>nr;
            nmax=numar_mare(nr);
            nmin=numar_mic(nr);
            fout<<(nmax+nmin)<<'\n';
        }
        return 0;
    }
    fin>>n;
    for(int i=1; i<=n; ++i)
    {
        fin>>nr;
        aux=nr;
        p=1;
        nrap=0;
        long long alt=0;
        int cifc=(aux%9==0 ? 9 : aux%9);
        do
        {
            if(cifc<(nr % 10)) nrap=nrap+((nr / 10)+1)*p;
            if (cifc>(nr % 10))  nrap=nrap+(nr / 10)*p;
            if (cifc==(nr % 10)) nrap=nrap+((nr / 10)*p)+alt+1;
            alt=alt+(nr % 10)*p;
            nr=nr / 10;
            p=p*10;
        } while(nr>0);
        fout<<nrap<<'\n';
    }
    return 0;
}