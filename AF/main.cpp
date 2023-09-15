#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream f("af.in");
    ofstream g("af.out");
    char semn, egal;
    long long int a, b, c, i, n, ok;
    f >> n;
    for (i=1; i<=n; ++i) {
        ok=0;
        f >> a >> semn >> b >> egal >> c;
        if (ok==0 && semn=='+' && a+b==c)
            ok=1;
        if (ok==0 && semn=='-' && a-b==c)
            ok=1;
        if (ok==0 && semn=='x' && a*b==c)
            ok=1;
        if (ok==0 && semn==':') {
            if (b==0)
                ok=0;
            else if (a/b==c)
                ok=1;
        }
        if (ok)
            g << "Adevarat" << "\n";
        else
            g << "Fals" << "\n";
    }
    return 0;
}
