#include <fstream>
#include <algorithm>
#include <deque>

using namespace std;

ifstream cin("sortsum.in");
ofstream cout("sortsum.out");

bool custom_sort(int a, int b) {
    return (a > b);
}

int sum(int x) {
    int s = 0;
    while(x) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main() {
    deque <int> v[65];
    int x;
    while (cin >> x)
        v[sum(x)].push_back(x);
    for (int i = 0; i < 65; i++) {
        sort(v[i].begin(), v[i].end(), custom_sort);
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
    }
}