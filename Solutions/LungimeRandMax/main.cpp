#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("lungimerandmax.in");
ofstream fout("lungimerandmax.out");

int main()
{
    char s[1000];
    int n;
    fin >> n;
    fin.getline(s, 1000);
    for (int i = 0; i < strlen(s); ++i) {
        if ((i + 1) % 22 == 0) {
            fout << endl;
            --i;
        }
        else
            fout << s[i];
    }
    return 0;
}
