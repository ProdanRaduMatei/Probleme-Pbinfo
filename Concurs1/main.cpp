#include <iostream>

using namespace std;

int main()
{
    int a, b, v;
    cin >> a >> b >> v;
    if (v >= a && v <= b)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
