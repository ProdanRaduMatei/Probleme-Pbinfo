#include <fstream>
#define ll long long

using namespace std;

ifstream cin("pagini.in");
ofstream cout("pagini.out");

short t;
int n, p;
ll fr[12];

void desc(int x) {
    for (int i = 1; i <= x; i++) {
        int k = i;
        while (k) {
            fr[k % 10]++;
            k /= 10;
        }
    }
}

void parcurgere() {
    short inceput = 0;
    if (!fr[0])
        inceput = 1;
    short sfarsit = 9;
    if (!fr[9])
        sfarsit = p;
    ll ct = 0;
    for (int i = inceput; i <= sfarsit; i++)
        if (fr[i] % 2)
            ct++;
    if (ct == 1 || ct == 0)
        cout << "DA" << "\n";
    else cout << "NU" << "\n";
}

void afisare() {
    for (int i = 0; i <= 9; i++)
        cout << i << " : " << fr[i] << "\n";    
}

void stergere() {
    for (int i = 0; i <= 9; i++)
        fr[i] = 0;
}

void read() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        for (int j = 1; j <= n; j++) {
            cin >> p;
            desc(p);
        }
        parcurgere();
        stergere();
    }
}

int main() {
    read();
}