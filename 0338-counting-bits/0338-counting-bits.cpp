class Solution {
public:
    int help(int n,vector<int> &dp){
        if(n==0)return dp[n]=0;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=(n&1)+help(n>>1,dp);
    }
    vector<int> countBits(int n) {
        vector<int> dp(n+1,-1);
        int i;
        for(i=0;i<=n;++i)help(i,dp);
        return dp;
    }
};