#include <iostream>

using namespace std;

int main() {
    int n, i, cnt = 0;
    cin >> n;
    for (i = 2; cnt < n; i = i + 2) {
        cout << i << " ";
        ++cnt;
    }
    return 0;
}
