#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <map>
#include <cmath>
#include <chrono>

using namespace std;
#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL
#define mod 1000000007
#define lsb (i & -i)

ifstream cin("beculete1.in");
ofstream cout("beculete1.out");

int n, m;
vector<pair<int, int> > v;
int op, x, y;

int main() {
    cin >> n >> m;
    for (int i = 1 ; i <= m ; ++i) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            v.push_back({x, y});
        }
        else {
            int apare = 0;
            cin >> x;
            for (auto i : v)
                if (x >= i.first && x <= i.second)
                    apare++;
            
            if (apare % 2 == 0)
                cout << "S\n";
            else
                cout << "A\n";
        }
    }
    return 0;
}