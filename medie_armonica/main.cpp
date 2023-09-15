#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, i;
    double suma, arit, a[10001];
    suma = 0.00;
    arit = 0.00;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 1; i <= n; i++)
        suma += 1 / a[i];
    arit = n / suma;
    cout<<fixed <<setprecision(2)<<arit;
    return 0;
}
