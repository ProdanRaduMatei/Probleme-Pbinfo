#include <iostream>
using namespace std;
int main()
{
    int numar_total_randuri, pret_total = 0, matrice[100][100] = {0};
    cin >> numar_total_randuri;
    for (int rand = 0; rand < numar_total_randuri; rand++) {
        for (int coloana = rand; coloana < numar_total_randuri - rand; coloana++) {
            if (matrice[rand][coloana] == 0)
                matrice[rand][coloana] = rand + 1;
            if (matrice[coloana][rand] == 0)
                matrice[coloana][rand] = rand + 1;
            if (matrice[numar_total_randuri - rand - 1][coloana] == 0)
                matrice[numar_total_randuri - rand - 1][coloana] = rand + 1;
            if (matrice[coloana][numar_total_randuri - rand - 1] == 0)
                matrice[coloana][numar_total_randuri - rand - 1] = rand + 1;
        }
    }
    cout << (numar_total_randuri + 1) / 2 << endl;
    for (int rand = 0; rand < numar_total_randuri; rand++) {
        for (int coloana = 0; coloana < numar_total_randuri; coloana++) {
            cout << matrice[rand][coloana];
        }
        cout << endl;
    }
    int pret_actual = 1, numar_prajituri = numar_total_randuri;
    while (numar_prajituri > 0) {
        pret_total = pret_total + pret_actual * numar_prajituri * numar_prajituri;
        numar_prajituri -= 2;
        pret_actual++;
    }
    cout << pret_total;
}
