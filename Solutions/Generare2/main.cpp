#include <iostream>

using namespace std;

const int MAX_N = 10000;

int n, x, y;
bool apartine[1 + MAX_N] ;

void genereaza(int b) {
    if (b <= n && !apartine[b]) {
        apartine[b] = true;
        genereaza(b + x);
        genereaza(b + y);
    }
}

int main() {
    int a;
    cin >> n >> a >> x >> y;
    genereaza(a);
    for (int i = 0; i <= n; i++)
        if (apartine[i])
            cout << i << ' ';
    return 0;
}
