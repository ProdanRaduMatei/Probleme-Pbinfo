#include <fstream>

using namespace std;

ifstream fin("cod3.in");
ofstream fout("cod3.out");

int n, fr[100] = {0};
int main() {
    fin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        fin >> x;
        fr[x]++;
    }
    for (int i = 0; i <= 99; i++)
        if (fr[i] % 2)
            fout << i;
}