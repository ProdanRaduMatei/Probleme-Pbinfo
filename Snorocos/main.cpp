#include <iostream>

using namespace std;

int n;
int main()
{
    cin >> n;
    if (n % 2 == 0)
        cout << "NU ESTE NOROCOS";
    else
        for (int i = n / 2 + 1; i <= n + n / 2; ++i)
            cout << i << " ";
    return 0;
}
