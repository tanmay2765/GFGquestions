class Solution {
  public:
    int rec(int n,vector<int> &dp){
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int ans=0;
        ans=rec(n-1,dp);
        ans+=rec(n-2,dp);
        return dp[n]=ans;
    }
    int numberOfWays(int n) {
        vector<int> dp(n+1,-1);
        return rec(n,dp);
    }
};