#include <fstream>
#include <bitset>

using namespace std;

ifstream cin("numere9.in");
ofstream cout("numere9.out");

const int NMAX = 6 * (1e4);
int n, x;
bitset <NMAX + 1> e;

int main() {
    cin >> n;
    for (int i = 1; i <= n * n; i++) {
        cin >> x;
        if (x <= NMAX)
            e[x] = 1;
    }
    for (int i = 1; i <= NMAX; i++)
        if (!e[i]) {
            cout << i << " "; 
            break;
        }
    for (int i = min(NMAX, n * n); i >= 1; i--)
        if (!e[i]) {
            cout << i;
            break;
        }
}