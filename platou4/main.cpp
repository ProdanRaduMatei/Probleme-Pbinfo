#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("platou4.in");
ofstream fout("platou4.out");

int main()
{
    int x, n = 0, p1 = 0, p2;
    while (fin >> x) {
        ++n;
        if (x % 2 == 0) {
            if (!p1)
                p1 = n;
            else
                p2 = n;
        }
    }
    fout << p2 - p1 + 1;
    return 0;
}
