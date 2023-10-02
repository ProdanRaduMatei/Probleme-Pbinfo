#include <fstream>

using namespace std;

ifstream cin("p2048.in");
ofstream cout("p2048.out");

int n, m, v[10001];
int fr[2049], elemente, x, y, z, st, dr, warning;
bool permutare;

void citire() {
    cin >> n >> m;
    st = 1;
    dr = n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        elemente++;
        y = max(y, v[i]);
        fr[v[i]] = 1;
    }
}

void parcurgere() {
    for (int i = st; i <= dr; i++)
        y = max(y, v[i]);
}

void afisare() {    
    cout << "st = " << st << " " << "dr= " << dr <<"\n";
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    cout << "\n";
}

void alinieredr() {
    int k = n;
    while (k >= 1) {
        int temp = k;
        while (!v[temp + 1] && temp + 1 <= n && v[k])
            temp++;
        v[temp] = v[k];
        if (temp != k)
            v[k] = 0;
        k--;
    }
    dr = n;
    st = n - elemente + 1;
}


void alinierest() {
    int k = 1;
    while (k <= n) {
        int temp = k;
        while (!v[temp - 1] && temp - 1 >= 1 && v[k])
            temp--;
        v[temp] = v[k];
        if (temp != k)
            v[k] = 0;
        k++;
    }
    st = 1;
    dr = elemente;
}


void dreapta() {
    int ct = 0;
    permutare = 0;
    for (int i = dr; i > st; i--) {
        if (v[i] == v[i - 1] && v[i]) {
            elemente--;
            permutare = 1;
            warning = 0;
            ct++;
            if (z < ct)
                z = ct;
            v[i] *= 2;
            fr[v[i]] = 1;
            v[i-1] = 0;
        }  
    }
    if (permutare) {
        x++;
        alinieredr();
    }
    else
        warning++;
}


void stanga() {
    int ct = 0;
    permutare = 0;
    for (int i = st; i < dr; i++) {
        if (v[i] == v[i + 1] && v[i]) {
            elemente--;
            permutare = 1;
            warning = 0;
            ct++;
            if (z < ct)
                z=ct;
            v[i] *= 2;
            fr[v[i]] = 1;
            v[i + 1] = 0;
        }
    }
    if (permutare) {
        x++;
        alinierest();
    }
    else
        warning++;
}


void solve() {
    int i = 1;
    char p;
    while (i <= m && !fr[2048] && warning != 2) {
        cin >> p;
        if (p == 'D')
            dreapta();
        else if (p == 'S')
            stanga();
        i++;
    }
    parcurgere();
    cout << x << "\n" << y << "\n" << z << "\n";
}

int main() {
    citire();
    solve();
}