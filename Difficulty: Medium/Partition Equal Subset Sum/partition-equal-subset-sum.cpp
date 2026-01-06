class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int s=0,n=arr.size();
        for(int a:arr) s+=a;
        if(s%2!=0) return false;
        s/=2;
        vector<vector<bool>>dp(n+1,vector<bool>(s+1,false));
        for(int i=0;i<=n;i++) dp[i][0]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=s;j++){
                if(j<arr[i-1]) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
        return dp[n][s];
    }
};