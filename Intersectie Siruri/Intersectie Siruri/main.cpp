#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("intersectie.in");
ofstream fout("intersectie.out");

struct sir {
    int x, ok;
};
int poz;

void verifApar(int x, int l, sir v[]) {
    int s = 1, d = l;
    while (s <= d) {
        int m = (s + d) / 2;
        if (v[m].x == x) {
            v[m].ok = 1;
            break;
        }
        if (v[m].x > x)
            d = m - 1;
        if (v[m].x < x)
            s = m + 1;
    }
}

void eliminare(int l, sir v[]) {
    for (int i = 1; i <= l; ++i)
        if (v[i].ok == 0) {
            for (int j = i; j <= l; ++j) {
                v[j].x = v[j + 1].x;
                v[j].ok = v[j + 1].ok;
            }
            --l;
            --i;
        }
}

void resetare(int l, sir v[]) {
    for (int i = 1; i <= l; ++i)
        v[i].ok = 0;
}

int main() {
    sir v[100001];
    int l = 0, x;
    cin >> v[++l].x;
    while (v[l].x != 0) {
        cin >> v[++l].x;
        v[l].ok = 0;
    }
    for (int i = 1; i <= 3; ++i) {
        cin >> x;
        verifApar(x, l, v);
        while (x != 0) {
            cin >> x;
            verifApar(x, l, v);
        }
        eliminare(l, v);
        resetare(l, v);
    }
    for (int i = 1; i <= l; ++i)
        cout << v[i].x << " ";
    return 0;
}
