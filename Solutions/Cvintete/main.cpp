#include <fstream>
#include <math.h>

#define M 1000000007
#define ll long long
#define N 25000
#define P 1235789

using namespace std;

ll n, d, k, i, x, a, b, c, w, sol;
ll z, m, j, e, nr, dc, y, l, u, h, ma, mb;
ll di[N], f[N], pp[N], v[P];

ll gcd( ll A, ll B) {
    ll r = A % B;
    while (r != 0) {
        A = B;
        B = r;
        r = A % B;
    }
    return B;
}

int main() {
    ifstream cin("cvintete.in");
    ofstream cout("cvintete.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> d;
    m = 0;
    for (i = 1; i <= n; i++) {
        cin >> x;
        f[x]++;
        if (x > m)
            m = x;
    }
    for (i = 1; i <= m; i++) {
        if ((d % i == 0)and(f[i] > 0)) {
            k++;
            di[k] = i;
        }
        pp[i] = i * i;
        v[pp[i] % P] = i;
    }
    for (i = 1; i <= k - 2; i++) {
        a = di[i];
        for (j = i + 1; j <= k - 1; j++) {
            b = di[j];
            e = a * b;
            if (d % e == 0) {
                c = d / e;
                if (c > b)
                    if (c <= m)
                    if(f[c] > 0){
                        nr = f[a] * f[b] * f[c];
                        w = c * c;
                        dc = gcd( a, b );
                        if (w % dc == 0) {
                            l = (ll)sqrt(w / b);
                            for (u = 1; u <= l; u++)
                                if ((w - b * pp[u]) % a == 0) {
                                    z = (w - b * pp[u]) / a;
                                    h = v[z % P];
                                    if (h * h == z)
                                        if ((h != u) and (h <= m))
                                        sol += nr * f[u] * f[h];
                                }
                        }
                    }
            }
        }
    }
    cout << sol % M << endl;
    return 0;
}