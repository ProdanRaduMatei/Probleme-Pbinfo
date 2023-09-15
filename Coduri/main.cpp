/*
În urma inundațiilor din această iarnă, COFFESHOP a suferit câteva pierderi esențiale. Unele materiale au fost luate de ape, iar documentele de înregistrare deteriorate. Pentru estimarea pagubelor s-a pornit la realizarea unor liste cu produsele existente în depozit. Singurele documente recuperate parțial au fost listingurile codurilor produselor și ale codurilor de bare.

Fiecare produs are un un cod reprezentând un număr în bază 16. Codul de bare asociat fiecărui produs este numărul obținut prin conversia codului produsului în baza 2. Pentru un produs se cunoaște fie codul produsului, fie codul de bare. În cazul produselor ale căror coduri nu sunt total vizibile, cifrele care nu se vad sunt marcate cu X.

Cerința
Fiind date numerele naturale N, H și D, reprezentând numărul de produse, numărul de cifre pentru codurile produselor, respectiv numărul de cifre pentru codurile de bare și cele N coduri, să se determine:

a) Pentru fiecare produs pentru care se cunoaște unul dintre cele două coduri, codul care lipsește, adică codul de bare – dacă este specificat codul produsului, respectiv codul produsului – dacă este precizat codul de bare. Pentru produsele pentru care nu se cunoaște cu exactitate niciunul dintre coduri, se va determina, dacă este posibil, codul produsului.
b) Numărul de coduri indescifrabile.

Date de intrare
Fișierul de intrare coduri.in conține pe prima linie despărțite printr-un spațiu, trei numere naturale N H D. Începând cu a doua linie, pe următoarele N linii se găsesc N coduri, precedate de caracterul 'H' pentru codurile produselor, 'D' pentru codurile de bare sau 'U' (unknown) pentru produsele ale căror coduri sunt indescifrabile. În cazul în care, pentru un produs nu se cunoaște cu exactitate niciunul din coduri, fișierul de intrare conține pe linia corespunzătoare caracterul 'U', urmat de codul produsului și codul de bare, cifrele indescifrabile fiind marcate cu 'X'. Pentru codurile indescifrabile, în fișierul de intrare, este scris caracterul 'U', urmat de H cifre hexazecimale și D cifre binare.

Date de ieșire
Fișierul de ieșire coduri.out va conține N+1 linii. Pe primele N linii vor fi trecute codurile lipsă ale produselor în ordinea citirii din fișierul de intrare, codul produsului în cazul în care o parte din cifre sunt indescifrabile, dar pot fi reconstituite din codul de bare, respectiv 0 în cazul în care codul nu poate fi reconstituit. Pe ultima linie se va afișa numărul de coduri indescifrabile.

Restricții și precizări
1 ≤ N ≤ 60000; 1 ≤ H ≤ 8; 1 ≤ D ≤ 32
Codurile produselor sunt cuprinse în intervalul [0,7FFFFFFF]
Pentru reprezentarea codurilor în hexazecimal se folosesc majuscule.
Exemplul 1
coduri.in

5 2 8
HB1
D01011100
D00110101
H23
HA3
coduri.out

10110001
5C
35
00100011
10100011
0
Explicație
Pe al doilea rând, numărul este în bază 16, adică reprezintă codul produsului, iar B116=17710=101100012
.
Pe al treilea rând numărul este în bază 2, adică reprezintă codul de bare, iar 010111002=9210=5C16
.
Pe al patrulea rând, numărul este în bază 2, adică reprezintă codul de bare, iar 001101012=5310=3516
.
Pe al cincelea rând, numărul este în bază 16, adică reprezintă codul produsului, iar 2316=3510=001000112
.
Pe al șaselea rând, număr este în bază 16, adică reprezintă codul produsului, iar A316=16310=101000112
.
Pe ultimul rând se afișează 0, deoarece nu sunt coduri indescifrabile.

Exemplul 2
coduri.in

7 2 8
HB1
D11111111
UX00000X000
HA3
UBX1011X010
UBX10110011
UX1X0000001
coduri.out

10110001
FF
00
10100011
0
B3
0
2
Explicație
Pe al doilea rând, numărul este în bază 16, adică reprezintă codul produsului, iar B116=17710=101100012
.
Pe al treilea rând numărul este în bază 2, adică reprezintă codul de bare, iar 111111112=25510=FF16
.
Pe al patrulea rând, numărul este parțial indescifrabil, adică prima cifră din codul produsului nu este vizibilă, dar poate fi reconstituită din codul de bare, codul produsului fiind 0016=010=000000002
.
Pe al cincelea rând, numărul este în bază 16, adică reprezintă codul produsului, iar A316=16310=101000112
.
Pe al șaselea rând, numărul este parțial indescifrabil, adică a doua cifră din codul produsului nu este vizibilă și nu poate fi reconstituită din codul de bare, deoarece cifra a cincea este de asemenea indescifrabilă. Se afișează 0.
Pe al șaptelea rând, numărul este parțial indescifrabil, adică a doua cifră din codul produsului nu este vizibilă, dar poate fi reconstituită din codul de bare, codul produsului fiind B316=17910=101100112
.
Pe al optulea rând, numărul este parțial indescifrabil, adică prima cifră din codul produsului nu este vizibilă și nu poate fi reconstituită din codul de bare, deoarece prima cifră a acestuia este de asemenea indescifrabilă. Se afișează 0.
Pe ultimul rând se afișează 2, deoarece sunt 2 coduri indescifrabile.
*/

