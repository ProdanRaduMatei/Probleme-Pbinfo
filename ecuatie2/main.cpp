#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

ifstream fin("ecuatie2.in");
ofstream fout("ecuatie2.out");

int TipEcuatie(char s[21], int poz) {
    if (s[poz - 1] == '+' && s[poz] == 'x')
        return 1;
    if (s[poz + 1] == '+' && s[poz] == 'x')
        return 2;
    if (s[poz - 1] == '-' && s[poz] == 'x')
        return 3;
    if (s[poz + 1] == '-' && s[poz] == 'x')
        return 4;
    if (s[poz - 1] == '*' && s[poz] == 'x')
        return 5;
    if (s[poz + 1] == '*' && s[poz] == 'x')
        return 6;
    if (s[poz - 1] == ':' && s[poz] == 'x')
        return 7;
    if (s[poz + 1] == ':' && s[poz] == 'x')
        return 8;
}

int main()
{
    char s[21];
    int tip, poz;
    long long a = 0, b = 0, sol;
    bool ok = 0;
    fin.getline(s, 21);
    for (int i = 0; s[i]; ++i) {
        if (s[i] >= '0' && s[i] <= '9' && ok == 0)
            a = a * 10 + s[i] - '0';
        else if (a)
            ok = 1;
        if (s[i] >= '0' && s[i] <= '9' && ok == 1)
            b = b * 10 + s[i] - '0';
        if (s[i] == 'x')
            poz = i;
    }
    tip = TipEcuatie(s, poz);
    switch(tip) {
        case 1: fout << "1" << "\n" << b - a;
            break;
        case 2: fout << "2" << "\n" << b - a;
            break;
        case 3: fout << "3" << "\n" << a - b;
            break;
        case 4: fout << "4" << "\n" << a + b;
            break;
        case 5: fout << "5" << "\n" << b / a;
            break;
        case 6: fout << "6" << "\n" << b / a;
            break;
        case 7: fout << "7" << "\n" << a / b;
            break;
        case 8: fout << "8" << "\n" << a * b;
            break;
    }
    return 0;
}
