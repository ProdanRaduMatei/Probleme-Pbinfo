/*
Cerinţă
Se dă un șir cu n elemente, numere naturale. Să se determine câte elemente ale șirului au număr impar de cifre.

Date de intrare
Programul va citi de la tastatură numărul n, apoi cele n elemente ale șirului.

Date de ieşire
Programul va afişa pe ecran valoarea cerută.

Restricţii şi precizări
n ≤ 100
elementele șirului sunt mai mici decât 109
Exemplu
Intrare

5
18 215 147 1256 7
Ieşire

3
Explicație
Elementele șirului cu număr impar de cifre sunt: 215 147 7.
*/

#include <iostream>

using namespace std;

int nr_cif(int n)
{
    if (n < 10)
        return 1;
    else
        return 1 + nr_cif(n / 10);
}

int main()
{
    int n, v[100], cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        if (nr_cif(v[i]) % 2 == 1)
            cnt++;
    cout << cnt;
    return 0;
}