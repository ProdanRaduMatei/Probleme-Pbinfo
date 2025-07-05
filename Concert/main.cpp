#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct muzica {
int inregistrare, durata;
} melodie[100];

int timp_secunde(char* timp) {
    int numar, este_minut = 1,secunde = 0;
    char *text = strtok(timp, ":");
    while (text != NULL)  {
        numar = 0;
        for (int i = 0; i < strlen(text); i++)
            numar = 10 * numar + (text[i] - '0');

        if (este_minut > 0) {
            numar = numar * 60;
            este_minut = 0;
        }
        secunde = secunde + numar;
        text = strtok(NULL, ":");
    }
    return secunde;
}

void sorteaza_durata(muzica melodie[], int n) {
    int min, temp;
    for (int i = 1; i <= n - 1; i++) {
        min = i;
        for (int j = i + 1; j <= n; j++)
            if (melodie[j].durata < melodie[min].durata)
                min = j;
        if (min != i) {
            melodie[temp] = melodie[i];
            melodie[i ]= melodie[min];
            melodie[min] = melodie[temp];
        }
    }
}

void afiseaza_lista(muzica melodie[], int n) {
    for(int i = 1; i <= n; i++)
        cout << melodie[i].inregistrare << " " << melodie[i].durata << endl;
}

int main() {
    int T, M, n, indice_melodie[10], nr_melodii = 0;
    char timp[100];
    ifstream fic("concert.in");
    ofstream foc("concert.out");
    fic >> n >> T;
    fic.getline(timp, 100);
    for(int i = 1; i <= n; i++) {
        fic.getline(timp, 100);
        melodie[i].inregistrare = i;
        melodie[i].durata = timp_secunde(timp);
    }
    sorteaza_durata(melodie, n);
    while (1) {
        nr_melodii++;
        T = T - melodie[nr_melodii].durata;
        if (T < 0) {
            nr_melodii--;
            break;
        }
        indice_melodie[nr_melodii] = melodie[nr_melodii].inregistrare;
    }
    foc << nr_melodii << endl;
    for (int i = 1; i <= nr_melodii; i++)
        foc << indice_melodie[i] << " ";
    return 0;
}
