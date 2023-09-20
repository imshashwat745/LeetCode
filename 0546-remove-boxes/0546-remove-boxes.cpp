class Solution {
private:
    int help(int streak,int left,int right,vector<int>& arr,vector<vector<vector<int>>> &dp){
        if(left>right)return 0;
        if(left>right)return (streak+1)*(streak+1);
        if(dp[streak][left][right]!=-1)return dp[streak][left][right];
        //Option 1 break the streak here
        int ans=(streak+1)*(streak+1)+help(0,left+1,right,arr,dp);
        for(int i=left+1;i<=right;++i){
            if(arr[left]==arr[i]){
                // same elemnt ki streak chalana chah rahe ham
                ans=max(ans,help(0,left+1,i-1,arr,dp)+help(streak+1,i,right,arr,dp));
            }
        }
        return dp[streak][left][right]=ans;
    }
public:
    int removeBoxes(vector<int>& arr) {
        vector<vector<vector<int>>> dp(arr.size()+1,vector<vector<int>>(arr.size()+1,vector<int>(arr.size()+1,-1)));
        return help(0,0,arr.size()-1,arr,dp);
    }
};