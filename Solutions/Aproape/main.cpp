/*

Se dă un număr N în baza 10. Un număr M se numește aproape de N dacă îndeplinește următoarele trei condiții:

Are același număr de cifre cu N.
Reprezentarea în baza 10 diferă față de cea a lui N în exact o poziție. Altfel spus, nu mai mult, nici mai puțin, o singură cifră diferă.
Această cifră este fie cu 1 mai mică, fie cu 1 mai mare decât cifra corespunzătoare din N.
Exemplu: Să presupunem că N = 1903. Un exemplu de număr M care este aproape de N este 1913, pentru că diferă (doar) cifra zecilor, iar diferența între 0 (cifra zecilor în N) și 1 (cifra zecilor în M) este 1. Numerele 1903, 903 și 1893 nu sunt aproape de N.

Cerința
Cunoscând numărul N, să se scrie un program care determină:

Numărul de cifre ale acestui număr.
Numărul de numere aproape de N.
Numărul de numere aproape de cel puțin un număr aproape de N.
Date de intrare
Fișierul de intrare aproape.in conține pe prima linie un număr V a cărui valoare poate fi doar 1, 2 sau 3, iar pe a doua linie numărul natural N.

Date de ieșire
Dacă valoarea lui V este 1, atunci fișierul aproape.out va conține pe prima linie un singur număr ce reprezintă numărul de cifre ale lui N.

Dacă valoarea lui V este 2, atunci fișierul aproape.out va conține pe prima linie un singur număr natural ce reprezintă numărul de numere aproape de N.

Dacă valoarea lui V este 3, atunci fișierul aproape.out va conține pe prima linie un singur număr natural ce reprezintă numărul de numere aproape de un număr aproape de N.

Restricții și precizări
0 ≤ N < 1.000.000.000
Pentru teste în valoare de 20 de puncte avem V = 1.
Pentru teste în valoare de 30 de puncte avem V = 2.
Pentru teste în valoare de 50 de puncte avem V = 3.
Aveți grijă să nu numărați vreun număr de mai multe ori!
Exemplul 1:
aproape.in

1
1903
aproape.out

4
Exemplul 2:
aproape.in

2
1903
aproape.out

5
Explicație
Numerele aproape de 1903 sunt: 1803, 1902, 1904, 1913 și 2903.

Exemplul 3:
aproape.in

3
1903
aproape.out

15
Explicație
Cele 15 numere sunt: 1703, 1802, 1804, 1813, 1901, 1903, 1905, 1912, 1914, 1923, 2803, 2902, 2904, 2913 și 3903.
*/

#include <fstream>
#include <stack>
#include <algorithm>
#define ll long long

using namespace std;

ifstream cin("aproape.in");
ofstream cout("aproape.out");

ll n;
int cerinta;
stack <ll> stiva;
ll total3;
ll v[1001];
int lungime = 0;

void solve1() {

    cin >> n;
    ll t = n;
    
    int cifre = 0;
    if (!t)
        cifre++;

    while (t) {
        t /= 10;
        cifre++;
    }

    cout << cifre;

}

ll exponentiere(int baza, int e) {

    if (!e)
        return 1;
    else if (e % 2 == 1)
        return baza * exponentiere(baza, e - 1);
    ll P =exponentiere(baza, e / 2);
    return P * P;

}


void solve2() {

    cin >> n;
    ll aproape = 0;
    ll m = n;

    if (!n) 
        aproape++;
    

    while (n) {

        ll cifra = n % 10;

        if (cifra + 1 <= 9) 
            aproape++;
        
        if (n <= 9) {
            
            if (m == 1)
                aproape++;
            else if (m != 1 && cifra - 1 > 0)
                aproape++;
                
        }
        else if (n > 9 && cifra - 1 >= 0) 
            aproape++;
        


        n /= 10;
    }

    cout << aproape;
    
   
  
}



bool cautare_binara(ll x) {

    int st = 1, dr = lungime, mid = 0;
    int poz = 0;

    while (st <= dr) {
        
        mid = (st + dr) / 2;

        if (x <= v[mid]) {
            dr = mid - 1;
            poz = mid;
        }
        else st = mid + 1;

    }

    if (v[poz] != x)
        return 0;
    else return 1;


}


void tempsolve(ll x) {

    ll m = x;
    int ordin = 0;
    
    if (!x) {

        if (!cautare_binara(1)) {
            v[++lungime] = 1;
            sort(v + 1, v + 1 + lungime);
        }
    }

    while (x) {

        ll cifra = x % 10;
        ll add = exponentiere(10, ordin);
        
        if (cifra + 1 <= 9) {
            if (!cautare_binara(m + add)) {
                v[++lungime] = m + add;
                sort(v + 1, v + 1 + lungime);
            }
        }


        if (x <= 9 /*&& cifra - 1 > 0*/) {

            if (m == 1) {
                if (!cautare_binara(0)) {
                    v[++lungime] = 0;
                    sort(v + 1, v + 1 + lungime);
                }
            }
            else if (m != 1 && cifra - 1 > 0) {

                if (!cautare_binara(m - add)) {
                    v[++lungime] = m - add;
                    sort(v + 1, v + 1 + lungime);
                }
                

            }
        }
        else if (x > 9 && cifra - 1 >= 0) {

            if (!cautare_binara(m - add)) {
                v[++lungime] = m - add;
                sort(v + 1, v + 1 + lungime);
            }
        
        }


        x /= 10;
        ordin++;
    }


}



void solve3() {


    cin >> n;
    ll m = n;
    int ordin = 0;

    if (!n) {
        stiva.push(1);
    }

    while (n) {

        ll cifra = n % 10;
        ll add = exponentiere(10, ordin);

        if (cifra + 1 <= 9) {
            stiva.push(m + add);
        }


        if (n <= 9) {

            if (m == 1) 
                stiva.push(0);
            else if (m != 1 && cifra - 1 > 0) 
                stiva.push(m - add);
            
        }
        else if (n > 9 && cifra - 1 >= 0) 
            stiva.push(m - add);
        


        n /= 10;
        ordin++;
    }




    while (!stiva.empty()) {
        ll x = stiva.top();
        tempsolve(x);
        stiva.pop();
    }

    cout << lungime;




}


void read() {

    cin >> cerinta;
    if (cerinta == 1)
        solve1();
    else if (cerinta == 2) {
        solve2();
    }
    else solve3();
        


}

int main(){
    read();
}