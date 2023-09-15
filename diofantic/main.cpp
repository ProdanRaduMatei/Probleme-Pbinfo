int diofantic(int n, int s[50001], int a,long long b,int c)
{
int k=0;int i=1; int j=n;
while(i<=n && j>0)
{
if(a*s[i]*s[i]+b*s[j]*s[j]==c )
{
k++;
i++;
}
if(a*s[i]*s[i]+b*s[j]*s[j]<c)
i++;
if(a*s[i]*s[i]+b*s[j]*s[j]>c)
j--;
}
return k;
}
