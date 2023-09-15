#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    const double PI = 3.141592658979323846;
    double r, a, c;
    cin >> r;
    a = PI * r * r;
    c = 2 * PI * r;
    cout << setprecision(15) << a << " " << c;
    return 0;
}
