#include <fstream>
#define ll unsigned long long

using namespace std;

ifstream fin("tomi.in");
ofstream fout("tomi.out");

long long masca = (1LL << 60) - 1, mini = (1LL << 60) - 1;
int n, k;
long long v[100001];

void read() {
    fin >> n >> k;
    for (int i = 1; i <= n; i++)
        fin >> v[i];
}

void solve() {
    long long temp = 0, ct = 0, t = 0;
    for (int i = 59; i >= 0; i--) {
        temp = (1LL << i);
        t = (masca ^ temp);
        ct = 0;
        for (int j = 1; j <= n; j++)
            if ((t & v[j]) == v[j])
                ct++;
        if (ct >= k && t < mini) {
            mini = t;
            masca = t;
        }
    }
    fout << mini;
}

int main() {
    read();
    solve();
    fin.close();
    fout.close();
    return 0;
}