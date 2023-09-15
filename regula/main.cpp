/*
Profesorul începe ora scriind pe tablă următorul şir de numere: 1 1 1 2 1 1 2 3 1 3 1 2 3 4 1 3
1 2 3 4 5 1 3 5 1 2 3 4 5 6 1 3 5 … Copiii îl întrerup şi anunţă că au găsit regula după care sunt construiţi succesiv termenii şirului, şi anume: se scrie 1 urmat de 1, apoi 1 2 urmate tot de 1, apoi 1 2 3 urmate de 1 şi 3, apoi 1 2 3 4 urmate tot de 1 şi 3 … tot aşa, la un moment dat după secvenţa 1, 2, …, k se scriu numerele impare de la 1 la k. Evident că acesta este un şir infinit. Începând numerotarea de la 1, avem, de exemplu, pe poziţia 3 valoarea 1, pe poziţia 4 valoarea 2, pe poziţia 8 valoarea 3 etc. Profesorul se bucură dar le spune la copii că pentru poziţii mari este greu de calculat în minte valorile din şir. Ştefan, elev bun la programare spune că poate scrie o sursă care să calculeze multe valori din şir.

Cerința
Dându-se o poziţie din şir se cere determinarea valorii care se află pe acea poziţie.
Dându-se o valoare, să se determine cea mai mică poziţie din şir pe care aceasta se află.

Date de intrare
De la tastatură se citesc două numere C şi V. Dacă avem C = 1, trebuie determinată valoarea de pe poziția V din șir. Dacă avem C = 2 se cere să determinăm cea mai mică poziție din șir unde avem valoarea V.

Date de ieșire
Pe ecran se va afișa un singur număr natural corespunzător rezultatului obținut pentru rezolvarea fiecărei
cerințe.

Restricții și precizări
1 ≤ C ≤ 2
Pentru 25% din punctaj, C = 1 și V ≤ 100.000
Pentru 25% din punctaj, C = 1 și 100.000 < V ≤ 1.000.000.000
Pentru 50% din punctaj, C = 2 și 1 < V ≤ 35.000
Exemplul 1:
Intrare

1
8
Ieșire

3
Explicație
C = 1, se cere valoarea de pe poziția 8. Aceasta este 3.

Exemplul 2:
Intrare

2
3
Ieșire

8
Explicație
C = 2, se cere cea mai mică poziție pe care se află valoarea 3. Aceasta este 8.
*/

#include <iostream>

using namespace std;

int main(void)
{
    long long c, v, s = 0, g, i;

    cin >> c >> v;

    if (c == 1) {
        for(g = 1;; g++) {
            s += (g + (g + 1) / 2);

            if (s >= v)
                break;
        }

        s -= (g + (g + 1) / 2);
        v -= s;

        if(v <= g) {
            cout << v << endl;

        } else {
            v -= g;
            cout << 2 * v - 1 << endl;

        }
    } else {
        for(i = 1; i <= v - 1; i++) {
            s += (i + (i + 1) / 2);
        }
        cout << s + v << endl;
    }

    return 0;
}