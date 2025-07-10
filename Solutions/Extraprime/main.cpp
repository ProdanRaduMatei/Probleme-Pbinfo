#include <fstream>
#include <bitset>
#define N 10000000

using namespace std;

ifstream cin("extraprime.in");
ofstream cout("extraprime.out");

bitset <N + 1> e, fr;
int a, b, t, maxi = -1, mini = N;

void ciur() {
    e[0] = e[1] = 1;
    for (int i = 2; i <= N; i++)
        if (!e[i])
            for (int j = i * 2; j <= N; j += i)
                e[j] = 1;
}

bool eliminare(int x) {
    int pow10 = 1, get = 0, k = 0;
    if (e[x])
        return 0;
    while (pow10 <= x) {
        get = x % pow10;
        k = x / pow10 / 10;
        k = k * pow10 + get;
        if (e[k])
            return 0;
        pow10 *= 10;
    }
    return 1;
}

int main() {
    ciur();
    cin >> a >> b;
    int r = 0;
    for (int i = a; i <= b; i++) {
        r = eliminare(i);
        t += r;
        if (r == 1) {
            maxi = max(maxi, i);
            mini = min(mini, i);
        }
    }
    cout << t << "\n" << mini << "\n" << maxi;
}