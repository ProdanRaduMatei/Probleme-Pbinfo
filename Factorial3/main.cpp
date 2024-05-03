#include <fstream>

using namespace std;

int sumExpFactPrim(int n)
{
    int suma = 0;
    for (int d = 2; d * d <= n; ++d)
        while (n % d == 0)
        {
            n /= d;
            suma++;
        }
    if (n != 1)
        suma++;
    return suma;
}

int main()
{
    ifstream fin("factorial3.in");
    ofstream fout("factorial3.out");
    int n, suma = 0;
    fin >> n;
    for (int i = 2; i <= n; ++i)
        suma += sumExpFactPrim(i);
    fout << suma;
    return 0;
}