#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("eratostene1.in");
ofstream fout("eratostene1.out");
int prim(int x){
    if (x < 2)
        return 0;
    if (x == 2)
        return 1;
    if (x % 2 == 0)
        return 0;
    for (int i = 3; i * i <= x; i = i + 2)
        if (x % i == 0)
            return 0;
    return 1;
}
int main() {
    int n, c = 0, x;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> x;
        if (prim(x) == 1)
            ++c;
    }
    fout << c;
}
