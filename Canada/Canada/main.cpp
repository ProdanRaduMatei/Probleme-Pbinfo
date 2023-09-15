#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    
    if (a+b > 100)
        std::cout << a+b-100;
    else
        std::cout << 0;
    
    return 0;
}