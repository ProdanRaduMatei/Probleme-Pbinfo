#include <fstream>

using namespace std;

int main()
{
    int n, ultimacutie, nrbomboane;
    long long int totalbomboane;
    ifstream fin("lacom.in");
    ofstream fout("lacom.out");
    fin >> n >> ultimacutie;
    totalbomboane = ultimacutie;
    for (int index = 2; index <= n; ++index)
    {
        fin >> nrbomboane;
        if (nrbomboane > ultimacutie)
        {
            totalbomboane += nrbomboane;
            ultimacutie = nrbomboane;
        }
    }
    fin.close();
    fout << totalbomboane;
    fout.close();
    return 0;
}