#include <iostream>

using namespace std;

int main()
{
    int n, v[1000];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 2; i <= n; i = i + 2)
        cout << v[i] << " ";
    cout << endl;
    if (n % 2 == 0)
        for (int i = n - 1; i >= 1; i = i - 2)
            cout << v[i] << " ";
    else
        for (int i = n; i >= 1; i = i - 2)
            cout << v[i] << " ";
    return 0;
}
