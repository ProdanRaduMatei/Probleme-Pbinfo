#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("brain.in");
ofstream fout("brain.out");

int a[1000001];

int main(void) {
    int n, x, i;
    long long maxim = 0, minim = 1, j = 0;
    fin >> n;
    for (i = 1; i <= n; i++) {
        fin >> x;
        if (x == i) {
            a[j] = x;
            j++;
        }
    }
    for (i = 0; i < j; i++) {
        fout << a[i] << " ";
        maxim += a[i];
    }
    fout << endl << maxim << endl;
    i = 0;
    while (a[i] <= minim && i <= j)
        minim += a[i++];
    fout << minim << endl;
    return 0;
}