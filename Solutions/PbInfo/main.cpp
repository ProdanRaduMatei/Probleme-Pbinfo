#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("pbinfo.in");
ofstream fout("pbinfo.out");
char s[100], k[100];
int n;

int main()
{
    fin >> s >> n;
    for (; n; --n) {
        fin >> k;
        if (strstr(s, k) != NULL or strstr(s, "virus") != NULL) {
            fout << "DA";
            return 0;
        }
    }
    fout << "NU";
    return 0;
}
