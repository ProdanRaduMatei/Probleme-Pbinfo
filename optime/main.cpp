#include <fstream>
#include <bitset>
#include <vector>

#define ll unsigned long long
#define N 2000000

using namespace std;

ifstream cin("optime.in");
ofstream cout("optime.out");

int task, k, x, a[401][201], v[201], sp[201];
ll s;
bitset <N + 1> e;
vector <int> prime;

void ciur() {
    int temp = 0;
    e[0] = e[1] = 1;
    for (int i = 2; i <= N; i++)
        if (!e[i])
            for (int j = (i << 1); j <= N; j += i)
                e[j] = 1;
    for (int i = 10; i <= N; i++) {
        if (i < 100 && !e[i])
            prime.push_back(i);
        else if (i > 100 && !e[i]) {
            temp = i % 100;
            if (temp >= 10)
            prime.push_back(temp);
        }
    }
}

void read() {
    cin >> task >> k;
    if (task == 2)
        cin >> x;
}

void build() {
    int p = 0;
    for (int i = 1; i <= 2 * k; i++)
        for (int j = 1; j <= k; j++) {
            a[i][j] = prime[p++];
            s += a[i][j] * (e[a[i][j]] == 1);
            if (a[i][j] > 10 && !e[a[i][j]])
                v[j]++;
        }
}

void solve() {
    if (task == 1)
        cout << s;
    else {
        int nr_prime = 0, maxi = -1, first = 0;
        for (int i = 1; i <= k; i++)
            sp[i] = sp[i - 1] + v[i];
        for (int i = x; i <= k; i++) {
            nr_prime = sp[i] - sp[i - x];
            if (nr_prime >= maxi) {
                maxi = nr_prime;
                first = i - x + 1;
            }
        }
        cout << first << "\n" << maxi << "\n";
    }
}

int main() {
    ciur();
    read();
    build();
    solve();
}   