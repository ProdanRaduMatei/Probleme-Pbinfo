#include <iostream>

using namespace std;

int main()
{
    int c, p;
    cin >> c >> p;
    c = c - (p*(p - 1)) / 2;
    cout << c % p;
    return 0;
}
