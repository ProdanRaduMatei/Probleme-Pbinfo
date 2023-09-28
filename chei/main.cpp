#include <iostream>
#include <fstream>

using namespace std;

int x, y, z, v[101], poz;

ifstream fin("chei.in");
ofstream fout("chei.out");

int prim(int n){
    if (n < 2)
        return 0;
    if (n > 2 && n % 2 == 0)
        return 0;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

int suma_factori_primi(int n) {
    int s = 0, d = 2;
    while (n != 1) {
        if (n % d == 0) {
            s += d;
            while (n % d == 0)
                n /= d;
        }
        if (d > 2)
            d += 2;
        else
            d++;
    }
    return s;
}

int main() {
    fin >> x >> y;
    fout << x << " " << y << " ";
    poz = 2;
    v[1] = x;
    v[2] = y;
    bool stop = true;
    while (stop) {
        x = v[poz - 1];
        y = v[poz];
        while (y > 9)
            y /= 10;
        if (x % 10)
            z = (x % 10) * 10 + y;
        else
            z = y;
        if (prim(z) || z == 1) {}
        else
            z -= suma_factori_primi(z);
        v[++poz] = z;
        if (z == v[poz - 3] || z == v[poz - 2] || z == v[poz - 1]) {
            stop = false;
            continue;
        }
        fout << z << " ";
    }
    return 0;
}