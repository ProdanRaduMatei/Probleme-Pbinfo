#include <fstream>
#include <vector>

using namespace std;

int main() {
    int n;
    ifstream f("secv011.in");
    f >> n;
    vector<int> frq(3 * n + 1);
    frq[n] = 1;
    int ps = 0;
    int64_t sol = 0;
    for (int i = 1; i <= n; ++i) {
        bool x;
        f >> x;
        ps += x;
        sol += frq[2 * i - 3 * ps + n]++;
    }
    ofstream g("secv011.out");
    g << sol << '\n';
    return 0;
}