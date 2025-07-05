#include <iostream>

using namespace std;

int getScore(int sus, int jos) {
    if (jos > sus)
        swap(jos, sus);
    if (sus == 2 && jos == 1)
        return 100000;
    if (sus == jos)
        return sus * 100;
    return sus * 10 + jos;
}

int main() {
    int A, B, C, D;
    while (cin >> A >> B >> C >> D && A != 0 && B != 0) {
        int scor1 = getScore(A, B);
        int scor2 = getScore(C, D);
        if (scor1 == scor2) {
            cout << "Tie." << endl;
            continue;
        }
        if (scor1 > scor2) {
            cout << "Player 1 wins." << endl;
            continue;
        }
        if (scor1 < scor2) {
            cout << "Player 2 wins." << endl;
            continue;
        }
    }
    return 0;
}
