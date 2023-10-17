#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

static int prime(int a) {
    int i, j, bound;
    if (a == 0 || a == 1)
        return 0;
    if (a == 2 || a == 3 || a == 5)
        return 1;
    if (a % 2 == 0 || a % 3 == 0 || a % 5 == 0)
        return 0;
    bound = sqrt((double) a);
    i = 7;
    j = 11;
    while (j <= bound && a % i && a % j) {
        i += 6;
        j += 6;
    }
    if ((j <= bound) || ((i <= bound) && (a % i == 0)))
        return 0;
    return 1;
}

static int count_divisors(int n) {
    int d = 2, c = 1, e;
    while (n > 1) {
        e = 0;
        while (n % d == 0) {
            n /= d;
            e++;
        }
        if (e)
            c *= (e + 1);
        d++;
        if (d * d > n)
            d = n;
    }
    return c;
}

int main(void) {
    int n, x, c = 0, i;
    ifstream fin("prim013.in");
    ofstream fout("prim013.out");
    fin >> n;
    for (i = 0; i < n; i++) {
        fin >> x;
        if (prime(count_divisors(x)))
            c++;
    }
    fout << c;
    return 0;
}