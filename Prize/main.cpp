#include<iostream>
#include<fstream>
using namespace std;
int main()
{
ifstream in("prize.in");
ofstream out("prize.out");
int n;
int tmp;
in>>n;
int s=0;
for(int i=0;i<n;i++)
{
in>>tmp;
s=s+(tmp-1);
}
s=s+1;
out<<s;
}
