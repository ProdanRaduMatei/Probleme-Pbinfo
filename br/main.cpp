#include <fstream>

using namespace std;

int v[15002], s[30004], n, k;

int CautareBinara(int k, int x) {
    int st, dr, mij, sol;
    st = k;
    dr = k + n - 1;
    sol = k - 1;
    while (st <= dr) {
        mij = (st + dr) / 2;
        if (s[mij] - s[k - 1] <= x) {
            st = mij + 1;
            sol = mij;
        }
        else
            dr = mij - 1;
    }
    sol -= (k - 1);
    return sol;
}

int main() {
    ifstream cin ("br.in");
    ofstream cout ("br.out");

    int a, b;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        s[i] = s[i - 1] + v[i];
    }
    for (int i = n + 1; i <= 2 * n; i++)
        s[i] = s[i - 1] + v[i - n];
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        cout << CautareBinara(a, b) << "\n";
    }
    return 0;
}