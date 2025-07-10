#include <iostream>

using namespace std;

int main() {
    int n, minim = 1001, maxim = 0, x;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        if (x > maxim)
            maxim = x;
        if (x < minim)
            minim = x;
    }
    cout << minim + maxim;
    return 0;
}
