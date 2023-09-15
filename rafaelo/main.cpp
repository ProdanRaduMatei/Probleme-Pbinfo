#include <iostream>

using namespace std;

int main()
{
    int S, N, p, nrmag, nmaxc, i, nc;
    cin >> S >> N;
    cin >> p;
    nrmag = 1;
    nmaxc = S / p;
    for (int i = 2; i <= N; ++i) {
        cin >> p;
        nc = S / p;
        if (nc > nmaxc) {
            nmaxc = nc;
            nrmag = i;
        }
    }
    cout << nmaxc << " " << nrmag;
    return 0;
}
