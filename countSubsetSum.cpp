int subsetSum(vector<int> v, int sum) {
    vector<vector<int>> dp(v.size()+1, vector<int>(sum+1, 0));
    
    dp[0][0]=1;
    
    for(int i=1;i<=v.size();i++) {
        for(int j=0;j<=sum;j++) {
            if(j>=v[i-1]) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-v[i-1]];
            } else dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[v.size()][sum];
}
