#include <iostream>

using namespace std;

int main()
{
    int a, b, nrSchimb = 0, sus = 1, jos = 0, dreapta = 1, stanga = 0, colt = 0, i, j;
    cin >> a >> b;
    ++a;
    ++b;
    i = b;
    j = 1;
    colt = 0;
    while (!colt) {
        if (sus)
            --i;
        if (dreapta)
            ++j;
        if (jos)
            ++i;
        if (stanga)
            --j;
        if ((i == 1 && j == 1) || (i == 1 && j == a) || (i == b && j == 1) || (i == b && j == a))
            colt = 1;
        else {
            if (i == 1) {
                jos = 1;
                sus = 0;
                ++nrSchimb;
            }
            if (i == b) {
                jos = 0;
                sus = 1;
                ++nrSchimb;
            }
            if (j == 1) {
                dreapta = 1;
                stanga = 0;
                ++nrSchimb;
            }
            if (j == a) {
                dreapta = 0;
                stanga = 1;
                ++nrSchimb;
            }
        }
    }
    cout << nrSchimb;
    return 0;
}
