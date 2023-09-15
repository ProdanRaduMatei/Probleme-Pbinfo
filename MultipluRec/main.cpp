#include <iostream>

using namespace std;

int multiplu(int a[], int n, int k) {
    int c = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] % k == 0 && a[i] % 10 == k)
            ++c;
    return c;
}

int main()
{
    int n, a[100], k;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> k;
    cout << multiplu(a, n, k);
    return 0;
}
