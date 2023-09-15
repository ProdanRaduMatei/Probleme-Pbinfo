#include <iostream>

using namespace std;

int main()
{
    int a,b,suma,diferenta,produs,cat;
    cout <<"Va rog sa introduceti doua numere pentru a se calcula suma, diferenta, produsul si catul lor:";
    cin >>a>>b;
    suma=a+b;
    diferenta=a-b;
    produs=a*b;
    cat=a/b;
    cout <<"Suma celor doua numere introduse este: "<<suma<<"."<<endl;
    cout <<"Diferenta celor doua numere introduse este: "<<diferenta<<"."<<endl;
    cout <<"Produsul celor doua numere introduse este: "<<produs<<"."<<endl;
    cout <<"Catul celor doua numere introduse este: "<<cat<<"."<<endl;
    return 0;
}
