/*
pyk
Fie k, n și y trei numere naturale. Fie X un șir format din n numere naturale: x1,x2,x3,…,xn
. Fie P produsul numerelor y,x1,x2,x3,…,xn
, adică P=y×x1×x2×x3×…×xn
. Numărul P este o “k-putere” dacă există un număr natural z astfel încât P=zk
.

Cerințe
Scrieți un program care să citească numerele k,n,x1,x2,x3,…,xn
 și care să determine:

1. cel mai mic și cel mai mare număr din șirul X ce sunt formate doar din cifre identice;
2. descompunerea în factori primi a celui mai mic număr natural y (y ≥ 2) cu proprietatea că numărul P=y×x1×x2×x3×…×xn
 este o “k-putere”.
Date de intrare
Fișierul de intrare pyk.in conține:

pe prima linie, un număr natural C, reprezentând cerința din problemă care trebuie rezolvată (1 sau 2);
pe a doua linie, numerele naturale k și n, separate printr-un singur spațiu;
pe a treia linie, cele n numere naturale x1,x2,x3,…,xn
, separate prin câte un singur spaţiu.
Date de ieșire
Dacă C=1, atunci prima linie a fişierului de ieşire pyk.out va conține două numere naturale, separate printr-un
singur spațiu, reprezentând răspunsul la cerința 1 a problemei. Dacă nu există astfel de numere, prima linie a
fișierului va conține valoarea 1.

Dacă C=2, atunci fișierul de ieşire pyk.out va conține:

pe prima linie, un număr natural m reprezentând numărul de factori primi distincți din descompunerea în
factori primi a numărului y, determinat la rezolvarea cerinței 2;
pe fiecare dintre următoarele m linii (câte o linie pentru fiecare factor prim din descompunerea în factori primi
a lui y), câte două valori F şi E, separate printr-un singur spaţiu, reprezentând factorul prim F și exponentul
E al acestui factor din descompunerea în factori primi a lui y.
Scrierea în fișier a acestor factori primi se va face în ordinea crescătoare a valorii lor.

Restricții și precizări
2 ≤ n ≤ 50.000
2 ≤ k ≤ 100
2 ≤  x1,x2,x3,…,xn
 ≤ 10.000
2 ≤ y
pentru rezolvarea corectă a cerinței 1 se acordă 10 puncte;
pentru rezolvarea corectă a cerinței 2 se acordă 90 puncte.
Exemplu:
pyk.in

1
2 7
122 1111 5 4 88 123 999
pyk.out

4 1111 
Explicație
Cerința este 1, k=2, n=7. Numerele din șirul X formate doar din cifre identice sunt: 1111, 5, 4, 88, 999. Cel mai mic număr dintre acestea este 4, iar cel mai mare este 1111.

pyk.in

2
3 6
12 5 60 125 4 36
pyk.out

3
2 1
3 2
5 1
Explicație
Cerința este 2, k=3, n=6. Produsul celor 6 numere din șir este: 12*5*60*125*4*36=64800000. y=90 este cea mai mică valoare pentru care P = 90 * 64800000 = 18003 devine o “k-putere“. Descompunerea în factori primi a lui y conține m=3 factori
primi: 21×32×51
*/

#include <fstream>
#include <bitset>
using namespace std;

ifstream cin("pyk.in");
ofstream cout("pyk.out");

bitset<10000> E;

int identic(int x)
{
while(x > 9)
    {
        if(x % 10 != x / 10 % 10)
            return 0;
        x = x / 10;
    }
    return 1;
}
int main()
{
    long long c , n , k = 0 , s = 0 , max = -1 , x , min = 2000000000 , P[100000] , a[100000] = {0};

    cin >> c >> k;
    int ck = k;
    if(c == 1)
    {
        cin >> n;

        for(int i = 1 ; i <= n ; i++)
        {
            cin >> x;

            if(identic(x) && x > max)
                max = x;
            if(identic(x) && x < min)
                min = x;
        }
        if(max == -1)
            cout << 1;
        else
            cout << min << " " << max;
    }
    if(c == 2)
    {

        int max = 10000 , cp = 0 , f , n , cnt = 0;
        cin >> n;
        for(int i = 2 ; i * i <= max ; i++)
            if(E[i] == 0)
                for(int j = i * i ; j <= max ; j = j + i)
                    E[j] = 1;
        for(int i = 2 ; i <= max ; i++)
            if(E[i] == 0)
                P[++cp] = i;
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> x;
            int d = 1;

            while(x > 1)
            {
                if(f != x)
                f = P[d];
                if(x % f == 0)
                {
                    int e = 0;

                    while(x % f == 0)
                        {
                            x = x / f;
                            e++;
                        }
                        a[f] = a[f] + e;
                    d++;
                }
                else
                    d++;
                if(P[d] * P[d] > x && x > 1)
                    f = x;
            }
        }
    for(int i = 2 ; i <= max ; i++)
        if(a[i] != 0 && a[i] % k != 0)
            cnt++;
        if(cnt == 0)
            cout << 1 << endl << 2 << " " << k;
        else
        {
        cout << cnt << endl;
        for(int i = 1 ; i <= max ; i++)
            if(a[i] != 0 && a[i] % k != 0)
                cout << i << " " <<  k - a[i] % k << endl;
        }
    }
}