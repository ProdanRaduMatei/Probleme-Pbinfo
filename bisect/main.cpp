#include <iostream>

using namespace std;

int main()
{
    int an;
    cout <<"Va rog sa introduceti anul dorit: ";
    cin >>an;
    if (an%4==0)
    {
        cout <<"Anul introdus de catre dumneavoastra este bisect.";
    }
    else
    {
        cout <<"Anul introdus de catre dumneavoastra nu este bisect.";
    }
    return 0;
}
