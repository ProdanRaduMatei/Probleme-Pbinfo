#include <iostream>
#include <fstream>

using namespace std;

ifstream fin1("file1.txt");
ifstream fin2("file2.txt");
ofstream fout("file.out");

void interclasare()
{
    int a, b, ok;
    fin1 >> a;
    fin2 >> b;
    if (a < b)
    {
        fout << a << " ";
        ok = 1;
    }
    else
    {
        fout << b << " ";
        ok = 0;
    }
    while (!fin1.eof() && !fin2.eof())
    {
        if (ok)
            fin1 >> a;
        else
            fin2 >> b;
        if (a < b)
        {
            fout << a << " ";
            ok = 1;
        }
        else
        {
            fout << b << " ";
            ok = 0;
        }
    }
    while (fin1 >> a)
    {
        fin1 >> a;
        fout << a << " ";
    }
    while (fin2 >> b)
    {
        fin2 >> b;
        fout << b << " ";
    }
    fin1.close();
    fin2.close();
    fout.close();
}

int main() {
    interclasare();
    
    return 0;
}