// solutia oficiala, formatata
#include <fstream>
#include <iostream>

using namespace std;

int n, h, d;

char a[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
              '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'},
     c, cod[65], cod1[65];
char w[64] = {'0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '1', '0', '0',
              '0', '1', '1', '0', '1', '0', '0', '0', '1', '0', '1', '0', '1',
              '1', '0', '0', '1', '1', '1', '1', '0', '0', '0', '1', '0', '0',
              '1', '1', '0', '1', '0', '1', '0', '1', '1', '1', '1', '0', '0',
              '1', '1', '0', '1', '1', '1', '1', '0', '1', '1', '1', '1'};

int i, j, x, q, nrx = 0, nrg;

int main(void)
{
    ifstream fin("coduri.in");
    ofstream fout("coduri.out");

    fin >> n >> h >> d;

    for (i = 1; i <= n; i++) {
        fin >> c;

        if (c == 'H') {
            for (j = 1; j <= h; j++) {
                fin >> cod[j];

                if (cod[j] > '9')
                    q = cod[j] - 'A' + 10;
                else
                    q = cod[j] - '0';

                fout << w[4 * q + 0] << w[4 * q + 1] << w[4 * q + 2] << w[4 * q + 3];
            }
        } else if (c == 'D') {
            for (int k = 1; k <= d; k++)
                fin >> cod1[k];

            for (j = 1; j <= h; j++) {
                x = (cod1[j * 4 - 3] - '0') * 8 + (cod1[j * 4 - 2] - '0') * 4 +
                    (cod1[j * 4 - 1] - '0') * 2 + (cod1[j * 4] - '0');
                fout << a[x];
            }
        } else {
            for (j = 1; j <= h; j++)
                fin >> cod[j];

            nrg = 0;
            for (int k = 1; k <= d; k++)
                fin >> cod1[k];

            for (j = 1; j <= h; j++) {
                if (cod[j] == 'X') {
                    if (cod1[j * 4 - 3] != 'X' && cod1[j * 4 - 2] != 'X' &&
                            cod1[j * 4 - 1] != 'X' && cod1[j * 4] != 'X') {
                        x = (cod1[j * 4 - 3] - '0') * 8 + (cod1[j * 4 - 2] - '0') * 4 +
                            (cod1[j * 4 - 1] - '0') * 2 + (cod1[j * 4] - '0');
                        cod[j] = a[x];
                    } else
                        nrg++;
                }
            }

            if (nrg > 0) {
                nrx++;
                fout << 0;
            } else
                for (j = 1; j <= h; j++)
                    fout << (char)cod[j];
        }

        fout << '\n';
    }

    fout << nrx;

    return 0;
}