/*
Cerința
Pentru a câștiga niște bani în plus, Ștefan s-a decis să deschidă un magazin nou de clătite pentru următorul sezon estival, deoarece toată lumea e înnebunită dupa clătite vara. Magazinul va vinde n tipuri de clătite, fiecare dintre ele având un cod anume(două clătite pot avea același cod), în funcție de tipul clătitei.

Pentru a afla prețul unei clătite, Ștefan a găsit un algoritm interesant pentru a decide prețul clătitei. Pentru că numerele prime sunt favoritele sale, prețul va depinde de cât de “primă” este clătita.

Astfel:

Prețul inițial al clătitei e x euro, x fiind dat în datele de intrare.

Dacă codul clătitei e un număr prim, prețul crește cu cod + p euro, unde cod e valoarea codului și p e dat în datele de intrare.

Pentru fiecare cifră primă din cod (2, 3, 5, 7), prețul va crește cu d[i] euro, unde valorile d[i] sunt date în datele de intrare.

Dacă suma cifrelor codului este număr prim, prețul crește cu sc euro, unde sc e suma cifrelor codului.

Dacă produsul cifrelor codului este număr prim, prețul crește cu pd euro, unde pd e produsul cifrelor din cod.

Din păcate, această metodă poate să nu ducă la un profit îndeajuns de mare și acum a venit vremea să îl ajutați pe Ștefan să obțină cel mai mare profit posibil. Pentru a realiza acest obiectiv, puteți să schimbați cel mult o cifră din fiecare cod pentru a maximiza suma prețurilor clătitelor.

Totuși, nu puteți face prima cifră egală cu 0 pentru a obține un număr cu o cifră mai puțin, chiar dacă ar putea fi cea mai profitabilă alegere.

Date de intrare
Pe prima linie programul va citi numărul n, reprezentând numărul de clătite disponibile în magazinul lui Ștefan.

Pe cea de-a doua linie, programul va citi n numere, reprezentând codurile clătitelor.

Cea de-a treia linie va conține două valori, x și p, cu semnificația din enunț.

Cea de-a patra linie va conține patru valori, d[2] , d[3], d[5], d[7].

Date de ieșire
Programul va afișa pe ecran profitul maxim pe care Ștefan îl poate obține după modificarea convenabilă a codurilor clătitelor.

Restricții și precizări
1 ≤ n ≤ 100 000
1 ≤ cod[i] ≤ 999 999
1 ≤ x, p, d[i] ≤ 1 000 000
Pentru teste în valoare de 30 de puncte, 1 ≤ n ≤ 1000.
Exemplu:
Intrare

4
12 89 941 101
5 7
8 5 3 9
Ieșire

1907
Explicație
Trebuie să schimbăm prima valoare de la 12 la 17 și vom obține un profit de 45.

Este optim să păstrăm al doilea cod la 89 pentru un profit de 118.

Trebuie să schimbăm cea de-a treia valoare de la 941 la 991 și vom obține un profit de 1022.

Trebuie să schimbăm cea de-a patra valoare de la 101 la 701 și vom obține un profit de 722.

Suma profiturilor va deveni 1907.
*/

#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
 
// #define fisier 1
 
using namespace std;
 
typedef long long ll;
 
const int mod = 1000000007;
const double dancila = 3.14159265359; // PI 
const double eps = 1e-9;
 
int n, v[100002];
int x, p;
int d[12];

bool prim[1000002];
int prod[1000002];
int sc[1000002];
int price[1000002];

void precompute()
{
    prim[0] = 1, prim[1] = 1; 
    
    for(int i = 2; i <= 1000000; ++i) 
        if(!prim[i])
            for(int j = i+i; j <= 1000000; j += i)
                prim[j] = 1;
    
    for(int i = 1; i <= 1000000; ++i)
    {
        int nr = i;
        int pc = 1;
        int sc = 0;
        
        price[i] += x; 
        
        if(!prim[i]) 
            price[i] = price[i] + p + i;
        while(nr)
        {
            int dg = nr%10;
            if(!prim[dg]) 
                price[i] += d[dg];
            pc *= dg;
            sc += dg;
            nr /= 10;
        }
        
        if(!prim[sc]) 
            price[i] += sc;
            
        if(!prim[pc]) 
            price[i] += pc; 
    }
}


 
int main()
{
    #ifdef fisier
        ifstream cin("input.in");
        ofstream cout("output.out");
    #endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    cin >> n;
    
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    
    cin >> x >> p;
    
    cin >> d[2] >> d[3] >> d[5] >> d[7];
    
    precompute();
    
    
    ll ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        deque<int> d;
        int nr = v[i];
        int val = price[v[i]];
        int wh = v[i];
        while(nr)
        {
            d.push_front(nr%10);
            nr /= 10;
        }
        int coef = 1;
        for(int poz = d.size() - 1; poz >= 0; --poz)
        {
            int nr = v[i] - d[poz] * coef + (poz == 0) * coef;
            for(int nd = 0 + (poz == 0); nd <= 9; ++nd)
            {
                if(price[nr] > val)
                    val = price[nr], wh = nr;
                nr += coef;
            }
            coef *= 10;
        }
        ans += val;
    }
    cout << ans;
    return 0;
}