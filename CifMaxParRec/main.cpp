#include <iostream>

using namespace std;

int cifminpar(int n) {
    if (n < 10) {
        if (n % 2 == 0)
            return n;
        return -1;
    }
    else {
        int cm = -1;
        while (n) {
            if (n % 2 == 0 && n % 10 > cm)
                cm = n % 10;
            n = n / 10;
        }
        return cm;
    }

}

int main()
{
    int n;
    cin >> n;
    cout << cifminpar(n);
    return 0;
}
