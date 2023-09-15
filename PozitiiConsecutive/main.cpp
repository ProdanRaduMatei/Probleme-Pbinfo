#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("pozitiiconsecutive.in");
ofstream fout("pozitiiconsecutive.out");

int main()
{
    int x, y, z;
    fin >> x >> y;
    fout << y << " " << x << " ";
    if (x != 0) {
        do {
            z = 2 * x - y + 2;
            fout << z << " ";
            y = x;
            x = z;
        } while (z > 0);
    }
    return 0;
}
