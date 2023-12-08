#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

void minDif(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    vector<vector<bool>> dp(n + 2, vector<bool>(sum + 1, false));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i-1][j];
            if (arr[i-1] <= j)
                dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
        }
    }

    int dif = INT_MAX;
    for (int j = sum/2; j >= 0; j--) {
        if (dp[n][j] == true) {
            dif = sum - 2*j;
            break;
        }
    }

    cout << dif << endl;
}

int main() {
    int n, v[22];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    minDif(v, n);
    
    return 0;
}