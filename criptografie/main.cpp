#include <fstream>
#include <queue>
#include <vector>

using namespace std;

ifstream cin("criptografie.in");
ofstream cout("criptografie.out");

queue <int> q;
int n, k, task;
int v[100001], fr[201];
long long ans;
char c;

void read() {
    cin >> task >> k >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        v[i] = c;
    }
}

void solve1() {
    int p = 1;
    for (int i = 1; i <= n; i++) {
        fr[v[i]]++;
        if (fr[v[i]] > k) {
            while (fr[v[i]] > k) {
                fr[v[p]]--;
                p++;
            }
        }
        ans += i - p + 1;
    }
    cout << ans;
}

void decide(int &st, int &dr, int &st2, int &dr2) {
    for (int j1 = st, j2 = st2; j1 <= dr && j2 <= dr2; j1++, j2++) {
        if (v[j1] < v[j2])
            break;
        else if (v[j1] > v[j2]) {
            st = st2;
            dr = dr2;
            break;
        }
    }
}

void solve2() {
    int p = 1, lmax = 0, st = 0, dr = 0;
    for (int i = 1; i <= n; i++) {
        fr[v[i]]++;
        q.push(v[i]);
        if (fr[v[i]] > 1) {
            while (fr[v[i]] > k) {
                fr[v[p]]--;
                q.pop();
                p++;
            }
        }
        int length = i - p + 1;
        if (lmax < length) {
            st = i - length + 1;
            dr = i;
            lmax = length;
        }
        else if (lmax == length) {
            int st2 = i - length + 1;
            int dr2 = i;
            decide(st, dr, st2, dr2);
        }
    }
    for (int i = st; i <= dr; i++)
        cout << char(v[i]);
}

int main() {
    read();
    if (task == 1)
        solve1();
    else
        solve2();
}