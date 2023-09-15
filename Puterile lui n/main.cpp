#include <iostream>

using namespace std;

int main() {
    int n;
    long long p, c;
    cin >> n >> p;
    for (c = 1; c <= p; c = c * n) {
        cout << c;
    }
    return 0;
}
