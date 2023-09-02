class Solution {
private:
    int help(string &s,int i,int prev,unordered_set<string> &st,
    vector<vector<int>> &dp){
        if(i==s.size())return i-prev;
        if(dp[i][prev]!=-1)return dp[i][prev];
        string curr=s.substr(prev,i-prev+1);
        if(st.find(curr)!=st.end()){
            return dp[i][prev]=min(help(s,i+1,i+1,st,dp),help(s,i+1,prev,st,dp));
        }
        return dp[i][prev]=min(help(s,i+1,prev,st,dp),
        (i-prev+1+help(s,i+1,i+1,st,dp)));
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st;
        for(auto word:dictionary)st.insert(word);
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
        return help(s,0,0,st,dp);
    }
};