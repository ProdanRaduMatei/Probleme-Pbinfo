#include <iostream>

using namespace std;

int n, t, m, k, sab, p, nr, j, u, l, pi, pj, ci, cj, suma, prod, c, pc, r, i, a;

int main()
{
    cin >> n >> t >> m;
    k = n;
    p = 0;
    sab = 0;
    while(k != 0) {
            k = k / 10;
        p++;
        sab = sab * 10 + p;
    }
    for(k = 1; k <= m; k++) {
            cin >> i >> j;
        if(i > j) {
            u = i;
            i = j;
            j = u;
        }
        pi = 1;
        pj = 1;
        for(l = 1; l <= p - i; l++)
            pi = pi * 10;
        for(l = 1; l <= p - j; l++)
            pj = pj * 10;
        ci = ( sab / pi ) % 10;
        cj = ( sab / pj ) % 10;
        sab = sab - ci * pi;
        sab = sab - cj * pj;
        sab = sab + cj * pi;
        sab = sab + ci * pj;
    }
    k = 0;
    nr = n;
    do {
            k++;
    a = sab;
    suma = 0;
    prod = 1;
    while (a != 0) {
            r = a % 10;
    pc = 1;
    for(i = 1; i <= p - r; i++)
        pc = pc * 10;
    c = (nr / pc) % 10;
    suma = suma + c * prod;
    prod = prod * 10;
    a = a / 10;
    }
    nr = suma;
    }while(nr != n);
    t = t % k;
    nr = n;
    for (i = 1; i <= t; i++) {
        a = sab;
        suma = 0;
        prod = 1;
        while ( a != 0 ) {
            r= a % 10;
            pc = 1;
            for(j = 1; j <= p - r; j++)
                pc = pc * 10;
            c = ( nr / pc ) % 10;
            suma = suma + c * prod;
            prod = prod * 10;
            a = a / 10;
        }
        nr = suma;
    }
    cout << nr;
    return 0;
}
