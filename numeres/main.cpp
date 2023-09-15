#include <iostream>

using namespace std;

int main() {
    int n,s,a,b=1,cnt=0;
    cin >> n >> s;
    for (int i=1; i<=n; ++i)
        b=b*10;
    a=b/10;
    for (int i=a; i<b; ++i) {
        int num=i, suma=0;
        while (num) {
        suma+=num%10;
        num/=10;
        }
        if (suma==s) {
            cout << i << " ";
            ++cnt;
        }
    }
    if (cnt!=0)
        cout << "\n" << cnt;
    else
        cout << cnt;
    return 0;
}
