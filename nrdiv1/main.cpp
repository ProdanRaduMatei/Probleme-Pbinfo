#include <fstream>
#include <bitset>
#include <vector>
#define ll long long

using namespace std;

ifstream cin("nrdiv.in");
ofstream cout("nrdiv.out");

const int sqrt_vmax = 3165001;
int n;
ll x;
bitset <3165001> v;
vector <ll> prime;
void ciur() {
    for (int i = 1; ((i * i) << 1) + (i << 1) <= sqrt_vmax; ++i)
        if (!v[i])
            for (int j = ((i * i) << 1) + (i << 1); (j << 1) + 1 <= sqrt_vmax; j += ((i << 1) + 1))
                v[j] = 1;
    prime.push_back(2);
    for (int i = 3; i <= sqrt_vmax; i += 2)
        if (!v[i / 2])
            prime.push_back(i);
}

ll nr_div() {
    ll divizori = 1;
    ll d = 0;
    int p = 0;
    if (x == 1)
        return 1;
    while (x != 1) {
        p = 0;
        while (x % prime[d] == 0) {
            x /= prime[d];
            ++p;
        }
        divizori *= (p + 1);
        d++;
        if (x > 1 && prime[d] * prime[d] > x) {
            divizori *= 2;
            break;
        }
    }
    if (divizori == 1)
        return 2;
    return divizori;
}

void read() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        cout << nr_div() << "\n";
    }
}

int main() {
    ciur();
    read();
}