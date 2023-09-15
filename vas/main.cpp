#include <iostream>

using namespace std;

int x,t,y,T;
float v;

int main() {
    cin >> x >> t >> y;
    v=1.0*x;
    while (v>y) {
        T+=t;
        v=v*3/4;
    }
    cout << T;
    return 0;
}
