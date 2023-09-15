int nr_sa(int a[100][100], int n, int m) {
    int i, j, c, nr = 0, maxx, minn, k, p, min1, max1;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            minn = 2147148001;
            maxx =- minn;
            min1 = minn;
            max1 = maxx;
            for(k = 0; k < m; k++) {
                if(a[i][k] > maxx)
                    maxx = a[i][k];
                if(a[i][k] < minn)
                    minn = a[i][k];
            }
            for(k = 0; k < n; k++) {
                if(a[k][j] > max1)
                    max1 = a[k][j];
                if(a[k][j] < min1)
                    min1 = a[k][j];
            }
            if(a[i][j] == maxx && a[i][j] == min1)
                nr++;
            else
                if(a[i][j] == max1 && a[i][j] == minn)
                    nr++;
        }
    }
    return nr;
}
