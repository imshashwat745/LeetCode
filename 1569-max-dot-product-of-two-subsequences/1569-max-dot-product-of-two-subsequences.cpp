class Solution {
private:
    int help(vector<int> &a,vector<int> &b,int i,int j,int taken,vector<vector<vector<int>>> &dp){
        if(i==a.size()||j==b.size())return taken==1?0:INT_MIN+1;
        if(dp[i][j][taken]!=INT_MIN)return dp[i][j][taken];
        return dp[i][j][taken]=max(a[i]*b[j]+help(a,b,i+1,j+1,1,dp),max(help(a,b,i+1,j,taken,dp),help(a,b,i,j+1,taken,dp)));
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(2,INT_MIN)));
        return help(nums1,nums2,0,0,0,dp);
    }
};