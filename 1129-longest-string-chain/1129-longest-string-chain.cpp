class Solution {
private:
    static bool cmp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    bool isPossible(string &s1,string &s2){
        if(s2.size()-s1.size()!=1)return false;
        int i=0,j=0;
        bool found=false;
        while(i<s1.size()&&j<s2.size()){
            if(s1[i]==s2[j]){
                ++i;
                ++j;
                continue;
            }
            if(!found){
                ++j;
                found=true;
                continue;
            }
            return false;
        }
        if(j==s2.size()-1)return !found;
        // return i==s1.size()&&j==s2.size();
        return true;
    }
    int help(vector<string> &arr,int i, int prev,vector<vector<int>> &dp){
        if(i == arr.size())return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        if(prev==-1){
            dp[i][prev+1]=max(1+help(arr,i+1,i,dp),help(arr,i+1,prev,dp));
            return dp[i][prev+1];
        }
        // vector<vector<int>> dp2(arr[prev].size(),vector<int>(arr[i].size(),-1));
        if(arr[i].size()==arr[prev].size()+1
        && isPossible(arr[prev],arr[i])){
            dp[i][prev+1]=max(1+help(arr,i+1,i,dp),help(arr,i+1,prev,dp));
            return dp[i][prev+1];
        }
        dp[i][prev+1]=help(arr,i+1,prev,dp);
        return dp[i][prev+1];
    }
public:
    int longestStrChain(vector<string>& arr) {
        vector<vector<int>> dp(arr.size(),vector<int>(arr.size()+1,-1));
        sort(arr.begin(),arr.end(),cmp);
        return help(arr,0,-1,dp);
    }
};