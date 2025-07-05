#include <iostream>
#include <fstream>

using namespace std;

ifstream f("canguri.in");
ofstream g("canguri.out");

short n1,s1,n2,s2,n3,s3,nr;

int main() {
    f >> n1 >> s1 >> n2 >> s2 >> n3 >> s3;
    if (s1>s2 && s1>s3) {
        g << n1 << "\n";
        nr=800/s1;
        if (800%s1) ++nr;
        g << nr;
    }
    if (s2>s1 && s2>s3) {
        g << n2 << "\n";
        nr=800/s2;
        if (800%s2) ++nr;
        g << nr;
    }
    if (s3>s2 && s3>s1) {
        g << n3 << "\n";
        nr=800/s3;
        if (800%s3) ++nr;
        g << nr;
    }
    return 0;
}
