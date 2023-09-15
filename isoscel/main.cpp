#include <iostream>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    if (a+b>c && a+c>b && b+c>a && a!=0 && b !=0 && c != 0) {
        if ((a==b && b!=c) || (b==c && c!=a) || (c==a && a!=b))
            cout << "Formeaza triunghi isoscel";
        else
            cout << "Nu formeaza triunghi isoscel";
    }
    else
        cout << "Nu formeaza triunghi";
    return 0;
}
