#include <stdio.h>

FILE *fin, *fout;


int poz[100010];
long long n, i, j, k, sum, vi;

int main()
{   fin = fopen("roata.in", "r");
    fout = fopen("roata.out", "w");
    fscanf(fin, "%lld", &n);
    for (i = 0; i < n; i++) {
        fscanf(fin, "%lld", &j);
        poz[j - 1] = i;
    }
    k = 0;
    j = 0;
    sum = 0;
    vi = 0;
    for (i = 0; i < n; i++) {
        k = n - (sum + poz[i]) % n;
        if (k <= j)
            vi += n;
        j = k;
        k = k + vi;
        sum += k;
        fprintf(fout, "%lld ", k);
    }
    return 0;
}