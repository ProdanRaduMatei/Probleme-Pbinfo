#include <iostream>

using namespace std;

int main()
{
    int l;
    cin >> l;
    for (int i = l + 1; i <= 12; ++i) {
        switch(i) {
            case 1:
                cout << "Ianuarie";
                break;
            case 2:
                cout << "Februarie";
                break;
            case 3:
                cout << "Martie";
                break;
            case 4:
                cout << "Aprilie";
                break;
            case 5:
                cout << "Mai";
                break;
            case 6:
                cout << "Iunie";
                break;
            case 7:
                cout << "Iulie";
                break;
            case 8:
                cout << "August";
                break;
            case 9:
                cout << "Septembrie";
                break;
            case 10:
                cout << "Octombrie";
                break;
            case 11:
                cout << "Noiembrie";
                break;
            case 12:
                cout << "Decembrie";
                break;
        }
        cout << endl;
    }
    return 0;
}
