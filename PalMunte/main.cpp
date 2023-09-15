#include <iostream>
using namespace std;
int main()
{
for(int i=1;i<=5;i++)
    for(int j=i+1;j<=6;j++)
        for(int k=j+1;k<=7;k++)
            for(int l=k+1;l<=8;l++)
                for(int m=l+1;m<=9;m++)
                    cout<<i<<j<<k<<l<<m<<l<<k<<j<<i<<" "<<endl;
    return 0;
}
