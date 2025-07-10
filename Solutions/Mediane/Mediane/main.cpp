#include <iostream>
#include <cmath>
#include <iomanip>

int a, b, c;
float m1, m2, m3;

int main()
{
    std::cin >> a >> b >> c;
    m1 = sqrt((2.0 * (a * a + c * c) - b * b) / 4.0);
    m2 = sqrt((2.0 * (b * b + c * c) - a * a) / 4.0);
    m3 = sqrt((2.0 * (a * a + b * b) - c * c) / 4.0);
    m1 = (int)(m1 * 100) / 100.0;
    m2 = (int)(m2 * 100) / 100.0;
    m3 = (int)(m3 * 100) / 100.0;
    if(m1 > 0 && m2 > 0 && m3 > 0)
        std::cout << std::fixed << std::setprecision(2) << m2 << " " << m1 << " " << m3;
    else std::cout << "Imposibil";

    return 0;
}