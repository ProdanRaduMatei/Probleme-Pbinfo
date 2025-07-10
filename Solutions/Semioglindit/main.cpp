#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string linie;
    getline(cin, linie);
    stringstream ss(linie);
    string cuvant;
    string rezultat;
    bool exista = false;
    while (ss >> cuvant)
    {
        int len = cuvant.length();
        if (len % 2 == 0)
        {
            exista = true;
            int k = len / 2;
            string semioglindit = cuvant.substr(k) + cuvant.substr(0, k);
            rezultat += semioglindit + " ";
        }
        else
            rezultat += cuvant + " ";
    }
    if (exista)
        cout << rezultat.substr(0, rezultat.size() - 1) << '\n';
    else
        cout << "nu exista\n";
    return 0;
}