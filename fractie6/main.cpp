/**
Cerința
Se dă un numar n și n perechi de numere naturale a și b.Să se determine dacă a/b este fracție finită sau periodică, iar dacă este fracție periodică să se determine dacă este fracție periodică simplă sau mixtă.

Date de intrare.
Se citește de la tastatură un număr n și apoi n perechi de numere a b.

Date de ieșire
Programul afișează pentru fiecare pereche citită, pe câte un rând, mesajul fractie finita, fractie periodica simpla sau fractie periodica mixta în funcție de caz.

Restricții și precizări
1 ≤ n ≤ 100
1 ≤ a , b ≤ 1.000.000.000, numere naturale
Exemplu:
Intrare

5
2 5
7 90
90 270
50 81000
9 3
Ieșire

fractie finita
fractie periodica mixta
fractie periodica simpla
fractie periodica mixta
fractie finita
*/

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int main() {
    long long int a, b;
    long long int n;
    cin >> n;
    for (long long int i = 1; i <= n; i++) {
        cin >> a >> b;
        long long int aux1 = a, aux2 = b;
        while (aux2 != 0) {
            long long int r = aux1 % aux2;
            aux1 = aux2;
            aux2 = r;
        }
        b /= aux1;
        long long int ok25 = 0, okk = 0, copieB = b;

        long long int j = 2;
        while (b != 1) {
               while (b % j == 0) {

                   if (j == 5 || j == 2)
                    ok25++;
                else
                    okk++;

                b /= j;
            }
               j++;
               if (j * j > b)
                   j = b;
        }
        if (ok25 != 0 && okk == 0 || copieB == 1)
            cout << "fractie finita";
        else if (okk != 0 && ok25 == 0)
            cout << "fractie periodica simpla";
        else 
            cout << "fractie periodica mixta";
        
                
        cout << '\n';
    }
    return 0;
}