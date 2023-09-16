#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int v[n], i, j;
    for (i = 0; i < n; ++i)
        cin >> v[i];
    if (n % 2 == 1) {
        i = n / 2;
        j = n / 2 + 1;
        while (j < n) {
            cout << v[i] << ' ' << v[j] << ' ';
            i--; 
            j++;
        }
        cout << v[0];
    }
    else if (n % 2 == 0) {
        i = n / 2;
        j = n / 2 - 1;
        while (j >= 0) {
            cout << v[i] << ' ' << v[j] << ' ';
            i++;
            j--;
        }
    }
    return 0;
}