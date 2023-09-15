#include <iostream>

using namespace std;

int sumaDeSume(int x) {
    return x * (x + 1) * (x + 2) / 6;
}

int main()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        cout << sumaDeSume(x) << " ";
    }
    return 0;
}
