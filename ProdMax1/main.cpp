#include <iostream>
using namespace std;
int main(){
    int n, x, M = -1000001, Mm = -1000001, m = 1000001, mm = 1000001;
    cin>>n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        if (x > M) {
            Mm = M;
            M = x;
        }
        else if (x > Mm)
            Mm = x;
        if (x < m) {
            mm = m;
            m = x;
        }
        else if (x < mm)
            mm = x;
    }
    if (n > 1)
        cout << max(M * Mm, m * mm);
    else
        cout << M;
    return 0;
}
