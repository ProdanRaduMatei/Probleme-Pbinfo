#include <iostream>

using namespace std;

int sum_cifra_control(int a, int b) {
    return (b - a) / 9 + 1;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << sum_cifra_control(a, b);
    return 0;
}
