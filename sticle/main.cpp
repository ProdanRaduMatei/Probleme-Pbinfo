#include <iostream>

using namespace std;

int main()
{
    int x, y, sticle;
    cout <<"Va rog sa introduceti numarul de litri al unei sticle: ";
    cin >>x;
    cout <<"va rog sa mai introductei nmarul de litri al vasului de depozitare: ";
    cin >>y;
    sticle=y/x+y%x;
    if (sticle<=20)
    {
        cout <<"Pentru a umple in totalitate vasul de depozitare este nevoie sa se desfaca: "<<sticle<<" sticle.";
    }
    else
    {
        cout <<"Pentru a umple in totalitate vasul de depozitare este nevoie sa se desfaca: "<<sticle<<" de sticle.";
    }
    return 0;
}
