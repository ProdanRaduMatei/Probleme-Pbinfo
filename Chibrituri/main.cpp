/*
Lui Gigel, elev în clasa a V-a, îi place grozav de tare să se joace cu cifrele, cu numerele şi creează tot felul de probleme pe care apoi încearcă să le rezolve. Acum se joacă cu o cutie de chibrituri şi formează cu ele cifre. Apoi privirea i-a căzut pe cadranul unui ceas electronic şi a văzut că cifrele sunt formate din segmente orizontale şi verticale şi a început să formeze cu chibriturile cifrele care indică ora (vezi figura). Şi imediat şi-a pus o întrebare: “oare dacă am n chibrituri puse vertical şi m chibrituri puse orizontal, care este ora minimă pe care o pot forma cu aceste chibrituri?”

Cerinţa
Fiind date un număr n de chibrituri verticale şi un număr m de chibrituri orizontale, să se scrie un program care determină numărul de ore posibile, ora minimă şi ora maximă care se pot forma cu aceste chibrituri, în modul indicat mai sus, utilizând toate chibriturile respective şi nemodificând orientarea acestora.

Date de intrare
Fișierul de intrare chibrituri.in conține pe prima linie două numere naturale n m, separate printr-un spaţiu, indicând numărul de chibrituri verticale (n), respectiv orizontale (m).

Date de ieșire
Fișierul de ieșire chibrituri.out va conține pe prima linie numărul de variante posibile de a forma o oră corectă, pe a doua linie ora minimă ce poate fi obținută utilizând toate chibriturile și nemodificând orientarea acestora, iar pe a treia linie ora maximă ce poate fi obținută utilizând toate chibriturile și nemodificând orientarea acestora. Ora minimă și, respectiv, ora maximă se vor scrie sub forma hh:mm, unde ora hh şi minutul mm vor fi formate din exact două cifre, separate prin caracterul : (două puncte).

Restricții și precizări
Pentru datele de test există întotdeauna soluţie.

Cifrele sunt formate din chibrituri în felul următor:


Exemplu:
chibrituri.in

14 10
chibrituri.out

17
00:28
20:08
Explicație
17 variante posibile
Ora minimă: 00:28
Ora maximă: 20:08
*/

#include <fstream>

using namespace std;

int main()
{
    int ver[10]= {4, 2, 2, 2, 3, 2, 3, 2, 4, 3}, orz[10]= {2,0,3,3,1,3,3,1,3,3};
    int c = 0, imin=-1, jmin=-1, kmin=-1, lmin=-1, imax, jmax, kmax, lmax;
    int n, m;

    ifstream fin("chibrituri.in");
    ofstream fout("chibrituri.out");

    fin>>n>>m;

    for (int i=0; i<=2; i++)
        if (i==2)
        {
            for (int j=0; j<4; j++)
                for(int k=0; k<=5; k++)
                    for (int l=0; l<=9; l++)
                        if ((ver[i]+ver[j]+ver[k]+ver[l]==n) && (orz[i]+orz[j]+orz[k]+orz[l]==m))
                        {
                            c++;
                            if (imin==-1)
                            {
                                imin=i;
                                jmin=j;
                                kmin=k;
                                lmin=l;
                            }
                            imax=i;
                            jmax=j;
                            kmax=k;
                            lmax=l;
                        }
        }
        else
        {
            for (int j=0; j<=9; j++)
                for(int k=0; k<=5; k++)
                    for (int l=0; l<=9; l++)
                        if ((ver[i]+ver[j]+ver[k]+ver[l]==n) && (orz[i]+orz[j]+orz[k]+orz[l]==m))
                        {
                            c++;
                            if (imin==-1)
                            {
                                imin=i;
                                jmin=j;
                                kmin=k;
                                lmin=l;
                            }
                            imax=i;
                            jmax=j;
                            kmax=k;
                            lmax=l;
                        }
        }

        fout<<c<<endl;
        fout<<imin<<jmin<<":"<<kmin<<lmin<<endl;
        fout<<imax<<jmax<<":"<<kmax<<lmax<<endl;
}