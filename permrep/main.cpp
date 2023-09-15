#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

ifstream fin("permrep.in");
ofstream fout("permrep.out");

string s;

int main()
{
    fin >> s;
    sort(s.begin(), s.end());
    do{
        fout << s << endl;
    } while(next_permutation(s.begin(), s.end()));
    return 0;
}
