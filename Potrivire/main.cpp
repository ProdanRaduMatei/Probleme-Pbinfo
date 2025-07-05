#include <fstream>

#define ll long long

using namespace std;

ifstream cin("potrivire.in");
ofstream cout("potrivire.out");

long long sum;
int n, m, x;
int fr[100001];
short v[100001];


void citire() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        if (!fr[v[i]])
            fr[v[i]] = 1;
    }
    for(int i = 1; i <= n; i++) {
        int j = i + 1;
        int num = v[i];
        while (j <= n && j - i + 1 <= 5) {
            num = num * 10 + v[j];
            fr[num] = 1;
            j++;
        }
    }
}

void solve() {
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        if (fr[x] == 1) {
            sum += x;
            fr[x] = 2;
        }
    }
    cout << sum;
}

int main() {
    citire();
    solve();
    return 0;
}