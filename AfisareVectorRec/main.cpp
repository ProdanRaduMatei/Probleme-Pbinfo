#include <iostream>

using namespace std;

void afisvec(int v[], int n) {
    for (int i = 0; i < n; ++i)
        cout << v[i] << " ";
}

int main()
{
    int n, v[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    afisvec(v, n);
    return 0;
}
