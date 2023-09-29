class Solution {
private:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]&&a[1]==b[1])return a[2]<b[2];
        if(a[0]==b[0])return a[1]<b[1];
        return a[0]<b[0];
    }
    int help(vector<vector<int>> &arr,int i,int prev,vector<vector<int>> &dp){
        if(i==arr.size())return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int w=0,l=0;
        if(prev!=-1){
            w=arr[prev][0];
            l=arr[prev][1];
        }
        int ans=help(arr,i+1,prev,dp);
        if(prev==-1||(arr[i][0]>=w&&arr[i][1]>=l)||(arr[i][0]>=l&&arr[i][1]>=w)){
            if(prev==-1||arr[i][2]>=arr[prev][2])
                ans=max(ans,arr[i][2]+help(arr,i+1,i,dp));
        }
        return dp[i][prev+1]=ans;
    }
public:
    int maxHeight(vector<vector<int>>& arr) {
        for(int i=0;i<arr.size();++i){
            sort(arr[i].begin(),arr[i].end());
        }
        sort(arr.begin(),arr.end(),cmp);
        vector<vector<int>> dp(arr.size(),vector<int>(arr.size()+1,-1));
        return help(arr,0,-1,dp);
    }
};