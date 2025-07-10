#include <bits/stdc++.h>

using namespace std;

ifstream fin("limite.in");
ofstream fout("limite.out");

int main()
{
    double x, n;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> x;
        if (x >= -128 && x <= 127)
            fout << "char" << endl;
        else if (x >= 0 && x <= 256)
            fout << "unsigned char" << endl;
        else if (x >= -32768 && x <= 32767)
            fout << "short" << endl;
        else if (x >= 0 && x <= 65535)
            fout << "unsigned short" << endl;
        else if (x >= -2147483648 && x <= 2147483647)
            fout << "int" << endl;
        else if (x >= 0 && x <= 4294967295)
            fout << "unsigned int" << endl;
        else if (x >= -9223372036854775808 && x <= 9223372036854775807)
            fout << "long long" << endl;
        else if (x >= 0 && x <= 18446744073709551615)
            fout << "unsigned long long" << endl;
    }
    return 0;
}
