#include <fstream>
#include <bitset>
#define LIMIT 1000000
#define ll long long
using namespace std;

ifstream cin("maxdiv.in");
ofstream cout("maxdiv.out");

int v[1001], n;
bitset <1000001> eratostene;
long long maxi, nr_secv;
int prime[80001], m, st, dr, lmax, l, pst, pdr;
short task;
int maxiold;

void ciur() {
    for (int i = 1; ((i * i) << 1) + (i << 1) <= LIMIT; i++)
        if (!eratostene[i])
            for (int j = ((i * i) << 1) + (i << 1); (j << 1) + 1 <= LIMIT; j += ((i << 1) + 1))
                eratostene[j] = 1;
    prime[++m] = 2;
    for (int i = 3; i <= LIMIT; i += 2)
        if (!eratostene[i / 2])
            prime[++m] = i;
}

long long nr_div(int x) {
    int d = 1;
    long long p = 0, rtn = 1;
    while (x > 1) {
        p = 0;
        while (!(x % prime[d])) {
            x /= prime[d];
            p++;
        }
        rtn *= (p + 1);
        d++;
        if (x > 1 && prime[d] * prime[d] > x) {
            rtn *= 2;
            break;
        }
    }
    return rtn;
}

void read() {
    cin >> n >> task;
    long long rtn = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] == 2 || (v[i] % 2 == 1 && !eratostene[v[i] / 2]))
            rtn = 2;
        else
            rtn = nr_div(v[i]);
        if (maxi < rtn) {
            maxiold = maxi;
            maxi = rtn;
            nr_secv = 1;
            l = 1;
            st = i;
        }
        else if (maxi > rtn)
            l++;
        else if (maxi == rtn) {
            l++;
            nr_secv++;
            if (lmax < l || maxiold < maxi) {
                maxiold = maxi;
                lmax = l;
                pst = st;
                pdr = i;
            }
            st = i;
            l = 1;
        }
    }
    if (task == 1)
        cout << nr_secv - 1;
    else
        for (int i = pst; i <= pdr; i++)
            cout << v[i] << " ";
}

int main() {
    ciur();
    read();
}