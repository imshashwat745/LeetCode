class Solution {
private:
    int help(vector<int> &arr,int t,vector<int> &dp){
        if(t==0)return 1;
        if(t<0)return 0;
        if(dp[t]!=-1)return dp[t];
        int ans=0;
        for(auto i:arr){
            if(i>t)break;
            ans+=help(arr,t-i,dp);
        }
        return dp[t]=ans;
    }
public:
    int combinationSum4(vector<int>& arr, int t) {
        vector<int> dp(t+1,-1);
        sort(arr.begin(),arr.end());
        return help(arr,t,dp);
    }
};