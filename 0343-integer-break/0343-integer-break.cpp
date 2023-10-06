class Solution {
private:
    int help(int n,int s,vector<int> &dp){
        if(n==0)return 1;
        if(dp[n]!=-1)return dp[n];
        int ans=0,limit=n;
        if(n==s)--limit;
        for(int i=1;i<=limit;++i)ans=max(ans,i*help(n-i,s,dp));
        return dp[n]=ans;
    }
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return help(n,n,dp);
    }
};