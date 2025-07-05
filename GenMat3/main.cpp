#include <iostream>

using namespace std;

int main()
{
    int n, m, i = 1;
    cin >> n >> m;
    for (int cnt = 1; cnt <= n * m; ++cnt) {
        cout << i * i << " ";
        i = i + 2;
        if (cnt % m == 0)
            cout << endl;
    }
    return 0;
}
