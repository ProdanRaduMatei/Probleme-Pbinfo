#include <iostream>
#include <cstring>

using namespace std;

struct angajat{
    char nume[30], prenume[30], functie[30], nrtel[11], email[30];
    int sal, varsta;
}A[80];

int main()
{
    int n, p;
    char c;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> A[i].prenume >> A[i].nume >> A[i].sal >> A[i].varsta >> A[i].functie >> A[i].nrtel >> A[i].email;
    cin >> p >> c;
    switch (p) {
        case 1:
            for (int i = 1; i < n; ++i)
                for (int j = i + 1; j <= n; ++j)
                    if (stricmp(A[i].prenume, A[j].prenume) > 0)
                        swap(A[i], A[j]);
        break;
        case 2:
            for (int i = 1; i < n; ++i)
                for (int j = i + 1; j <= n; ++j)
                    if (stricmp(A[i].nume, A[j].nume) > 0)
                        swap(A[i], A[j]);
        break;
        case 3:
            for (int i = 1; i < n; ++i)
                for (int j = i + 1; j <= n; ++j)
                    if (A[i].sal > A[j].sal)
                        swap(A[i], A[j]);
        break;
        case 4:
            for (int i = 1; i < n; ++i)
                for (int j = i + 1; j <= n; ++j)
                    if (A[i].varsta > A[j].varsta)
                        swap(A[i], A[j]);
        break;
        case 5:
            for (int i = 1; i < n; ++i)
                for (int j = i + 1; j <= n; ++j)
                    if (stricmp(A[i].functie, A[j].functie) > 0)
                        swap(A[i], A[j]);
        break;
        case 6:
            for (int i = 1; i < n; ++i)
                for (int j = i + 1; j <= n; ++j)
                    if (stricmp(A[i].nrtel, A[j].nrtel) > 0)
                        swap(A[i], A[j]);
        break;
        case 7:
            for (int i = 1; i < n; ++i)
                for (int j = i + 1; j <= n; ++j)
                    if (stricmp(A[i].email, A[j].email) > 0)
                        swap(A[i], A[j]);
        break;
    }
    if (c == '+')
        for (int i = 1; i <= n; ++i)
            cout << A[i].prenume << " " << A[i].nume << " " << A[i].sal << " " << A[i].varsta << " " << A[i].functie << " " << A[i].nrtel << " " << A[i].email << endl;
    else
        for (int i = n; i >= n; ++i)
            cout << A[i].prenume << " " << A[i].nume << " " << A[i].sal << " " << A[i].varsta << " " << A[i].functie << " " << A[i].nrtel << " " << A[i].email << endl;
    return 0;
}
