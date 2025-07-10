#include <iostream>
#include <fstream>
#include <climits>
#include <utility>

using namespace std;

ifstream fin("memory002.in");
ofstream fout("memory002.out");

int n, left, right, pmin, pmax, minim = INT_MAX, maxim = INT_MIN, x;
long long int s;

int main(void) {
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> x;
        if (x > maxim)
            maxim = x, pmax = i;
        if (x < minim)
            minim = x, pmin = i;
    }
    fin.clear();
    fin.seekg(0);
    if (pmin > pmax)
        swap(pmin, pmax);
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> x;
        if (pmin <= i)
            s += x;
        if (i >= pmax)
            break;
    }
    fout << s;
    return 0;
}