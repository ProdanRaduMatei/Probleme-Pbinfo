#include <iostream>

using namespace std;

int prim(int x){
    int d = 2, cnt = 0;
    while (x > 1) {
        int p = 0;
        while (x % d == 0) {
            p++;
            x /= d;
        }
        if (p)
            cnt += d;
        d++;
        if (d * d > x)
            d = x;
    }
    return cnt;
}
int main(){
    int x, y;
    cin >> x >> y;
    if (prim(x) > prim(y))
        cout << x;
    else if (prim(x) < prim(y))
        cout << y;
    else
        cout << min(x, y);
    return 0;
}
