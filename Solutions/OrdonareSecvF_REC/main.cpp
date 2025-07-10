#include <iostream>

using namespace std;

void ordonare(int a[], int n, int st, int dr) {
    for (int i = st; i < dr; ++i)
        for (int j = i + 1; j <= dr; ++j)
            if (a[i] > a[j])
                swap(a[i], a[j]);
}

int main()
{
    int n, a[1000], st, dr;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> st >> dr;
    ordonare(a, n, st, dr);
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    return 0;
}
