#include <iostream>

using namespace std;

int main()
{
    int n, v[101];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    int ok = 1;
    for (int i = 0; i < n; ++i)
        if (v[i] == 1 && v[i + 1] == 1) {
            ok = 0;
            break;
        }
    if (ok == 1)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
