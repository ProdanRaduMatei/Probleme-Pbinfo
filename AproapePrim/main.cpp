#include <iostream>

using namespace std;

int a_prim(int n) {
    int aprim = 0;
    int d = 2, k, a, b;
    while(!aprim && d * d <= n) {
        if(n % d == 0) {
            a = d;
            b = n / d;
            int prim = 1;
            if(a < 2)
                prim = 0;
            if(a > 2 && a % 2 == 0)
                prim = 0;
            for(k = 3; k * k <= a ; k = k + 2)
                if(a % k == 0)
                    prim = 0;
            if(prim) {
                if(b < 2)
                    prim = 0;
                if(b > 2 && b % 2 == 0)
                    prim = 0;
                for(k = 3; k * k <= b ; k += 2)
                    if(b % k == 0)
                        prim = 0;
                if(prim)
                    aprim = 1;
            }
        }
        if(d == 2)
            d++;
        else
            d = d + 2;
    }
    return aprim;
}

int main()
{
    long long n;
    cin >> n;
    if (a_prim(n))
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
