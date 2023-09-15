#include <iostream>

using namespace std;

int bitcmp(int a, int b) {
    if (a < b)
        return -1;
    if (a == b)
        return 0;
    if (a > b)
        return 1;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << bitcmp(a, b);
    return 0;
}
