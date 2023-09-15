#include <iostream>

using namespace std;

int n, s;
int main()
{
    cin >> n;
    for (int i = 2; i <= 2 * n; i = i + 2)
        s = s + i;
    cout << "Suma este " << s;
    return 0;
}
