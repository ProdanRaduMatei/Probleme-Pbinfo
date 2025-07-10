#include <fstream>
#include <bitset>
#include <vector>
#define N 100000
#define M 44780

using namespace std;

ifstream cin("forta.in");
ofstream cout("forta.out");

short task;
int n, maxi, x, maxi2;
int v[N + 1];
int d[N + 1];
int fr[N + 1];
vector <int> prime;
bitset <M + 1> e;

void read() {
    cin >> task >> n;
    for (int i = 1; i <= n; i++) 
        cin >> v[i];
}

void ciur() {
    e[0] = e[1] = 1;
    for (int i = 2; i <= M; i++)
        if (!e[i])
            for (int j = i * 2; j <= M; j += i)
                e[j] = 1;
    for (int i = 2; i <= M; i++)
        if (!e[i])
            prime.push_back(i);
}

int nr_divizori(int x) {
    int d = 1;
    int k = 0;
    while (x > 1) {
        int putere = 0;
        while (x % prime[k] == 0) {
            x /= prime[k];
            putere++;
        }
        d *= (putere + 1);
        k++;
        if (x > 1 && prime[k] * prime[k] > x) {
            d *= 2;
            break;
        }
    }
    return d;
}

void solve() {
    for (int i = 1; i <= n; i++) {
        d[i] = nr_divizori(v[i]);
        fr[d[i]]++;
        if (d[i] > maxi) {
            maxi = d[i];
            x = v[i];
        }
        else if (d[i] == maxi)
            x = min(x, v[i]);
    }
    for (int i = 1; i <= N; i++)
        maxi2 = max(maxi2, fr[i]);
    if (task % 2)
        cout << x;
    else
        cout << maxi2;
}


int main() {
    read();
    ciur();
    solve();
}