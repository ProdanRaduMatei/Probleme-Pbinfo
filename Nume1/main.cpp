/*
De ziua lui, vrăjitorul Arpsod a primit în dar un animăluț mic și pufos. Evident, acesta dorește să îi dea un nume. Pentru a fi protejat de răul și blaturile existente în Univers, Arpsod a decis să îi dea un nume strict legat de numărul său protector. Cunoscând numărul protector, numele animăluțului se va determina astfel: Va fi un șir de litere MARI ale alfabetului latin, de lungime minimă cu proprietatea că suma diferențelor în modul a literelor vecine este egală cu numărul lui Arpsod.
Concret: dacă avem numele FLAFFY, obținem:
|F – L| + |L – A| + |A – F| + |F – F| + |F – Y| =
= |6 – 12| + |12 – 1| + |1 – 6| + |6 – 6| + |6 – 25|=
= 6 + 11 + 5 + 0 + 19 = 41
Deci codul numelui FLAFFY este 41

Cerința
Arpsod vă oferă onoarea de a afla numele micuțului său animăluț.

Date de intrare
În fișierul nume1.in, pe prima și singura linie, se va afla P, numărul protector dat de Arpsod.

Date de ieșire
În fișierul nume1.out, pe prima și singura linie se va afișa un șir de litere MARI ale alfabetului latin, cu proprietățile cerute în enunț.

Restricții și precizări
1 ≤ P ≤ 4.000.000
A = 1, B = 2, C = 3… Z = 26
În cazul în care șirul afișat are suma corectă și număr minim de caractere, primiți 20% din punctajul pe acel test.
Dacă șirul afișat are proprietățile de mai sus și este și minim lexicografic, primiți punctajul integral pe acel test.
Un șir A este mai mic lexicografic decât un șir B dacă pe prima poziție unde A[i] ≠ B[i], A[i] < B[i].
Exemplu:
nume1.in

19
808
nume1.out

AT
ARAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAY
Explicație
În primul exemplu: A = 1, T = 20, |A – T| = |1 – 20| = 19
*/

// Implementare: Cristi Dospra
// Punctaj: 100p
// Complexitate: O(N)

#include <fstream>
#include <cmath>
using namespace std;

/*
* N = suma ceruta pentru sirul cerut
* bestLen = numarul de caractere pe care il va avea sirul cerut
* currentLen = cate caractere am folosit pana acum
* las = ultimul caracter pus
*/

ifstream fin("nume1.in");
ofstream fout("nume1.out");

int N, bestLen, currentLen;
char last = 'A';

// functie ce verifica daca pot pune un anumit caracter
bool potPune(int trebuie, char c) {

    int sum = abs(last - c); // vad cat se adauga la suma daca pun caracterul meu

    int ramase = bestLen - currentLen - 1; //vad cate caractere imi mai raman de pus

    // daca o sa mai pot pune macar unul
    if (ramase > 0) {
        sum += max(abs(c - 'A'), abs(c - 'Z')); // pun 'A' sau 'Z', ce e mai departe de caracterul meu
        ramase--; //si raman cu unul mai putin
    }

    sum += ramase * 25; //de restul pun numa 'A' si 'Z' alternativ (ca sa scot suma maxima)

    //daca am obtinut o suma mai mare sau egala totul e ok
    if (sum >= trebuie)
        return true;

    //daca nu, nu
    return false;
}

int main() {

    fin >> N; //suma ceruta a sirului

    bestLen = (N / 25) + 1 + (N % 25 != 0); //numarul de caractere pe care il va avea sirul

    fout << 'A'; //primul element va fi mereu 'A'
    currentLen = 1; //am pus momentan un singur element

    int sum = 0; //suma pe care o dau elementele de pana acum
    while (currentLen < bestLen) {

        for (int i = 'A'; i <= 'Z'; ++i) { //incerc sa pun fiecare caracter, il iau pe primul care merge

            if (potPune(N - sum, i)) { //daca il pot pune

                if (currentLen == bestLen - 1 && sum + abs(last - i) != N) //daca e ultimul element, adaugat, atunci e unic
                    continue;

                sum += abs(last - i); // adaug la suma ce imi creeaza noul element

                fout << (char)i; //il afisez
                currentLen++; //il adaug la sir
                last = i; //el este acum ultimul adaugat

                break; //nu mai are rost sa continui
            }
        }
    }

    return 0;
}