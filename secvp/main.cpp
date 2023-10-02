#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

ifstream cin("secvp.in");
ofstream cout("secvp.out");

const int N = 1000100;
bitset <N + 1> e;
vector <int> v;
int n, k, x, s;
int a[100001];
int iteratii[100001], sp[100001], nr, secv, mini = 10000000;

void ciur() {
    e[0] = e[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!e[i]) {
            v.push_back(i);
            for (int j = i * 2; j <= N; j += i)
                e[j] = 1;       
        }
    }
}

void read_solve1() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        auto it = lower_bound(v.begin(), v.end(), x);
        auto it2 = upper_bound(v.begin(), v.end(), x);
        int d1 = distance(v.begin(), it);
        int d2 = distance(v.begin(), it2);
        if (e[x]) {
            if (d1 > 0) {
                s += min(abs(x - v[d1 - 1]), abs(x - v[d2]));
                iteratii[i] = min(abs(x - v[d1 - 1]), abs(x - v[d2]));
                if (iteratii[i] == abs(x - v[d1 - 1]))
                    iteratii[i] *= -1;
            }
            else { 
                s += abs(x - v[d2]);
                iteratii[i] = abs(x - v[d2]);
            }
        }
        a[i] = x + iteratii[i];
        if (iteratii[i] < 0)
            iteratii[i] *= -1;
        sp[i] = sp[i - 1] + iteratii[i];
    }
    cout << s << "\n";
}

void solve2() {
    int temp = 0;
    for (int i = k; i <= n; i++) {
        temp = sp[i] - sp[i - k];
        if (temp < mini) {
            mini = temp;
            secv = 1;
        }
        else if (temp == mini)
            secv++;
    }
    cout << mini << " " << secv;
}

int main() {
    ciur();
    read_solve1();
    solve2();
}