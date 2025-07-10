#include <bits/stdc++.h>
using namespace std;
int x = 1 , zi , luna , an , luni[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int bisect(int an) {
    return (an % 400) == 0 || (an % 4 == 0 && an % 100 != 0);
}
int main() {
    cin >> zi >> luna >> an;
    for(int a = 1900 ; a < an ; a++) {
        if(bisect(a))
            x += 366;
            else x += 365;
    }
    for(int l = 1 ; l < luna ; l++) {
        if(bisect(an) && l == 2)
            x += 29;
        else
            x += luni[l];
    }
    x = (x + zi - 1) % 7;
    if(x == 0)
        cout << "Duminica";
    else if (x == 1)
        cout << "Luni";
    else if (x == 2)
        cout << "Marti";
    else if (x == 3)
        cout << "Miercuri";
    else if (x == 4)
        cout << "Joi";
    else if (x == 5)
        cout << "Vineri";
    else if (x == 6)
        cout << "Sambata";
    return 0;
}
