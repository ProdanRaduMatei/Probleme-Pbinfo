#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    double a,b,c,d,x1,x2;
    cin >> a >> b >> c;
    d = double(b * b - 4 * a * c);
    if (d > 0) {
        x1 = double(((1 - 2) * b + sqrt(d)) / (2 * a));
        x2 = double(((1 - 2) * b - sqrt(d)) / (2 * a));
        cout << fixed << setprecision(2) << x1 << " " << x2;
    }
    else
        if (d == 0) {
            x1 = double(((1 - 2) * b) / (2 * a));
            cout << "Radacina dubla " << fixed << setprecision(2) << x1;
        }
        else
            cout << "Nu are solutii reale";
    return 0;
}
