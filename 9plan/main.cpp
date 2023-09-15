#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("9plan.in");
ofstream fout("9plan.out");

int main()
{
    int n;
    fin >> n;
    if (n % 2 == 0)
        fout << 1;
    else
        fout << 9;
    return 0;
}
