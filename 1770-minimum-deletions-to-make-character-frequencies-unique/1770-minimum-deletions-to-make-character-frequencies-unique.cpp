class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        int ans=0;
        for(auto ch:s)++freq[ch-97];
        unordered_map<int,int> mp;
        for(auto v:freq)++mp[v];
        for(auto x:freq){
            int k=x;
            int v=mp[k];
            if(v>1)--mp[k];
            else continue;
            while(k>0&&mp[k]>0){
                ++ans;
                --k;
            }
            if(k>0)++mp[k];
        }
        return ans;
    }
};