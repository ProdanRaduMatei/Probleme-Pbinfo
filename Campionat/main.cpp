#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (log2(n) == (int)log2(n))
        cout << (int)log2(n);
    else
        cout << -1;
    return 0;
}
