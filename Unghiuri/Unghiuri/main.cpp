#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.14159265359

int a, b, c;
float ma, mb, mc;

int main()
{
    std::cin >> a >> b >> c;
    float p = (a + b + c) / 2.0;
    float A = sqrt(p * (p - a) * (p - b) * (p - c));
    float R = (1.0 * a * b * c) / (4.0 * A);
    ma = asin(b / (2.0 * R)) * 180.0/ PI;
    ma = (int)(ma * 100) / 100.0;
    mb = asin(c / (2.0 * R)) * 180.0/ PI;
    mb = (int)(mb * 100) / 100.0;
    mc = asin(a / (2.0 * R)) * 180.0/ PI;
    mc = (int)(mc * 100) / 100.0;
    if(ma > 0 && mb > 0 && mc > 0)
        std::cout << std::fixed << std::setprecision(2) << ma << " " << mb << " " << mc;
    else std::cout << "Imposibil";

    return 0;
}