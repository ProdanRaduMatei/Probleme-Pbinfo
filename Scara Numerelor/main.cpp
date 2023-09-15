#include <iostream>

using namespace std;

int main()
{
    int n, i, e, l;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        for (l = 1; l <= i; ++l) {
            for (e = 1; e <= i; ++e) {
                cout << i;
            }
            cout << endl;
        }
    }
    return 0;
}
