#include <iostream>

using namespace std;

int a, b, x, y, c;

int main() {
    cin >> a >> b;
    c=(a+b)*b;
    for (x=1; x<=c; ++x) {
        for (y=c; y>0; --y) {
            if (x+y<x*y) {
                if (a*x*y==b*(x+y) && x<=y)
                cout << x << " " << y << "\n";
                if (x>y) {break;}
            }
        }
    }
    return 0;
}
