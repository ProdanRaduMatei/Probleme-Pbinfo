#include <iostream>

using namespace std;

struct sir {
    long long x, s;
};

int main() {
    long long n, k, w;
    sir v[1000001];
    cin >> n >> k >> w;
    cin >> v[1].x;
    v[1].s = v[1].x;
    for (int i = 2; i <= n; ++i) {
        cin >> v[i].x;
        v[i].s = v[i - 1].s + v[i].x;
    }
    
    return 0;
}
