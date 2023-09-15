#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("codjoc.in");
ofstream fout("codjoc.out");

int main()
{
    long long n, c = 0, s = 0, p = 1;
    fin >> n;
    while (n) {
        c = c + p * (n % 10);
        s = s + c;
        p = p * 10;
        n = n / 10;
    }
    fout << s;
    return 0;
}
