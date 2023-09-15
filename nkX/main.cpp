#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    if(2 * k < n)
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++)
                if(((i+k>=j)&&(j+k>=i))||((k+n+1>=i+j)&&(n-k<i+j)))
                    cout << 1 << ' ';
                else
                    cout << 2 << ' ';
            cout << '\n';
        }
    else
        cout << "Dublul lui k nu este mai mic decat n.\n";
    return 0;
}
