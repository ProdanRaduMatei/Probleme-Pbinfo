#include <iostream>

using namespace std;

int main()
{
    int n, nr = 0, f = 5;
    cin >> n;
    while (f <= n) {
        int ff = f;
        while (ff % 5 == 0) {
            ff = ff / 5;
            ++nr;
        }
        f = f + 5;
    }
    cout << nr;
    return 0;
}
