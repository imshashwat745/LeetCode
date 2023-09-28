class Solution {
private:
    int help(vector<int> &arr,int i,int first_taken,int n,vector<vector<int>> dp[]){
        if(n==0)return 0;
        if(i>=arr.size()||(i==arr.size()-1&&first_taken==1))return -1e7;
        if(dp[first_taken][i][n]!=-1)return dp[first_taken][i][n];
        return dp[first_taken][i][n]=max(arr[i]+help(arr,i+2,i==0?1:first_taken,n-1,dp),help(arr,i+1,first_taken,n,dp));
    }
public:
    int maxSizeSlices(vector<int>& arr) {
        vector<vector<int>> dp[2];
        dp[0]=vector<vector<int>> (arr.size(),vector<int>(arr.size()/3+1,-1));
        dp[1]=vector<vector<int>> (arr.size(),vector<int>(arr.size()/3+1,-1));
        return help(arr,0,0,arr.size()/3,dp);
    }
};