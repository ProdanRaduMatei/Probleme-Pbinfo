#include <iostream>

using namespace std;

int main()
{
    int n, i;
    cin >> n;
    if (n % 2 == 0)
        i = n - 1;
    else
        i = n;
    for (; i >= 1; i = i - 2)
        cout << i << " ";
    return 0;
}
