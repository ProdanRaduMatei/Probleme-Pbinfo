#include <iostream>

using namespace std;

int main() {
    int a, b, d = 1;
    cin >> a >> b;
    while (d <= b)
    {
        cout << d * a << " ";
        ++d;
    }
    return 0;
}
