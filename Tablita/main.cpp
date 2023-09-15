#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("tablita.in");
ofstream fout("tablita.out");
double n;
int main()
{
    fin >> n;
    fout << ceil((-1+sqrt(1+8*n))/2);
    return 0;
}
