#include <iostream>
using namespace std;
int main ()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i * i <= n; i++) {
        if (i * i == n && i % 2 == 0) {
            sum = sum + i;
            cout << i << ' ';
        }
        else if (n % i == 0 && i * i != n) {
            if (i % 2 == 0) {
                sum = sum + i;
                cout << i << ' ';
            }
            if ((n / i) % 2 == 0) {
                sum = sum + n / i;
                cout << n / i << ' ';
            }
        }
    }
    cout << endl << sum;
    return 0;
}
