#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    float a, b, c, d, S;
    cin >> a >> b >> c >> d;
    S = (a + b + c + d) / 2.0;
    float A = sqrt((S - a) * (S - b) * (S - c) * (S - d));
    cout << fixed << setprecision(3) << (int)(A * 1000) / 1000.0;

}