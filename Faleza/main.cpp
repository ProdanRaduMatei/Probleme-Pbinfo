#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("faleza.in");
ofstream fout("faleza.out");

char x;
int a[200001], b[200001], i, n, poza, pozb, k;

int main() {
    fin >> n;
    for (i = 1; i <= n; i++) {
        fin >> x;
        a[i] = x - '0';
    }
    for (i = 1; i <= n; i++) {
        fin >> x;
        b[i] = x - '0';
    }
    i = 1;
    while (a[i] == 0 && b[i] == 0) {
        k++;
        a[i] = b[i] == k;
        i++;
        if (i == n + 1)
            break;
    }
    if (a[i] == 1)
        poza = 1;
    else if (b[i] == 1)
        pozb = 1;
        while (i < n) {
            while (a[i] == 0 && b[i] == 0) {
                k++;
                a[i] = b[i] == k;
                i++;
                if (i == n + 1)
                    break;
            }
            if (i == n + 1)
                break;
            if (a[i] == 1) {
                poza = 1;
                pozb = 0;
            }
            else if (b[i] == 1) {
                pozb = 1;
                poza = 0;
            }
            if (poza == 1) {
                while (a[i + 1] == 1 and i != n + 1)
                    i++;
                if (i == n)
                    break;
                else
                    if (a[i + 1] == 0 and b[i] == 0) {
                        i++;
                        k++;
                        a[i] = b[i - 1] = k;
                    }
                else if (a[i + 1] == 0 and b[i] != 0) {
                    i++;
                    poza = 0;
                    pozb = 1;
                }
                else if (a[i + 1] == 0 and b[i] != 0 and b[i + 1] != 0) {
                    i++;
                    poza = 0;
                    pozb = 1;
                }
                if (i == n && a[i] == 0 && b[i] == 0)
                    k++;
            }
            else if (pozb == 1) {
                while (b[i + 1] == 1 and i != n + 1)
                    i++;
                if (i == n)
                    break;
                if (b[i + 1] == 0 and a[i] == 0) {
                    i++;
                    k++;
                    b[i] = a[i - 1] = k;
                }
                else if (b[i + 1] == 0 and a[i] != 0) {
                    i++;
                    poza = 1;
                    pozb = 0;
                }
                else if (b[i + 1] == 0 and a[i] != 0 and a[i + 1] != 0) {
                    i++;
                    poza = 1;
                    pozb = 0;
                }
                if (i == n && a[i] == 0 && b[i] == 0)
                    k++;
            }
        }
    fout << k;
    return 0;
}