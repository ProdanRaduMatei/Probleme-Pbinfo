int permutare(int a[] , int n) {
    int cnt=0;
    int cn=0;
    int f[100000]={0};
    for(int i = 0 ; i < n ; ++i)
        f[a[i]]++;
    for(int i = 1 ; i <= n ; ++i) {
        if(f[i]==1)
        cn++;
    }
    for(int i = 0 ; i < n ; ++i) {
        if(a[i]==i+1)
            cnt++;
        if(a[i]>n)
            cn=0;
    }
    if(cnt==0 && cn==n)
        return 1;
    else
        return 0;
}
