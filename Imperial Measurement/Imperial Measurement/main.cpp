#include <iostream>

using namespace std;

int main() {
    long double D;
    cin >> D;
    string A, Gunoi, B;
    cin >> A >> Gunoi >> B;
    if (A == "th" || A == "thou")
        goto end1;
    D *= 1000;
    if (A == "in" || A == "inch")
        goto end1;
    D *= 12;
    if (A == "ft" || A == "foot")
        goto end1;
    D *= 3;
    if (A == "yd" || A == "yard")
        goto end1;
    D *= 22;
    if (A == "ch" || A == "chain")
        goto end1;
    D *= 10;
    if (A == "fur" || A == "furlong")
        goto end1;
    D *= 8;
    if (A == "mi" || A == "mile")
        goto end1;
    D *= 3;
    if (A == "lea" || A == "league")
        goto end1;
    end1:
    if (B == "th" || B == "thou")
        goto end2;
    D /= 1000;
    if (B == "in" || B == "inch")
        goto end2;
    D /= 12;
    if (B == "ft" || B == "foot")
        goto end2;
    D /= 3;
    if (B == "yd" || B == "yard")
        goto end2;
    D /= 22;
    if (B == "ch" || B == "chain")
        goto end2;
    D /= 10;
    if (B == "fur" || B == "furlong")
        goto end2;
    D /= 8;
    if (B == "mi" || B == "mile")
        goto end2;
    D /= 3;
    if (B == "lea" || B == "league")
        goto end2;
    end2:
    cout << fixed;
    cout.precision(13);
    cout << D;
    return 0;
}
