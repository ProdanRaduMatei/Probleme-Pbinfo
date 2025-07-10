/*
Un atelier de fabricat ceasuri cu cuc are nevoie de plăcuțe cu numerele pentru orele pe care trebuie să le așeze pe discul ceasurilor. Aceste numere sunt realizate la o imprimantă.

Din cauza unei erori imprimanta tipărește plăcuțe cu numere naturale, unele mai mari ca 12. Atelierul poate utiliza doar plăcuțe cu numere cuprinse ı̂ntre 0 și 12. Pentru a utiliza aceste numere este nevoie ca ele să fie tăiate ı̂ncepând din partea dreaptă ı̂n grupuri de maximum două cifre, fiecare grup reprezentând valoarea de pe o plăcuță, care să fie o cifră la 0 la 9 sau unul dintre numerele 10, 11, 12. Dacă pe o plăcuță se găsește un număr mai mare ca 12 atunci plăcuța trebuie tăiată, astfel ı̂ncât ı̂n urma tăierii să se obțină numere de cel mult 2 cifre. Dacă ı̂n numărul de pe o plăcuță cifra zecilor este 0, atunci la prima tăiere se ia doar cifra unităților, altfel dacă numărul format cu cifra zecilor și unităților este mai mare ca 12, atunci se taie prima dată cifra unităților, iar dacă numărul format cu cifra zecilor și unităților este 10, 11 sau 12 se taie prima dată numărul format din ultimele două cifre, apoi procedeul se repetă până la tăierea completă a plăcuței. Imprimanta a realizat N plăcuțe. De exemplu dacă plăcuța este 12030, după tăiere se obțin 0, 3, 0, 12.

Cerința 1
Determinați numărul total de apariții ale cifrei X pe plăcuțe ı̂nainte de tăiere.

Cerința 2
Determinați numărul de tăieturi realizate conform enunțului.

Date de intrare
Pe prima linie a fișierului ceas.in se află valorile C, X și N separate prin câte un singur spațiu. Pe linia a doua se află N numere naturale separate prin câte un singur spațiu, având semnificația din enunț. Pentru C = 1 se rezolvă doar cerința 1, iar pentru C = 2 se rezolvă doar cerința 2.

Date de ieșire
Fișierul ceas.out conține pe prima linie un singur număr natural care reprezintă valoarea calculată
conform cerinței.

Restricții și precizări
1 ≤ N ≤ 100.000
0 ≤ X ≤ 9
Valorile din șir sunt numere naturale ≤ 50.000
Pentru testele în care avem C=2 valoarea X este prezentă în fișierul de intrare chiar dacă nu este folosită în rezolvare.
Pentru teste în valoare de 39 de puncte avem C = 1
Pentru teste în valoare de 61 de puncte avem C = 2
Exemplul 1:
ceas.in

1 0 6
1010 40 201 5123 31 6
ceas.out

4
Explicație
Pe plăcuțe cifra 0 apare de patru ori.

Exemplul 2:
ceas.in

2 0 6
120 40 201 5123 31 6
ceas.out

7
Explicație
În ordinea tăierilor se obțin: 0,12; 0,4; 1,0,2; 3,12,5; 1,3; 6. Numărul de tăieturi este 7.
*/

#include <fstream>

using namespace std;

ifstream fin("ceas.in");
ofstream fout("ceas.out");

int main()
{
    int C, X, N, i, j, k, nr, t, nrt;
    fin >> C >> X >> N;
    int v[N];
    for (i = 0; i < N; i++)
        fin >> v[i];
    if (C == 1)
    {
        nr = 0;
        for (i = 0; i < N; i++)
        {
            t = v[i];
            while (t != 0)
            {
                if (t % 10 == X)
                    nr++;
                t = t / 10;
            }
        }
        fout << nr << endl;
    }
    else
    {
        nr = 0;
        for (i = 0; i < N; i++)
        {
            t = v[i];
            while (t != 0)
            {
                if (t % 10 == X)
                    nr++;
                t = t / 10;
            }
        }
        nrt = 0;
        for (i = 0; i < N; i++)
        {
            t = v[i];
            while (t != 0)
            {
                if (t % 10 > 1)
                    nrt++;
                else if (t % 10 == 1)
                {
                    t = t / 10;
                    if (t % 10 > 2)
                        nrt++;
                    else if (t % 10 == 2)
                        nrt = nrt + 2;
                }
                t = t / 10;
            }
        }
        fout << nrt << endl;
    }
    return 0;
}