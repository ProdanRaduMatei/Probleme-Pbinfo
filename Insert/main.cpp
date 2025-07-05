#include <iostream>
using namespace std;

void Insert(int a[], int &n)
{
    int i, k = 0;
    for (i = 0; i < n; ++i)
        if (a[i] % 2)
            ++k;;
    int j = n + k - 1;
    for (i = n - 1; i >= 0; --i) {
        if (a[i] % 2)
            a[j--] = 2 * a[i];
        a[j--] = a[i];
    }
    n = n + k;
}

int main()
{
    int n, a[800000];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    Insert(a, n);
    cout << n;
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    return 0;
}
