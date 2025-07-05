#include <fstream>
#include <climits>
#define ll unsigned long long

using namespace std;

ifstream fin("bomboane2.in");
ofstream fout("bomboane2.out");

int n;
long long v[100001];

void read() {
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> v[i];
}


long long progresie(long long a1, long long N) {
    return((2 * a1 + (N - 1) * n) * N / 2);
}

void solve() {
    long long ture_max = LLONG_MAX, k = 0, s = 0;
    for (int i = 1; i <= n; i++) {
        k = 0;
        long long st = 1, dr = 1000001;
        while (st < dr) {
            long long mid = ((st + dr) >> 1ll);
            if (v[i] >= progresie(i, mid)) {
                k = mid;
                st = mid + 1;
                if (v[i] >= progresie(i, mid + 1)) {
                    k = mid + 1;
                    st = mid + 2;
                }
            }
            else
                dr = mid - 1;
        }
        if (v[i] >= progresie(i, st))
            k = max(k, st);
        if (v[i] >= progresie(i, dr))
            k = max(k ,dr);
        ture_max = min(ture_max, k);
    }
    if (ture_max)
        for (int i = 1; i <= n; i++)
            s += progresie(i, ture_max);
    fout << s;
}

int main(){
    read();
    solve();
    return 0;
}