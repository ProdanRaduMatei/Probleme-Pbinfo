#include <cstdio>
#include <algorithm>

using namespace std;

int nr, i, j, q, m, x, ok, n, total;
int prim[170], v[1001], a[22000];
char p[1010];

void eratostene() {
    p[1] = 1;
    nr = 0;
    for (i = 2; i <= 1009; i++)
        if (p[i] == 0) {
        nr++;
        prim[nr] = i;
        j = i + i;
        while (j <= 1009) {
            p[j] = 1;
            j = j + i;
        }
    }
}

int main() {
    eratostene();
    freopen("soft_prime.in","r",stdin);
    freopen("soft_prime.out","w",stdout);
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        v[x / 1000]++;
    }
    i = 0;
    total = 0;
    while (total < n / 2) {
        total += v[i];
        i++;
    }
    m = 1000 * (i - 1);
    rewind(stdin);
    scanf("%d", &n);
    q = 0;
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (x <= m) {
            ok = 1;
            for (j = 1; prim[j] * prim[j] <= x; j++)
                if (x % prim[j] == 0) {
                    ok = 0;
                    break;
                }
            if (ok) {
                q++;
                a[q] = x;
            }
        }
    }
    sort(a + 1, a + q + 1);
    for (i = 1; i <= q; i++)
        printf("%d ", a[i]);
    rewind(stdin);
    scanf("%d", &n);
    q = 0;
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (x > m) {
            ok = 1;
            for (j = 1; prim[j] * prim[j] <= x; j++)
                if (x % prim[j] == 0) {
                    ok = 0;
                    break;
                }
            if (ok) {
                q++;
                a[q] = x;
            }
        }
    }
    sort(a + 1, a + q + 1);
    for (i = 1; i <= q; i++)
        printf("%d ", a[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}