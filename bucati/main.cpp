/*
Gigel se joacă din nou cu numerele. El taie un număr natural în bucăți mai mici și adună bucățile, observând faptul că se obțin sume diferite. Evident, dacă rotește, la stânga sau la dreapta, cifrele numărului și repetă operația de tăiere, se obțin alte sume. De exemplu numărul 12345 se poate tăia în bucățile 1, 2, 3 și 45 sau, dacă rotește numărul cu 2 poziții la dreapta și obține 45123, acesta se poate tăia în bucățile 4, 512 și 3 și așa mai departe. El stabilește următoarele proprietăți ale unei tăieri:

doar una dintre bucăţi trebuie să conţină cel puțin două cifre;
bucăţile pot fi formate doar din cifre 0 sau pot începe cu cifra 0;
după aplicarea tăierii, trebuie să se obţină cel puţin 3 bucăţi;
costul unei tăieri este egal cu suma bucăţilor obţinute.
O tăiere specială este o tăiere care respectă, în plus, următoarele două condiţii:

bucăţile au cel mult trei cifre;
costul este un număr prim.
Cerința
Scrieţi un program care citește un număr natural și determină:
1. costul maxim al unei tăieri
2. costul minim al unei tăieri speciale

Date de intrare
Fișierul de intrare bucati.in conține pe prima linie cerința (1 sau 2). Linia următoare conține un număr natural n.

Date de ieșire
Fișierul de ieșire bucati.out va conține o singură linie pe care va fi scris un număr natural determinat conform cerinței.

Restricții și precizări
999 < n < 1.000.000.000
Pentru datele de test se garantează existența soluției
Exemplul 1:
bucati.in

1
12353
bucati.out

536
Explicație
Cerinţa este 1, trebuie determinat costul maxim al unei tăieri. Costul maxim se obţine pentru numărul 53123, obţinut prin două rotaţii la dreapta din numărul iniţial, care se împarte în bucățile 531 2 3. Se obţine costul 536

Exemplul 2:
bucati.in

2
12533
bucati.out

23
Explicație
Cerinţa este 2, trebuie determinat costul minim al unei tăieri speciale. Se observă că există mai multe soluții de a obține cost minim 12 5 3 3; 3 12 5 3; 3 3 12 5; 5 3 3 12.

Exemplul 3:
bucati.in

2
78409
bucati.out

109
Explicație
Cerinţa este 2, trebuie determinat costul minim al unei tăieri speciale. Bucățile se obţin din numărul 84097 obţinut printr-o rotaţie la stânga cu o poziţie: 8 4 0 97.

Exemplul 4:
bucati.in

2
908834033
bucati.out

857
Explicație
Cerinţa este 2, trebuie determinat costul minim al unei tăieri speciale. Bucățile pot fi: 9 0 8 834 0 3 3.
*/
/*

Pirnog Theodor Ioan
Colegiul National "B. P. Hasdeu"

*/

#include <fstream>
#include <climits>
using namespace std;

fstream cin("bucati.in");
ofstream cout("bucati.out");

short cerinta;
int n, cost, x;
int maxi, mini=INT_MAX;
int cifre, v[11], v2[11]; 

// pentru cerinta=2
/*

-exista o singura bucata cu mai mult de 2 cifre
-cel putin 3 bucati
-cost prim
-cel mult 3 cifre/bucata
-


*/

int fcifre(int x) {

    int cif = 0;
    while (x) {
        
        x /= 10;
        cif++;
        
    }

    return cif;

}
void creare(int x) {

    int index = n;
    while (x) {
        v[index] = x % 10;
        x /= 10;
        index--;
    }

}
void afisare() {
    
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    cout << "\n";
    
}
int prim(int x) {

    if (x <= 3)
        return (x >= 2);
    if (x % 2 == 0 || x % 3 == 0)
        return 0;
    else {
        for (int d = 5; d * d <= x; d += 6)
            if (x % d == 0 || x % (d + 2) == 0)
                return 0;
    }

    return 1;
}
int functienr() {

    int prima = v[1];
    for (int i = 1; i < n; i++)
        v[i] = v[i + 1];


    v[n] = prima;


    if (!v[1])
        return 0;
    else {

        int nr = 0;
        for (int i = 1; i <= n; i++)
            nr *= 10, nr += v[i];

        return nr;
    }



}
int switchpozmaxim() {

    for (int j = 1; j <= n; j++) {

        int g = functienr();
        
        if (!g) 
            for (int i = 1; i <= n; i++) 
                g = g * 10 + v[i];

        maxi = max(maxi, g);

    }

    return maxi;

}
void solve1() {

    int p = switchpozmaxim();

    int a = p % 10;
    p /= 10;
    int b = p % 10;
    p /= 10;
    cout << a + b + p;

}




void rotire() {
    int prima = v2[1];
    for (int i = 1; i < n; i++)
        v2[i] = v2[i + 1];
    v2[n] = prima;
}

int parcurgere(int param) {

    int p = 0;
    for (int i = param; i <= n; i++)
        p *= 10, p += v2[i];

    return p;
}

int sumcif(int x) {

    int s = 0;
    while (x) {
        s += (x % 10);
        x /= 10;
    }

    return s;
}



int cifre2() {

    int minim = INT_MAX;
    int a, k;
    for (int i = 1; i <= n; i++) {

        rotire();
        
            
        if (v2[1])
            k = parcurgere(1);
        else k = parcurgere(2);

            a = k % 100;
            k /= 100;
            int sum = sumcif(k);
        
            if (prim(a + sum)) 
                minim = min(minim, a + sum);

    }


    return minim;
}


int cifre3() {

    int minim = INT_MAX;
    int a, k;
    for (int i = 1; i <= n; i++) {

        rotire();
        

        if (v2[1])
            k = parcurgere(1);
        else k = parcurgere(2);

            a = k % 1000;
            k /= 1000;
            int sum = sumcif(k);
            if (prim(a + sum)) {
                if (minim > a + sum)
                    minim = a + sum;
            }

        

    }


    return minim;
}





void creare2() {

    int temp = x;
    int cif = n;
    while (temp) {
        v2[cif] = temp % 10;
        temp /= 10;
        cif--;
    }
}


void solve2() {

    creare2();
    int mini1 = cifre2();
    int mini2 = cifre3();
    if (mini1 < mini2)
        cout << mini1;
    else cout << mini2;

}


void read() {

    cin >> cerinta >> x;
    
    n = fcifre(x);
    creare(x);

}


int main() {
    
    read();
    if (cerinta == 1)
        solve1();
    else solve2();
    
}