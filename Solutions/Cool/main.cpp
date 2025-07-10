#include <fstream>
#include <vector>
#include <unordered_map>
#define big 1000000001

using namespace std;

ifstream cin("cool.in");
ofstream cout("cool.out");

int task, n, k;
vector <int> v;

void read() { 
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
}

void solve1() {
    int maxi = -1, mini = big;
    unordered_map <int, int> m;
    int p = 0;
    for (int i = 0; i < k; i++) {
        m[v[i]]++;
        maxi = max(maxi, v[i]);
        mini = min(mini, v[i]);
        if (m[v[i]] == 1)
            p++;
        else if (m[v[i]] == 2)
            p--;
    }
    if (maxi - mini + 1 == k)
        cout << maxi;
    else
        cout << p;
}


void solve2() {
    int maxi = -1, mini = big, lmax = 0, secvente = 0;
    for (int i = 0; i < n - 1; i++) {
        unordered_map <int, bool> m;
        maxi = mini = v[i];
        m[v[i]] = 1;
        for (int j = i + 1; j < n; j++) {
            mini = min(mini, v[j]);
            maxi = max(maxi, v[j]);
            if (m[v[j]] == 1)
                break;
            m[v[j]] = 1;
            if (maxi - mini + 1 == j - i + 1) {
                if (lmax < j - i + 1)
                    lmax = j - i + 1, secvente = 1;
                else if (lmax == j - i + 1)
                    secvente++;
            }
        }
    }
    cout << lmax << "\n" << secvente;
}

int main() {
    cin >> task >> n >> k;
    read();
    if (task == 1)
        solve1();
    else
        solve2();
}