/*
Pentru un număr x numim asociat par al lui x numărul scris cu cifrele pare ale lui x. Dacă x nu are cifre pare, asociatul său par este 0. De exemplu, asociatul par al lui 7485 este 48, iar asociatul par al lui 791 este 0.

Cerinţă
Se dă un șir cu n numere naturale. Să se determine numărul din șir care are asociatul par maxim. Dacă există mai multe numere cu asociat par maxim se va determina numărul mai mare.

Date de intrare
Programul va citi de la tastatură numărul n, apoi cele n numere.

Date de ieşire
Programul va afişa pe ecran valoarea cerută.

Restricţii şi precizări
n ≤ 100
cele n numere sunt sunt mai mici decât 109
Exemplu
Intrare

5
19 410 1470 1256 70
Ieşire

1470
Explicație
Asociatul par al lui 19 este 0.
Asociatul par al lui 410 este 40.
Asociatul par al lui 1470 este 40.
Asociatul par al lui 1256 este 26.
Asociatul par al lui 70 este 0.

Valoarea maximă a asociatului par este 40. Există două numere care îl au pe 40 ca asociat par, dintre care este mai mare 1470.
*/

#include <iostream>

using namespace std;

int asociat_par(int n)
{
    int aux = n, p = 1, nr = 0;
    while (aux)
    {
        if (aux % 2 == 0)
        {
            nr = nr + (aux % 10) * p;
            p = p * 10;
        }
        aux = aux / 10;
    }
    return nr;
}

int main()
{
    int n, v[100], max = 0, nr = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        if (asociat_par(v[i]) > max)
            max = asociat_par(v[i]);
    for (int i = 0; i < n; i++)
        if (asociat_par(v[i]) == max)
            if (v[i] > nr)
                nr = v[i];
    cout << nr;
    return 0;
}