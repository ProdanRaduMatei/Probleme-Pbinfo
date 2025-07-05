#include <iostream>
#include <iomanip>
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    double A = (n * l * l * 100 / (4 * tan(M_PI / n)));
    cout << fixed << setprecision(2) << A / 100.0;
    return 0;
}
