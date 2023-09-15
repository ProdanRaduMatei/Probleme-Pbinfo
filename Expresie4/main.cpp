#include <iostream>

using namespace std;

int n, s, m;
int main()
{
    cin >> n;
    m = n;
    for (int i = 1; i <= n; ++i, --m)
        s = s + i * m;
    cout << "Rezultatul este " << s;
    return 0;
}
