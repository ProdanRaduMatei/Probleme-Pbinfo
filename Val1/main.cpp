#include <iostream>
using namespace std;

short n, m;

int main()
{
    cin >> n >> m;
    for (int j = 1; j <= m; ++j)
        cout << "__0_0___";
    cout << endl;
    if (n > 1) {
        for (int i = 2; i < n; ++i) {
            for (int j = 1; j <= m; ++j)
                cout << "_0___0__";
            cout << endl;
        }
        for (int j = 1; j <= m; ++j)
            cout << "0_____0_";
        cout << endl;
    }
    return 0;
}
