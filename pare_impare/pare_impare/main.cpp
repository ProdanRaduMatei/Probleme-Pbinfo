#include <iostream>

using namespace std;

/*
Se dau 3 numere naturale a, b și c.

Cerinţa
Stabiliți dacă dintre cele trei numere citite sunt mai multe numere pare sau mai multe impare.

Date de intrare
Programul citeşte de la tastatură 3 numere întregi separate prin spaţii.

Date de ieşire
Programul va afişa pe ecran mesajul pare dacă sunt cel puțin două numere pare dintre cele trei citite, despectiv mesajul impare în caz contrar.

Restricţii şi precizări
Numerele citite sunt mai mic decât 1.000.000.000
Exemplu 1:
Intrare

125 68 200
Ieşire

pare
Exemplu 2:
Intrare

125 681 2001
Ieşire

impare

*/

int main() {
    int a, b, c, nr_pare = 0, nr_impare = 0;
    cin >> a >> b >> c;
    if (a % 2 == 0) {
        nr_pare++;
    } else {
        nr_impare++;
    }
    if (b % 2 == 0) {
        nr_pare++;
    } else {
        nr_impare++;
    }
    if (c % 2 == 0) {
        nr_pare++;
    } else {
        nr_impare++;
    }
    if (nr_pare > nr_impare) {
        cout << "pare";
    } else {
        cout << "impare";
    }
    return 0;
}
