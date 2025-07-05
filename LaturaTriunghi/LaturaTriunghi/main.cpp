#include <iostream>
#include <cmath>

using namespace std;

/*
Se dau două laturi ale unui triunghi oarecare și măsura unghiului dintre ele. Aflați lungimea celeilalte laturi.
Programul citește de la tastatură numerele naturale a b u, reprezentând lungimea celor două laturi și măsura unghiului dintre ele.
Programul va afișa pe ecran numărul c reprezentând lungimea celeilalte laturi, cu cel puțin 2 zecimale exacte.
1 ≤ a, b, c ≤ 1000
1 ≤ u ≤ 179
punctajul se acordă dacă diferența dintre rezultatul afișat de program și cel corect este mai mică decât 0.01.
rezultatul va avea cel puțin 2 zecimale exacte
Exemplu:
Intrare

22 29 40
Ieșire

18.64

*/

int main() {
    double a, b, u, c;
    cin >> a >> b >> u;
    c = sqrt(a * a + b * b - 2 * a * b * cos(u * 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067 / 180));
    cout << c;
    return 0;
}
