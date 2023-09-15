#include <bits/stdc++.h>
using namespace std;
int a, b, c, ic = -1, sc = 0, i, v[1000000], difa, difb, lg, f[1000000];
bool gasit;
struct elem {
    int va, vb, dad, op;
};
elem C[1000000], now;
int main() {
    cin >> a >> b >> c;
    ic++;
    while (ic <= sc) {
        now = C[ic];
        ic++;
        if (!f[1000 * a + now.vb]) {
            sc++;
            C[sc].va = a;
            C[sc].vb = now.vb;
            C[sc].dad = ic - 1;
            C[sc].op = 1;
            f[1000 * a + now.vb] = 1;
        }
        if (C[sc].va == c || C[sc].vb == c)
            break;
        if (!f[1000 * now.va + b]) {
            sc++;
            C[sc].va = now.va;
            C[sc].vb = b;
            C[sc].dad = ic - 1;
            C[sc].op = 2;
            f[1000 * now.va + b] = 1;
        }
        if (C[sc].va == c || C[sc].vb == c)
            break;
        if (!f[now.vb]) {
            sc++;
            C[sc].va = 0;
            C[sc].vb = now.vb;
            C[sc].dad = ic - 1;
            C[sc].op = 3;
            sc++;
            f[now.vb] = 1;
        }
        if (!f[1000 * now.va]) {
            sc++;
            C[sc].va = now.va;
            C[sc].vb = 0;
            C[sc].dad = ic - 1;
            C[sc].op = 4;
            f[1000 * now.va] = 1;
        }
        if (C[sc].va == c || C[sc].vb == c)
            break;
        if (now.va > b - now.vb) {
            difa = now.va - b + now.vb;
            difb = b;
        }
        else {
            difa = 0;
            difb = now.vb + now.va;
        }
        if (!f[1000 * difa + difb]) {
            sc++;
            C[sc].va = difa;
            C[sc].vb = difb;
            C[sc].dad = ic - 1;
            C[sc].op = 5;
            f[1000 * difa + difb] = 1;
        }
        if (C[sc].va == c || C[sc].vb == c)
            break;
        if (now.vb > a - now.va) {
            difb = now.vb - a + now.va;
            difa = a;
        }
        else {
            difb = 0;
            difa = now.va + now.vb;
        }
        if (!f[1000 * difa + difb]) {
            sc++;
            C[sc].va = difa;
            C[sc].vb = difb;
            C[sc].dad = ic - 1;
            C[sc].op = 6;
            f[1000 * difa + difb] = 1;
        }
        if (C[sc].va == c || C[sc].vb == c)
            break;
    }
    i = sc;
    while (i) {
        lg++;
        v[lg] = C[i].op;
        i = C[i].dad;
    }
    cout << lg << '\n';
    for (i = lg; i >= 1; i--) {
        switch (v[i]) {
            case 1:
                cout << "R A\n";
                break;
            case 2:
                cout << "R B\n";
                break;
            case 3:
                cout << "A C\n";
                break;
            case 4:
                cout << "B C\n";
                break;
            case 5:
                cout << "A B\n";
                break;
            case 6:
                cout << "B A\n";
                break;
        }
    }
    return 0;
}
