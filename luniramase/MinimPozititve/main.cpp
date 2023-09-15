#include <iostream>

using namespace std;

int main()
{
    int a, m = 1000000;
    do{
        cin >> a;
        if (m > a && a > 0)
            m = a;
    }while (a!=0);
    cout << m;
    return 0;
}
