#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    while (a)
    {
        cout << a * b << " ";
        --a;
    }
    return 0;
}
