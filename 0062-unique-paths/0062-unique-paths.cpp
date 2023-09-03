class Solution {
private:
    int help(int m,int n,int i,int j,vector<vector<int>> &dp){
        if(i==m-1&&j==n-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(i<m-1)ans+=help(m,n,i+1,j,dp);
        if(j<n-1)ans+=help(m,n,i,j+1,dp);
        return dp[i][j]=ans;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return help(m,n,0,0,dp);
    }
};