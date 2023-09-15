#include <iostream>

using namespace std;

int Kth(int a[], int n, int x, int k)
{
    int num = 0;
    if (k==0)
        return -1;
    for (int i=0; i<n; i++) {
        if (a[i]==x)
            num++;
        if (num==k)
            return i;
    }
    return -1;
}

int main()
{
    int a[1001], n, k, x;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> x >> k;
    cout << Kth(a, n, x, k);
    return 0;
}
