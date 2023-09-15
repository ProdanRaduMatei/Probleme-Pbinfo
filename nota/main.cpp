#include <iostream>

using namespace std;

int main()
{
    int nota;
    cout <<"Va rog sa introduceti nota copilului: ";
    cin >>nota;
    if (nota>=5)
    {
        cout <<"Copilul este promovat.";
    }
    else
    {
        cout <<"Copilul este corigent.";
    }
    return 0;
}
