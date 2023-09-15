#include <iostream>

using namespace std;

int n, k, i, m, cif, num;

int main() {
    cin >> n;
    for (i=1; i<=n; ++i) {
        cin >> k;
        num=100; m=3;
        while (m<k) {
            m+=3;
            ++num;
        }
        if (m-k==0)
            cif=num%10;
        if (m-k==1)
            cif=(num/10)%10;
        if (m-k==2)
            cif=num/100;
        cout << cif << " ";
    }
}
