#include <fstream>
#include <vector>
#include <set>
#include <unordered_map>
#define big 1000000000
#define ll long long

using namespace std;

ifstream cin("gard.in");
ofstream cout("gard.out");

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t, n, x;
    cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> n;
        unordered_map <long long, long long> m; 
        set <long long> inaltimi;
        bool erase = 0, ok = 1;
        long long mini = big;
        for (int j = 1; j <= n; j++) {
            cin >> x;
            m[x]++;
        }
        for (auto e : m) {
            inaltimi.insert(e.second);
            mini = min(mini, e.second);
        }
        if (inaltimi.size() >= 3)
            ok = 0;
        else if (inaltimi.size() == 2 && mini == 1)
            ok = 1;
        else {
            for (auto it = m.begin(); it != m.end() && ok; it++) {
                if (it -> second != mini) {
                    long long a = it -> second;
                    if (abs(a - mini) == 1 && !erase)
                        erase = 1;
                    else if (abs(a - mini) == 1 && erase)
                        ok = 0;
                    if (abs(a - mini) > 1)
                        ok = 0;
                }
            }
        }
        cout << ok << "\n";
    }
}