#include <iostream>

using namespace std;

int main()
{
    int L, l, A, P;
    cout <<"Va rog sa introduceti lungimea si latimea curtii dumnavoastra (in metri) , dar numai daca are forma dreptunghiulara, pentru a se calcula aria acesteia si lungimea gardului care o inconjoara: ";
    cin >>L>>l;
    A=L*l;
    P=2*(L+l);
    if ((A<=20)&(P<=20))
    {
        cout <<"Aria curtii este de: "<<A<<" metri patrati."<<endl;
        cout <<"Lungimea gardului care o inconjoara este de: "<<P<<" metri."<<endl;
    }
    if ((A<=20)&(P>20))
    {
        cout <<"Aria curtii este de: "<<A<<" metri patrati."<<endl;
        cout <<"Lungimea gardului care o inconjoara este de: "<<P<<" de metri."<<endl;
    }
    if ((A>20)&(P>20))
    {
        cout <<"Aria curtii este de: "<<A<<" de metri patrati."<<endl;
        cout <<"Lungimea gardului care o inconjoara este de: "<<P<<" de metri."<<endl;
    }
    if ((A>20)&(P<=20))
    {
        cout <<"Aria curtii este de: "<<A<<" de metri patrati."<<endl;
        cout <<"Lungimea gardului care o inconjoara este de: "<<P<<" de metri."<<endl;
    }
    return 0;
}
