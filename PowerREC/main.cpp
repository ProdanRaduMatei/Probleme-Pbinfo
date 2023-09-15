#include <iostream>

using namespace std;

int main()
{
    int a, b;
    long long P = 1;
    cin >> a >> b;
    for (int i = 1; i <= b; ++i)
        P = P * a;
    cout << P;
    return 0;
}
