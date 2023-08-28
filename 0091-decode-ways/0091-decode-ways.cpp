class Solution {
private:
    int help(string &s,int i,vector<int> &dp){
        if(i>=s.size())return 1;
        int ch=s[i]-48;
        if(ch==0)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=help(s,i+1,dp);
        if(i<s.size()-1){
            int ch1=s[i+1]-48;
            int num=ch*10+ch1;
            if(num<27)ans+=help(s,i+2,dp);
        }
        return dp[i]=ans;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return help(s,0,dp);
    }
};