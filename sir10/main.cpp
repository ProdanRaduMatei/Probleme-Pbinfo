#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sir10.in");
ofstream fout("sir10.out");

int n;
long long int rez;

int main() {
    fin >> n;
    for (int l = 3; l <= n; ++l) {
        int r = 1;
        while (n - l * r + r >= 1) {
            rez += n - l * r + r;
            ++r;
        }
    }
    fout << rez;
    return 0;
}
